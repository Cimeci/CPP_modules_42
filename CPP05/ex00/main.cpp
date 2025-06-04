/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inowak-- <inowak--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 11:30:58 by inowak--          #+#    #+#             */
/*   Updated: 2025/04/07 16:24:24 by inowak--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main(void)
{
	std::cout << BLUE << "-------- classic --------" << std::endl << RESET;

	try{
		Bureaucrat bureaucrat("Christophe", 5);
		std::cout << bureaucrat << std::endl;
		bureaucrat.incrementGrade();
		std::cout << bureaucrat << std::endl;
		bureaucrat.decrementGrade();
		std::cout << bureaucrat << std::endl;
	}
	catch (Bureaucrat::GradeTooHighException& e){std::cout << PURPLE << e.what() << std::endl << RESET;}
	catch (Bureaucrat::GradeTooLowException& e){std::cout << RED << e.what() << std::endl << RESET;}

	std::cout << RED << "-------- ERROR --------" << std::endl << RESET;

	std::cout << "\n-------- error1 --------" << std::endl;

	try{
		Bureaucrat bureaucrat1("Jean", 5);
		std::cout << bureaucrat1 << std::endl;
		for (int i = 0; i < 50; i++)
			bureaucrat1.incrementGrade();
		std::cout << bureaucrat1 << std::endl;
		std::cout << "decrementGrade" << std::endl;
		bureaucrat1.decrementGrade();
		std::cout << bureaucrat1 << std::endl;
	}
	catch (Bureaucrat::GradeTooHighException& e){std::cout << PURPLE << e.what() << std::endl << RESET;}
	catch (Bureaucrat::GradeTooLowException& e){std::cout << RED << e.what() << std::endl << RESET;}

	std::cout << "\n-------- error2 --------" << std::endl;

	try{
		Bureaucrat bureaucrat2("Bob", 0);
		std::cout << bureaucrat2 << std::endl;
	}
	catch (Bureaucrat::GradeTooHighException& e){std::cout << PURPLE << e.what() << std::endl << RESET;}
	catch (Bureaucrat::GradeTooLowException& e){std::cout << RED << e.what() << std::endl << RESET;}

	std::cout << "\n-------- error3 --------" << std::endl;
	
	try{
		Bureaucrat bureaucrat3("Jacque", 200);
		std::cout << bureaucrat3 << std::endl;
	}
	catch (Bureaucrat::GradeTooHighException& e){std::cout << PURPLE << e.what() << std::endl << RESET;}
	catch (Bureaucrat::GradeTooLowException& e){std::cout << RED << e.what() << std::endl << RESET;}
}