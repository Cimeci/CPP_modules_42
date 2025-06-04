/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inowak-- <inowak--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 11:18:44 by inowak--          #+#    #+#             */
/*   Updated: 2025/03/14 15:57:57 by inowak--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

# include "ClapTrap.hpp"

class FragTrap : public ClapTrap{

	public:
        FragTrap(std::string name);
		FragTrap();
		FragTrap(const FragTrap &cp);
		FragTrap &operator=(const FragTrap &op);
		~FragTrap();

		void attack(const std::string& target);
        void highFivesGuys(void);
};

#endif