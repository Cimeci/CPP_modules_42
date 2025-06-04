/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inowak-- <inowak--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 14:53:20 by inowak--          #+#    #+#             */
/*   Updated: 2025/03/10 16:35:47 by inowak--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

void Harl::debug(void){
	std::cout << RED << "DEBUG: " << RESET << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger."
		<< "I really do!" << std::endl;
}

void Harl::info(void){
	std::cout << BLUE << "INFO: " << RESET << "I cannot believe adding extra bacon costs more money."
		<< " You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!" << std::endl;
}

void Harl::warning(void){
	std::cout << YELLOW << "WARNING: " << RESET << "I think I deserve to have some extra bacon for free."
	<< " I’ve been coming for years, whereas you started working here just last month." << std::endl;
}

void Harl::error(void){
	std::cout << PURPLE << "ERROR: " << RESET << "This is unacceptable! I want to speak to the manager now." << std::endl;
}

void Harl::complain(std::string level){

	std::string levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	int lvl;

	for (lvl = 0; level != levels[lvl] && lvl < 4; lvl++){};
	
	switch(lvl){
		default:
			std::cout << "[ Probably complaining about insignificant problems ]\n";
		case 0:
			Harl::debug();
			break;
		case 1:
			Harl::info();
			break;
		case 2:
			Harl::warning();
			break;
		case 3:
			Harl::error();
			break;
	}
}