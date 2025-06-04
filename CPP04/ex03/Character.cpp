/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inowak-- <inowak--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 15:04:50 by inowak--          #+#    #+#             */
/*   Updated: 2025/03/28 10:27:31 by inowak--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Character.hpp"

Character::Character(std::string const & name) : name(name){
	// std::cout << "Character constructor name\n";
	for (int i = 0; i < 4; i++)
		inventory[i] = NULL;
}

Character::Character() : name("default"){
	// std::cout << "Character constructor\n";
	for (int i = 0; i < 4; i++)
		inventory[i] = NULL;
}

Character::Character(const Character &cp) : name(cp.name){
	// std::cout << "Character copy constructor\n";
	for (int i = 0; i < 4; i++)
	{
		if (cp.inventory[i])
			inventory[i] = cp.inventory[i]->clone(); // deep copy
		else
			inventory[i] = NULL;
	}
}

Character::~Character(){
	for (int i = 0; i < 4; i++){
		if (inventory[i] != NULL){
			delete inventory[i];
			inventory[i] = NULL;
		}
	}
}

Character &Character::operator=(Character const & op){
	if (this != &op){
		name = op.name;
		for (int i = 0; i < 4; i++){
			delete inventory[i];
			if (op.inventory[i])
				inventory[i] = op.inventory[i]->clone(); // deep copy
			else
				inventory[i] = NULL;
		}
	}
	return *this;
}

std::string const & Character::getName() const{
	return (name);
}

void Character::equip(AMateria* m){
	for (int i = 0; i < 4; i++)
	{
		if (inventory[i] == NULL)
		{
			inventory[i] = m;
			return ;
		}
	}
	std::cout << RED << "Materia inventory full\n" << RESET;
	delete m;
}

void Character::unequip(int idx) {
    if (idx >= 0 && idx < 4) {
        inventory[idx] = NULL;
    }
}

void Character::use(int idx, ICharacter& target) {
    if (idx >= 0 && idx < 4 && inventory[idx] != NULL) {
        inventory[idx]->use(target);
		return ;
    }
	if (!(idx >= 0 && idx < 4))
		std::cout << YELLOW << idx << " is a invalid value, the index must be between 0 and 3\n" << RESET;
	else
		std::cout << YELLOW << "The value at " << idx << " in the inventory is empty\n" << RESET;
}