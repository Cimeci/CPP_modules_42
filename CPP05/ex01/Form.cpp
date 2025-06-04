/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inowak-- <inowak--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 13:44:52 by inowak--          #+#    #+#             */
/*   Updated: 2025/04/09 17:26:57 by inowak--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form(): name("default"), gradeToSign(150), gradeToExecute(150){}
Form::Form(Form const &cp):name(cp.name),indicator(cp.indicator),gradeToSign(cp.gradeToSign),gradeToExecute(cp.gradeToExecute){}
Form &Form::operator=(Form const &op){
    if (this != &op) {
        this->indicator = op.indicator;
    }
    return *this;
}
Form::~Form(){}
Form::Form(const std::string &name, const int gradeToSign, const int gradeToExecute): name(name), indicator(0), gradeToSign(gradeToSign), gradeToExecute(gradeToExecute){
		if (gradeToSign > 150 || gradeToExecute > 150)
			throw GradeTooLowException();
		else if (gradeToSign < 1 || gradeToExecute > 150)
			throw GradeTooHighException();
}

const char* Form::GradeTooHighException::what() const throw() {return "GradeTooHighException";}

const char* Form::GradeTooLowException::what() const throw() {return "GradeTooLowException";}

const char* Form::AlreadySigned::what() const throw() {return "AlreadySigned";}

std::string Form::getName(void) const{return name;}
bool Form::getIndicator(void) const{return indicator;}
int Form::getGradeToSign(void) const{return gradeToSign;}
int Form::getGradeToExecute(void) const{return gradeToExecute;}

std::ostream& operator<<(std::ostream& os, const Form& b) {
	os << YELLOW << "Form " << b.getName() << ", gradeToSign " << b.getGradeToSign() << ", gradeToExecute " << b.getGradeToExecute() << "." << RESET;
	return os;
}

void Form::beSigned(const Bureaucrat &b){
	if (b.getGrade() <= gradeToSign)
	{
		if (indicator == true)
			throw AlreadySigned();
		indicator = true;
	}
	else
		throw GradeTooLowException();
}
