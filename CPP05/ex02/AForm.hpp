/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inowak-- <inowak--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 13:36:24 by inowak--          #+#    #+#             */
/*   Updated: 2025/04/15 10:54:51 by inowak--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "colors.hpp"
#include <iostream>

class Bureaucrat;

class AForm{

	private:
		const std::string name;
		bool indicator;
		const int gradeToSign;
		const int gradeToExecute;
	
	public:
		// CANONICAL FORM //
		AForm();
		AForm(AForm const &cp);
		AForm &operator=(AForm const &op);
		virtual ~AForm(); // abstract class
		// CANONICAL FORM //

		AForm(const std::string &name, const int gradeToSign, const int gradeToExecute);

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

		class FormNotSignedException : public std::exception {
			public:
				const char* what() const throw();
			};

		std::string getName(void) const;
		bool getIndicator(void) const;
		int getGradeToSign(void) const;
		int getGradeToExecute(void) const;

		void beSigned(const Bureaucrat &b);
		void execute(Bureaucrat const & executor) const;
		virtual void executeAction(void) const = 0; // abstract class
};
std::ostream& operator<<(std::ostream& os, const AForm& b);