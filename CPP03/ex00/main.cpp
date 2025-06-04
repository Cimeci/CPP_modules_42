/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inowak-- <inowak--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 13:11:08 by inowak--          #+#    #+#             */
/*   Updated: 2025/03/19 22:24:24 by inowak--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main(void)
{
    ClapTrap soldier1("soldier1");
    ClapTrap soldier2;

    std::cout << "----- start -----\n";
    soldier1.attack("enemy");
    soldier1.takeDamage(5);
    soldier1.beRepaired(4);
    std::cout << "----- end -----\n";
}