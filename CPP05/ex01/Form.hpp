/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inowak-- <inowak--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 13:36:24 by inowak--          #+#    #+#             */
/*   Updated: 2025/04/09 17:26:39 by inowak--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "colors.hpp"
#include <iostream>

class Bureaucrat;

class Form{

	private:
		const std::string name;
		bool indicator;
		const int gradeToSign;
		const int gradeToExecute;
	
	public:
		// CANONICAL FORM //
		Form();
		Form(Form const &cp);
		Form &operator=(Form const &op);
		~Form();
		// CANONICAL FORM //

		Form(const std::string &name, const int gradeToSign, const int gradeToExecute);

		class GradeTooHighException : public std::exception {
			public:
				const char* what() const throw();
			};
		
		class GradeTooLowException : public std::exception {
			public:
				const char* what() const throw();
			};
		class AlreadySigned : public std::exception {
			public:
				const char* what() const throw();
			};

		std::string getName(void) const;
		bool getIndicator(void) const;
		int getGradeToSign(void) const;
		int getGradeToExecute(void) const;

		void beSigned(const Bureaucrat &b);
};
std::ostream& operator<<(std::ostream& os, const Form& b);