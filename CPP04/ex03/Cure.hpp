/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inowak-- <inowak--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 10:15:56 by inowak--          #+#    #+#             */
/*   Updated: 2025/03/27 15:17:18 by inowak--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CURE_HPP
# define CURE_HPP

# include "AMateria.hpp"

class Cure: public AMateria{
    
    public:
        Cure();
        Cure(const Cure &cp);
        Cure &operator=(const Cure &op);
        ~Cure();

        virtual Cure* clone() const;
        virtual void use(ICharacter& target);
};

#endif