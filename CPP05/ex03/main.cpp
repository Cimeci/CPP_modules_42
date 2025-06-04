/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inowak-- <inowak--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 10:28:01 by inowak--          #+#    #+#             */
/*   Updated: 2025/04/09 17:17:44 by inowak--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Bureaucrat.hpp"
# include "Intern.hpp"

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
	
		Intern someRandomIntern;
		AForm* SForm = someRandomIntern.makeForm("shrubbery creation", "creation");
		AForm* RForm = someRandomIntern.makeForm("robotomy request", "robot");
		AForm* PForm = someRandomIntern.makeForm("presidential pardon", "sorry");
		AForm* CForm = someRandomIntern.makeForm("caca", "Bender");
		
		std::cout << "\nBureaucrat Signed :\n" << std::endl;

		bureaucrat.signForm(*SForm);
		bureaucrat.signForm(*RForm);
		bureaucrat.signForm(*PForm);

		std::cout << "\nBureaucrat Execute :" << std::endl;

		std::cout << BOLD << UNDERLINE <<"\nShrubberyCreationForm : \n" << RESET << std::endl;
		
		try{bureaucrat.executeForm(*SForm);}
		catch(AForm::GradeTooLowException &e){std::cout << "error\n" << std::endl;}

		std::cout << BOLD << UNDERLINE <<"\nRobotomyRequestForm : \n" << RESET << std::endl;
		
		try{bureaucrat.executeForm(*RForm);}
		catch(AForm::GradeTooLowException &e){std::cout << "error\n" << std::endl;}

		std::cout << BOLD << UNDERLINE <<"\nPresidentialPardonForm : \n" << RESET << std::endl;
		
		try{bureaucrat.executeForm(*PForm);}
		catch(AForm::GradeTooLowException &e){std::cout << "error\n" << std::endl;}
		
		delete RForm;
		delete SForm;
		delete PForm;
		delete CForm;

	}
	catch (Bureaucrat::GradeTooHighException& e){std::cout << PURPLE << name << " has " << e.what() << std::endl << RESET;}
	catch (Bureaucrat::GradeTooLowException& e){std::cout << RED << name << " has " << e.what() << std::endl << RESET;}
}	