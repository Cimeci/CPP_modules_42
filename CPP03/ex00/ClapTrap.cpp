/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inowak-- <inowak--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 11:25:23 by inowak--          #+#    #+#             */
/*   Updated: 2025/03/19 22:24:49 by inowak--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(std::string name): hitPoint(10), energyPoint(10), attackDamage(0){
	this->name = name;
	std::cout << "ClapTrap name creat\n";
};

ClapTrap::ClapTrap(): hitPoint(10), energyPoint(10), attackDamage(0){
	this->name = "default";
	std::cout << "ClapTrap creat\n";
}

ClapTrap::ClapTrap(const ClapTrap &cp){
	*this = cp;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &op){
	if (this != &op){
		name = op.name;
		hitPoint = op.hitPoint;
		energyPoint = op.energyPoint;
		attackDamage = op.attackDamage;
	}
	return (*this);
}

ClapTrap::~ClapTrap(){
	std::cout << "ClapTrap destroy\n";
}

void	ClapTrap::attack(const std::string& target){
	if (energyPoint > 0 && hitPoint > 0)
	{
		std::cout << RED <<"ClapTrap " << name <<" attacks " << target << ", causing " << attackDamage << " points of damage!\n" << RESET;
		energyPoint--;
	}
}

void	ClapTrap::takeDamage(unsigned int amount){
	if (hitPoint > 0)
	{
		std::cout << YELLOW << "ClapTrap " << name << " with " << hitPoint << " hit point take " << amount << " points of damages\n";
		hitPoint -= amount;
		std::cout << "ClapTrap " << name << " drop to " << hitPoint << " hit point\n" << RESET;
	}
	else
		std::cout << YELLOW << "Stop the harassment\n" << RESET;
}

void	ClapTrap::beRepaired(unsigned int amount){
	if (energyPoint > 0 && hitPoint > 0)
	{
		std::cout << GREEN << "ClapTrap " << name << " repair " << amount << " hit point!\n";
		hitPoint += amount;
		std::cout << "ClapTrap " << name << " up to " << hitPoint << " hit point!\n" << RESET;
		energyPoint--;
	}
}