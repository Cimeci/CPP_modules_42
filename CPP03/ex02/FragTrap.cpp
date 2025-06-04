/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inowak-- <inowak--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 14:52:17 by inowak--          #+#    #+#             */
/*   Updated: 2025/03/24 09:45:52 by inowak--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap(std::string name) : ClapTrap(name){
    hitPoint = 100;
    energyPoint = 100;
    attackDamage = 30;
	std::cout << "FragTrap called Claptrap name constructor\n";
};

FragTrap::FragTrap() : ClapTrap(){
    hitPoint = 100;
    energyPoint = 100;
    attackDamage = 30;
    std::cout << "FragTrap called Claptrap constructor\n";
}

FragTrap::FragTrap(const FragTrap &cp) : ClapTrap(cp){
	std::cout << "FragTrap called Claptrap copy constructor\n";
}

FragTrap &FragTrap::operator=(const FragTrap &op){
    ClapTrap::operator=(op);
    std::cout << "FragTrap called Claptrap operator\n";
    return (*this); 
}

FragTrap::~FragTrap(){
    std::cout << "FragTrap destroy\n";
}

void	FragTrap::attack(const std::string& target){
	if (energyPoint > 0 && hitPoint > 0)
	{
		std::cout << RED <<"FragTrap " << name <<" attacks " << target << ", causing " << attackDamage << " points of damage!\n" << RESET;
		energyPoint--;
	}
}

void FragTrap::highFivesGuys(){
    std::cout << PURPLE << "FragTrap " << name << " give a hightFive\n" << RESET;
}