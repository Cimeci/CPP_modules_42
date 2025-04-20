/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inowak-- <inowak--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 10:30:28 by inowak--          #+#    #+#             */
/*   Updated: 2025/04/17 14:38:31 by inowak--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# pragma once

# include "colors.hpp"
# include "debug.hpp"
# include "macro.hpp"

# include <algorithm>
# include <iostream>
# include <limits>
# include <stack>
# include <sstream>

class RPNEXCEPTION : public std::exception {
	private:
		std::string _msg;
	public:
		RPNEXCEPTION(const std::string& msg);
		virtual const char* what() const throw();
		virtual ~RPNEXCEPTION() throw();
};

class RPN{
	private:
		std::stack<double> stack;

		void loadStack(const std::string &input, size_t op, size_t lastOp);
		void calcul(const std::string &input);

		// int stoi(const std::string &nb);
		void operation(const char op);

		void isEnough(const std::string &input);
		void isValidInput(const std::string &input) const;

	public:
		RPN();
		RPN(const RPN &cp);
		RPN &operator=(const RPN &op);
		~RPN();

		void process(const std::string input);

	
};