/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inowak-- <inowak--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 10:06:10 by inowak--          #+#    #+#             */
/*   Updated: 2025/03/27 15:53:50 by inowak--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIA_HPP
# define MATERIA_HPP

# include <iostream>
# include "colors.hpp"
# include "ICharacter.hpp"

class AMateria
{
	protected:
		std::string type;
	
	public:
	
		AMateria(std::string const & type);
		AMateria();
		AMateria(const AMateria &cp);
		AMateria &operator=(const AMateria &op);
		virtual ~AMateria();
		
		std::string const & getType() const;

		virtual AMateria* clone() const = 0;
		virtual void use(ICharacter& target);
};

#endif