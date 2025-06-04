/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inowak-- <inowak--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 14:02:44 by inowak--          #+#    #+#             */
/*   Updated: 2025/03/24 09:45:32 by inowak--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap(std::string name) : ClapTrap(name){
    hitPoint = 100;
    energyPoint = 50;
    attackDamage = 20;
	std::cout << "ScavTrap called Claptrap name constructor\n";
};

ScavTrap::ScavTrap() : ClapTrap(){
    hitPoint = 100;
    energyPoint = 50;
    attackDamage = 20;
    std::cout << "ScavTrap called Claptrap constructor\n";
}

ScavTrap::ScavTrap(const ScavTrap &cp) : ClapTrap(cp){
	std::cout << "ScavTrap called Claptrap copy constructor\n";
}

ScavTrap &ScavTrap::operator=(const ScavTrap &op){
    ClapTrap::operator=(op);
    std::cout << "ScavTrap called Claptrap operator\n";
    return (*this); 
}

ScavTrap::~ScavTrap(){
	std::cout << "ScavTrap destroy\n";
}

void	ScavTrap::attack(const std::string& target){
	if (energyPoint > 0 && hitPoint > 0)
	{
		std::cout << RED <<"ScavTrap " << name <<" attacks " << target << ", causing " << attackDamage << " points of damage!\n" << RESET;
		energyPoint--;
	}
}


void ScavTrap::guardGate(){
    std::cout << BLUE << "ScavTrap " << name << " is now in Gate keeper mode\n" << RESET;
}
