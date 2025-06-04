/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inowak-- <inowak--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 13:11:08 by inowak--          #+#    #+#             */
/*   Updated: 2025/03/19 22:23:42 by inowak--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main(void)
{
    ClapTrap soldier1("soldier1");
    ScavTrap soldier2("soldier2");

    std::cout << "----- start -----\n";
    soldier1.attack("enemy1");
    soldier1.takeDamage(5);
    soldier1.beRepaired(4);
    std::cout << "----- ex01 -----\n";
    soldier2.attack("enemy2");
    soldier2.takeDamage(5);
    soldier2.beRepaired(4);
    soldier2.guardGate();
    std::cout << "----- end -----\n";
}