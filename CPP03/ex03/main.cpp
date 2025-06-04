/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inowak-- <inowak--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 13:11:08 by inowak--          #+#    #+#             */
/*   Updated: 2025/03/14 17:39:04 by inowak--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"

int main(void)
{
    ClapTrap soldier1("soldier1");
    ScavTrap soldier2("soldier2");
    FragTrap soldier3("soldier3");
    DiamondTrap soldier4("soldier4");

    std::cout << "----- start -----\n";
    soldier1.attack("enemy1");
    soldier1.takeDamage(5);
    soldier1.beRepaired(4);
    std::cout << "----- ex01 -----\n";
    soldier2.attack("enemy2");
    soldier2.takeDamage(5);
    soldier2.beRepaired(4);
    soldier2.guardGate();
    std::cout << "----- ex02 -----\n";
    soldier3.attack("enemy3");
    soldier3.takeDamage(5);
    soldier3.beRepaired(4);
    soldier3.highFivesGuys();
    std::cout << "----- ex02 -----\n";
    soldier4.attack("enemy4");
    soldier4.takeDamage(5);
    soldier4.beRepaired(4);
    soldier4.whoAmI();
    std::cout << "----- end -----\n";
}