/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inowak-- <inowak--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 11:45:01 by inowak--          #+#    #+#             */
/*   Updated: 2025/04/17 10:00:13 by inowak--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# pragma once

# include "colors.hpp"
# include "debug.hpp"

# include <map>
# include <algorithm>
# include <iostream>
# include <fstream>
# include <iostream>
# include <cstdlib>
# include <sstream>
# include <limits>
# include <ctime>
# include <cmath>

# define ERROR_FORMAT std::cout << RED << "[ERROR]" << RESET << ": format : ./btc file" << std::endl; return 1
# define ERROR_EXTENSION std::cout << RED << "[ERROR]" << RESET << ": extension : must be in .csv" << std::endl; return 1
# define ERROR_LOAD std::cout << RED << "[ERROR]" << RESET << ": loadDataBase : " << e.what() << std::endl;
# define ERROR_INPUT std::cout << RED << "[ERROR]" << RESET << ": loadInputDataBase : " << e.what() << std::endl;

class BitcoinException : public std::exception {
	private:
		std::string _msg;
	public:
		BitcoinException(const std::string& msg);
		virtual const char* what() const throw();
		virtual ~BitcoinException() throw();
};

class BitcoinExchange{
	private:
		std::map<std::string, float> dataBase;

		void loadDataBase(const std::string &filePath);

		bool isAllDigit(const std::string nb) const;
		std::string decrementDate(const std::string &date) const;
		
		bool isValidDate(const std::string &date) const;
		bool isValidValue(const std::string &value) const;

	public:
		BitcoinExchange();
		BitcoinExchange(const BitcoinExchange &cp);
		BitcoinExchange &operator=(const BitcoinExchange &op);
		~BitcoinExchange();

		void process(const std::string &filePath);

};
