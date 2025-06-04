/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inowak-- <inowak--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 11:30:15 by inowak--          #+#    #+#             */
/*   Updated: 2025/04/15 10:50:13 by inowak--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "RobotomyRequestForm.hpp"
# include "Bureaucrat.hpp"

// CANONICAL FORM //
RobotomyRequestForm::RobotomyRequestForm():AForm("RobotomyRequestForm", 72, 45), target("default"){}
RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const &cp): AForm(cp), target(cp.target){}
RobotomyRequestForm &RobotomyRequestForm::operator=(RobotomyRequestForm const &op){
	if (this != &op){AForm::operator=(op);}
	return *this;
}
RobotomyRequestForm::~RobotomyRequestForm(){}
// CANONICAL FORM //

RobotomyRequestForm::RobotomyRequestForm(const std::string target):AForm("RobotomyRequestForm", 72, 45), target(target){}

void RobotomyRequestForm::executeAction() const{
	std::cout << "Drilling noises..." << std :: endl;
	std::srand(std::time(0));
	int r = std::rand() % 2;
	if (r == 0)
		std::cout << "Robotomy failed!" << std::endl;
   	else
		std::cout << "Robotomy succeeded!" << std::endl;
}

std::string RobotomyRequestForm::getTarget() const {return target;}

std::ostream& operator<<(std::ostream& os, const RobotomyRequestForm& b){
	os << RED << "RobotomyRequestForm" << RESET << " have target: " << b.getTarget() << YELLOW <<", gradeToSign: 72 and gradeToExecute: 45 ." << RESET;
	return os;
}
