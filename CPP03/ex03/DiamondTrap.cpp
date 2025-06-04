/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inowak-- <inowak--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 15:28:20 by inowak--          #+#    #+#             */
/*   Updated: 2025/03/24 09:46:13 by inowak--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(std::string name): ClapTrap(name + "_clap_name"), ScavTrap(name), FragTrap(name), name(name){
    hitPoint = FragTrap::hitPoint; // 100 
    attackDamage = FragTrap::attackDamage; // 30
    energyPoint = ScavTrap::energyPoint; // 50
	std::cout << "DiamondTrap called Claptrap name constructor\n";
    std::cout << ORANGE << "name: " << name << " | hitPoint: " << hitPoint << " | engeryPoint: " << energyPoint << " | attackDamage: " << attackDamage << RESET << "\n";
};

DiamondTrap::DiamondTrap() : ClapTrap(){
    hitPoint = FragTrap::hitPoint; // 100 
    attackDamage = FragTrap::attackDamage; // 30
    energyPoint = ScavTrap::energyPoint; // 50
    std::cout << "DiamondTrap called Claptrap constructor\n";
}

DiamondTrap::DiamondTrap(const DiamondTrap &cp) : ClapTrap(cp){
	std::cout << "DiamondTrap called Claptrap copy constructor\n";
}

DiamondTrap &DiamondTrap::operator=(const DiamondTrap &op){
    ClapTrap::operator=(op);
    std::cout << "DiamondTrap called Claptrap operator\n";
    return (*this); 
}

DiamondTrap::~DiamondTrap(){
	std::cout << "DiamondTrap destroy\n";
}

void	DiamondTrap::attack(const std::string& target){
    ScavTrap::attack(target);
}

void    DiamondTrap::whoAmI(void){
    std::cout << DARK_BLUE << "DiamondTrap name: " << name << "\nClapTrap name: " << ClapTrap::name << "\n" << RESET; 
}