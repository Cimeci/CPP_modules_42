/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inowak-- <inowak--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 10:58:42 by inowak--          #+#    #+#             */
/*   Updated: 2025/04/07 16:23:50 by inowak--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(const std::string& name, int grade): name(name){
	if (grade > 150)
		throw GradeTooLowException();
	else if (grade < 1)
		throw GradeTooHighException();
	this->grade = grade;
}
Bureaucrat::~Bureaucrat(){}

const char* Bureaucrat::GradeTooHighException::what() const throw() {return "GradeTooHighException";}

const char* Bureaucrat::GradeTooLowException::what() const throw() {return "GradeTooLowException";}

std::string Bureaucrat::getName(void) const{return (name);}
int Bureaucrat::getGrade(void) const{return (grade);}

void	Bureaucrat::incrementGrade(void) {
	if (grade > 1){
		grade--;
		std::cout << "Increment grade : " << grade << std::endl;
	}
	else throw GradeTooHighException();
}
void	Bureaucrat::decrementGrade(void) {
	if (grade < 150){
		grade++;
		std::cout << "Decrement grade : " << grade << std::endl;
	}
	else throw GradeTooLowException();
}

std::ostream& operator<<(std::ostream& os, const Bureaucrat& b) {
	os << GREEN << b.getName() << ", bureaucrat grade " << b.getGrade() << "." << RESET;
	return os;
}