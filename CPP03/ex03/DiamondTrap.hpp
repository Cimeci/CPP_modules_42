/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inowak-- <inowak--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 15:03:06 by inowak--          #+#    #+#             */
/*   Updated: 2025/03/14 17:34:03 by inowak--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP

# include "ClapTrap.hpp"
# include "FragTrap.hpp"
# include "ScavTrap.hpp"

class DiamondTrap : public ScavTrap, public FragTrap {

    private:
        std::string name;

    public:
        DiamondTrap(std::string name);
        DiamondTrap();
        DiamondTrap(const DiamondTrap &cp);
        DiamondTrap &operator=(const DiamondTrap &op);
        ~DiamondTrap(); 
    
        void attack(const std::string& target);
        void whoAmI();

};

#endif