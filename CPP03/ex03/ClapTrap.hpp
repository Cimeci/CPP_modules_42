/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inowak-- <inowak--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 11:18:44 by inowak--          #+#    #+#             */
/*   Updated: 2025/03/14 17:45:41 by inowak--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# define RED "\033[1;31m"
# define DARK_BLUE "\033[0;36m"
# define GREEN "\033[1;32m"
# define ORANGE "\033[38;5;214m"
# define YELLOW "\033[1;33m"
# define PURPLE "\033[1;35m"
# define BLUE   "\033[1;34m"
# define RESET "\033[0m"

# include <iostream>

class ClapTrap{
  
	protected:
		std::string name;
		int hitPoint;
		int energyPoint;
		int attackDamage;
	
	public:
		ClapTrap();
		ClapTrap(std::string name);
		ClapTrap(const ClapTrap &cp);
		ClapTrap &operator=(const ClapTrap &op);
		~ClapTrap();

		void attack(const std::string& target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);
};

#endif