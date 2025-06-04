/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inowak-- <inowak--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 10:52:30 by inowak--          #+#    #+#             */
/*   Updated: 2025/04/15 10:50:46 by inowak--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "ShrubberyCreationForm.hpp"
# include "Bureaucrat.hpp"

// CANONICAL FORM //
ShrubberyCreationForm::ShrubberyCreationForm():AForm("ShrubberyCreationForm", 145, 137), target("default"){}
ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const &cp): AForm(cp), target(cp.target){}
ShrubberyCreationForm &ShrubberyCreationForm::operator=(ShrubberyCreationForm const &op){
	if (this != &op){AForm::operator=(op);}
	return *this;
}
ShrubberyCreationForm::~ShrubberyCreationForm(){}
// CANONICAL FORM //

ShrubberyCreationForm::ShrubberyCreationForm(const std::string target):AForm("ShrubberyCreationForm", 145, 137), target(target){}

void ShrubberyCreationForm::executeAction(void) const{
		std::ofstream file;
		std::string filename = target + "_shrubbery";
		file.open(filename.c_str(), std::ios::out);
		if (!file.is_open()){
			std::cerr << "Error : open file !" << std::endl;
			return ;
		}
		file << "       ###             ###" << std::endl;
		file << "      #o###           #o###" << std::endl;
		file << "    #####o###       #####o###" << std::endl;
		file << "   #o#\\#|#/###     #o#\\#|#/###" << std::endl;
		file << "    ###\\|/#o#       ###\\|/#o#" << std::endl;
		file << "     # }|{  #        # }|{  #" << std::endl;
		file << "       }|{             }|{   " << std::endl;
		file.close();
}

std::string ShrubberyCreationForm::getTarget() const {return target;}

std::ostream& operator<<(std::ostream& os, const ShrubberyCreationForm& b){
	os << RED << "ShrubberyCreationForm" << RESET << " have target: " << b.getTarget() << YELLOW << ", gradeToSign: 145 and gradeToExecute: 137 ." << RESET;
	return os;
}