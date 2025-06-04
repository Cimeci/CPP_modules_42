/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inowak-- <inowak--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 10:58:42 by inowak--          #+#    #+#             */
/*   Updated: 2025/04/09 17:25:24 by inowak--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(): name("default"), grade(150){}
Bureaucrat::Bureaucrat(Bureaucrat const &cp){*this = cp;}
Bureaucrat &Bureaucrat::operator=(Bureaucrat const &op){
	if (this != &op){
		grade = op.grade;
	}
	return *this;
}
Bureaucrat::~Bureaucrat(){}
Bureaucrat::Bureaucrat(const std::string& name, int grade): name(name){
	if (grade > 150)
		throw GradeTooLowException();
	else if (grade < 1)
		throw GradeTooHighException();
	this->grade = grade;
}

const char* Bureaucrat::GradeTooHighException::what() const throw() {return "GradeTooHighException";}

const char* Bureaucrat::GradeTooLowException::what() const throw() {return "GradeTooLowException";}

std::string Bureaucrat::getName(void) const{return (name);}
int Bureaucrat::getGrade(void) const{return (grade);}

void	Bureaucrat::incrementGrade(void) {
	if (grade > 1)grade--;
	else throw GradeTooHighException();
}
void	Bureaucrat::decrementGrade(void) {
	if (grade < 150)grade++;
	else throw GradeTooLowException();
}

std::ostream& operator<<(std::ostream& os, const Bureaucrat& b) {
	os << GREEN << b.getName() << ", bureaucrat grade " << b.getGrade() << "." << RESET;
	return os;
}

void	Bureaucrat::signForm(Form &form) const{
	
	try{
		form.beSigned(*this);
    	std::cout << BOLD << name << RESET << " signed " << form.getName() << std::endl;
	}
	catch (Form::GradeTooLowException &e){
		std::cout << BOLD << name << RESET << " couldn't sign " << form.getName() << " because " << BLUE_BOLD << grade << " > " << form.getGradeToSign() << "." << std::endl << RESET;
	}
	catch (Form::AlreadySigned &e){
		std::cout << BOLD << name << RESET << " has already signed " << form.getName() << "." << std::endl;
	}	
}