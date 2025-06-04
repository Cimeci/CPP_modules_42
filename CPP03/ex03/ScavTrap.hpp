/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inowak-- <inowak--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 11:18:44 by inowak--          #+#    #+#             */
/*   Updated: 2025/03/14 18:20:06 by inowak--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

# include "ClapTrap.hpp"

class ScavTrap : virtual public ClapTrap{

	protected:
		int energyPoint;

	public:
        ScavTrap(std::string name);
		ScavTrap();
		ScavTrap(const ScavTrap &cp);
		ScavTrap &operator=(const ScavTrap &op);
		~ScavTrap();

		void attack(const std::string& target);
        void guardGate();
};

#endif