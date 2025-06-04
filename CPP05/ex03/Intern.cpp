/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inowak-- <inowak--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 17:54:34 by inowak--          #+#    #+#             */
/*   Updated: 2025/04/09 17:16:09 by inowak--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Intern.hpp"
# include <string>

Intern::Intern(){}
Intern::Intern(Intern const &cp){*this = cp;}
Intern &Intern::operator=(Intern const &op){\
	if(this != &op)
		return *this;
	return (*this);
	}
Intern::~Intern(){}

AForm *Intern::makeForm(const std::string &FormName, const std::string &FormTarget){
	
	std::string name[3] = {
		"shrubbery creation",
		"robotomy request",
		"presidential pardon"
	};

	int n;
	for (n = 0; n < 3 && name[n] != FormName; n++);

	switch(n){
		case 0:
			std::cout << YELLOW << "Intern creates " << FormName << RESET << std::endl;
			return new ShrubberyCreationForm(FormTarget);
		case 1:
			std::cout << BLUE << "Intern creates " << FormName << RESET << std::endl;
			return new RobotomyRequestForm(FormTarget);
		case 2:
			std::cout << PURPLE << "Intern creates " << FormName << RESET << std::endl;
			return new PresidentialPardonForm(FormTarget);
		default:
			std::cout << RED << FormName << " doesn't exist" << RESET << std::endl;
			return NULL;
	}
}
