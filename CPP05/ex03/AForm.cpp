/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inowak-- <inowak--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 13:44:52 by inowak--          #+#    #+#             */
/*   Updated: 2025/04/15 10:54:30 by inowak--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm(): name("default"), indicator(0), gradeToSign(150), gradeToExecute(150){}
AForm::AForm(AForm const &cp):name(cp.name),indicator(cp.indicator),gradeToSign(cp.gradeToSign),gradeToExecute(cp.gradeToExecute){}
AForm &AForm::operator=(AForm const &op){
    if (this != &op) {
        this->indicator = op.indicator;
    }
    return *this;
}
AForm::AForm(const std::string &name, const int gradeToSign, const int gradeToExecute): name(name), indicator(0), gradeToSign(gradeToSign), gradeToExecute(gradeToExecute){
		if (gradeToSign > 150 || gradeToExecute > 150)
			throw GradeTooLowException();
		else if (gradeToSign < 1 || gradeToExecute > 150)
			throw GradeTooHighException();
}

AForm::~AForm(){}

const char* AForm::GradeTooHighException::what() const throw() {return "GradeTooHighException";}

const char* AForm::GradeTooLowException::what() const throw() {return "GradeTooLowException";}

const char* AForm::AlreadySigned::what() const throw() {return "AlreadySigned";}

const char* AForm::FormNotSignedException::what() const throw() {return "FormNotSignedException";}


std::string AForm::getName(void) const{return name;}
bool AForm::getIndicator(void) const{return indicator;}
int AForm::getGradeToSign(void) const{return gradeToSign;}
int AForm::getGradeToExecute(void) const{return gradeToExecute;}

std::ostream& operator<<(std::ostream& os, const AForm& b) {
	os << YELLOW << "AForm " << b.getName() << ", gradeToSign " << b.getGradeToSign() << ", gradeToExecute " << b.getGradeToExecute() << "." << RESET;
	return os;
}

void AForm::beSigned(const Bureaucrat &b){
	if (b.getGrade() <= gradeToSign)
	{
		if (indicator == true)
			throw AlreadySigned();
		indicator = true;
	}
	else
		throw GradeTooLowException();
}

void AForm::execute(Bureaucrat const & executor) const{
	if (!indicator)
		throw AForm::FormNotSignedException();
	if (executor.getGrade() > gradeToExecute)
		throw AForm::GradeTooLowException();
	executeAction();
}

