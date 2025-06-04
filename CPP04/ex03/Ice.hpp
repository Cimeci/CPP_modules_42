/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inowak-- <inowak--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 10:15:56 by inowak--          #+#    #+#             */
/*   Updated: 2025/03/27 09:51:29 by inowak--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICE_HPP
# define ICE_HPP

# include <iostream>
# include "AMateria.hpp"

class Ice: public AMateria{
    
    public:
        Ice();
        Ice(const Ice &cp);
        Ice &operator=(const Ice &op);
        ~Ice();

        virtual Ice* clone() const;
        virtual void use(ICharacter& target);
};

#endif