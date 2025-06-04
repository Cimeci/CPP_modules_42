/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inowak-- <inowak--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 11:30:15 by inowak--          #+#    #+#             */
/*   Updated: 2025/04/15 10:50:30 by inowak--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "PresidentialPardonForm.hpp"
# include "Bureaucrat.hpp"

// CANONICAL FORM //
PresidentialPardonForm::PresidentialPardonForm():AForm("PresidentialPardonForm", 25, 5), target("default"){}
PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const &cp): AForm(cp), target(cp.target){}
PresidentialPardonForm &PresidentialPardonForm::operator=(PresidentialPardonForm const &op){
	if (this != &op){AForm::operator=(op);}
	return *this;
}
PresidentialPardonForm::~PresidentialPardonForm(){}
// CANONICAL FORM //

PresidentialPardonForm::PresidentialPardonForm(const std::string target):AForm("PresidentialPardonForm", 25, 5), target(target){}

void PresidentialPardonForm::executeAction(void) const{
		std::cout << target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}

std::string PresidentialPardonForm::getTarget() const {return target;}

std::ostream& operator<<(std::ostream& os, const PresidentialPardonForm& b){
	os << RED << "PresidentialPardonForm" << RESET << " have target: " << b.getTarget() << YELLOW <<", gradeToSign: 25 and gradeToExecute: 5 ." << RESET;
	return os;
}