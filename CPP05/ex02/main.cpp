/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inowak-- <inowak--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 10:28:01 by inowak--          #+#    #+#             */
/*   Updated: 2025/04/08 16:46:36 by inowak--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Bureaucrat.hpp"
# include "colors.hpp"
# include "PresidentialPardonForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "ShrubberyCreationForm.hpp"

int main(void){
	
	std::srand(std::time(0));
	int grade = std::rand() % 200;
	if (grade > 150)
	{
		std::srand(std::time(0));
		int r = std::rand() % 2;
		if (r == 0)
			grade *= -1;
	}
	std::cout << "Random grade is " << grade << std::endl;
	std::string name = "Mallory";
	try{
		Bureaucrat bureaucrat(name, grade);
		std::cout << bureaucrat << std::endl;
	
		std::cout << BOLD << UNDERLINE <<"\nShrubberyCreationForm : \n" << RESET << std::endl;
		
		ShrubberyCreationForm Sform("creation");
		std::cout << Sform << std::endl;
		bureaucrat.signForm(Sform);
		try{bureaucrat.executeForm(Sform);}
		catch(AForm::GradeTooLowException &e){std::cout << "error\n" << std::endl;}
		
		std::cout << BOLD << UNDERLINE <<"\nRobotomyRequestForm : \n" << RESET << std::endl;
		
		RobotomyRequestForm Rform("creation");
		std::cout << Rform << std::endl;
		bureaucrat.signForm(Rform);
		try{bureaucrat.executeForm(Rform);}
		catch(AForm::GradeTooLowException &e){std::cout << "error\n" << std::endl;}
		
		std::cout << BOLD << UNDERLINE <<"\nPresidentialPardonForm : \n" << RESET << std::endl;
		
		PresidentialPardonForm Pform("creation");
		std::cout << Pform << std::endl;
		bureaucrat.signForm(Pform);
		try{bureaucrat.executeForm(Pform);}
		catch(AForm::GradeTooLowException &e){std::cout << "error\n" << std::endl;}
	}
	catch (Bureaucrat::GradeTooHighException& e){std::cout << PURPLE << name << " has " << e.what() << std::endl << RESET;}
	catch (Bureaucrat::GradeTooLowException& e){std::cout << RED << name << " has " << e.what() << std::endl << RESET;}
}	