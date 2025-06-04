/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inowak-- <inowak--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 09:23:44 by inowak--          #+#    #+#             */
/*   Updated: 2025/03/17 14:20:42 by inowak--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Cat.hpp"
# include "colors.hpp"

Cat::Cat(){
	brain = new Brain();
	type = "Cat";
	std::cout << BLUE << "Cat class constructor\n" << RESET;
}

Cat::~Cat(){
	delete brain;
	std::cout << BLUE << "Cat class destructor\n" << RESET;
}

Cat::Cat(const Cat &cp): AAnimal (cp){
	brain = new Brain(*cp.brain);	
}

Cat &Cat::operator=(const Cat& op){
	if (this != &op){
		AAnimal::operator=(op);
		*brain = *op.brain;
	}
	return (*this);        
}

void Cat::makeSound() const {
	std::cout << BLUE << "MIAOUUUUUUUU !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\n" << RESET;
}