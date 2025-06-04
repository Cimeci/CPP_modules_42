/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inowak-- <inowak--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 09:50:59 by inowak--          #+#    #+#             */
/*   Updated: 2025/03/28 09:56:24 by inowak--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "MateriaSource.hpp"

MateriaSource::MateriaSource(){
    // std::cout << "MateriaSource constructor\n";
    for (int i = 0; i < 4; i++)
			inventory[i] = NULL;
}

MateriaSource::MateriaSource(const MateriaSource &cp){
    // std::cout << "MateriaSource copy constructor\n";
	for (int i = 0; i < 4; i++)
	{
		if (cp.inventory[i])
			inventory[i] = cp.inventory[i]->clone(); // deep copy
		else
			inventory[i] = NULL;
	}
}

MateriaSource &MateriaSource::operator=(const MateriaSource &op){
	if (this != &op)
    {
		for (int i = 0; i < 4; i++)
        {
			delete inventory[i];
			if (op.inventory[i])
				inventory[i] = op.inventory[i]->clone(); // deep copy
			else
				inventory[i] = NULL;
		}
	}
	return *this;
}

MateriaSource::~MateriaSource(){
    for (int i = 0; i < 4; i++)
    {
        if (inventory[i])
            delete inventory[i];
    }
    // std::cout << "MateriaSource constructor\n";
}

void MateriaSource::learnMateria(AMateria *m){
    int i;
    
    if (m)
    {
        for (i = 0; i < 4; i++)
        {
            if (inventory[i] == NULL)
            {
                inventory[i] = m->clone();
                break;
            }
        }
        delete m;
        if (i < 4)
            std::cout << GREEN << "Use of inventory of MateriaSource is " << i + 1  << "/4\n" << RESET;
        else
            std::cout << RED << "Use of inventory of MateriaSource is full\n" << RESET;
    }
}

AMateria *MateriaSource::createMateria(std::string const & type){
    for (int i = 0; i < 4; i++)
    {
        if (inventory[i] && inventory[i]->getType() == type){
            std::cout << BLUE << "Create Materia with " << type << " type\n" << RESET;
            return inventory[i]->clone();
        }
    }
    std::cout << PURPLE << "Unknow type: \"" << type << "\" in materia inventory\n" << RESET;
    return (NULL);
}