/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inowak-- <inowak--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 15:47:42 by inowak--          #+#    #+#             */
/*   Updated: 2025/04/18 16:24:09 by inowak--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# pragma once

# include "debug.hpp"

# include "colors.hpp"
# include "macro.hpp"

# include <iostream>
# include <vector>
# include <deque>
# include <algorithm>
# include <ctime>

class PMERGEMEEXCEPTION : public std::exception {
	private:
		std::string _msg;
	public:
		PMERGEMEEXCEPTION(const std::string& msg);
		virtual const char* what() const throw();
		virtual ~PMERGEMEEXCEPTION() throw();
};

class PmergeMe{
	private:
		std::vector<int> Cvector;
		std::deque<int> Cdeque;

		std::time_t Vstart;
		std::time_t Dstart;

		size_t size;

		void loadContainer(char **argv);
		void isValid(const std::string nb) const;

		template<typename T>
		void sort(T container);

	public:
		PmergeMe();
		PmergeMe(const PmergeMe &cp);
		PmergeMe &operator=(const PmergeMe &op);
		~PmergeMe();

		void process(char **argv);
};

