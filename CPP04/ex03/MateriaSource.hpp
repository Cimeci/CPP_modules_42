/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inowak-- <inowak--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 09:51:09 by inowak--          #+#    #+#             */
/*   Updated: 2025/03/27 13:35:13 by inowak--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP

# include "IMateriaSource.hpp"
# include "AMateria.hpp"

class MateriaSource : public IMateriaSource
{
    private:
        AMateria *inventory[4];
    
    public:
        MateriaSource();
        MateriaSource(const MateriaSource &cp);
        MateriaSource &operator=(const MateriaSource &op);
        ~MateriaSource();

        void learnMateria(AMateria*);
		AMateria* createMateria(std::string const & type);
};

#endif