/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inowak-- <inowak--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 10:46:36 by inowak--          #+#    #+#             */
/*   Updated: 2025/04/09 17:24:48 by inowak--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "colors.hpp"
#include "Form.hpp"
#include <iostream>

class Bureaucrat{
	
	private:
		const std::string name;
		int grade;
		
	public:
		// CANONICAL FORM //
		Bureaucrat();
		Bureaucrat(Bureaucrat const &cp);
		Bureaucrat &operator=(Bureaucrat const &op);
		~Bureaucrat();
		// CANONICAL FORM //
		Bureaucrat(const std::string& name, int grade);

		class GradeTooHighException : public std::exception {
			public:
				const char* what() const throw();
			};
		
		class GradeTooLowException : public std::exception {
			public:
				const char* what() const throw();
			};
		
		std::string getName(void) const;
		int getGrade(void) const;

		void	incrementGrade(void);
		void	decrementGrade(void);

		void	signForm(Form &form) const;
};
std::ostream& operator<<(std::ostream& os, const Bureaucrat& b);