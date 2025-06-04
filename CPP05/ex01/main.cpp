/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inowak-- <inowak--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 11:30:58 by inowak--          #+#    #+#             */
/*   Updated: 2025/04/08 10:11:35 by inowak--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main(void)
{
	std::cout << BLUE << "-------- classic --------" << std::endl << RESET;

	try{
		Bureaucrat bureaucrat("Christophe", 5);
		std::cout << bureaucrat << std::endl;
		Form form("conctract42", 30, 10);
		std::cout << form << std::endl;
		bureaucrat.signForm(form);
	}
	catch (Bureaucrat::GradeTooHighException& e){std::cout << PURPLE << e.what() << std::endl << RESET;}
	catch (Bureaucrat::GradeTooLowException& e){std::cout << RED << e.what() << std::endl << RESET;}
	catch (Form::GradeTooHighException& e){std::cout << YELLOW << e.what() << std::endl << RESET;}
	catch (Form::GradeTooLowException& e){std::cout << CYAN << e.what() << std::endl << RESET;}

	std::cout << RED << "-------- ERROR --------" << std::endl << RESET;

	std::cout << RED << "\n-------- error1 --------" << std::endl << RESET;
	try{
		Bureaucrat bureaucrat("Jean", 100);
		std::cout << bureaucrat << std::endl;
		Form form("conctract42", 30, 10);
		std::cout << form << std::endl;
		bureaucrat.signForm(form);
	}
	catch (Bureaucrat::GradeTooHighException& e){std::cout << PURPLE << e.what() << std::endl << RESET;}
	catch (Bureaucrat::GradeTooLowException& e){std::cout << RED << e.what() << std::endl << RESET;}
	catch (Form::GradeTooHighException& e){std::cout << YELLOW << e.what() << std::endl << RESET;}
	catch (Form::GradeTooLowException& e){std::cout << CYAN << e.what() << std::endl << RESET;}

	std::cout << RED << "\n-------- error2 --------" << std::endl << RESET;
	try{
		Bureaucrat bureaucrat("Brice", 30);
		std::cout << bureaucrat << std::endl;
		Form form("Sudoku", 30, 10);
		std::cout << form << std::endl;
		bureaucrat.signForm(form);
		bureaucrat.decrementGrade();
		bureaucrat.signForm(form);
		
	}
	catch (Bureaucrat::GradeTooHighException& e){std::cout << PURPLE << e.what() << std::endl << RESET;}
	catch (Bureaucrat::GradeTooLowException& e){std::cout << RED << e.what() << std::endl << RESET;}
	catch (Form::GradeTooHighException& e){std::cout << YELLOW << e.what() << std::endl << RESET;}
	catch (Form::GradeTooLowException& e){std::cout << CYAN << e.what() << std::endl << RESET;}

	std::cout << BLUE << "\n-------- extra --------" << std::endl << RESET;
	try{
		Bureaucrat bureaucrat("Fabrice", 50);
		std::cout << bureaucrat << std::endl;
		Form form("chess", 50, 10);
		std::cout << form << std::endl;
		bureaucrat.signForm(form);
		bureaucrat.signForm(form);
		
	}
	catch (Bureaucrat::GradeTooHighException& e){std::cout << PURPLE << e.what() << std::endl << RESET;}
	catch (Bureaucrat::GradeTooLowException& e){std::cout << RED << e.what() << std::endl << RESET;}
	catch (Form::GradeTooHighException& e){std::cout << YELLOW << e.what() << std::endl << RESET;}
	catch (Form::GradeTooLowException& e){std::cout << CYAN << e.what() << std::endl << RESET;}
}