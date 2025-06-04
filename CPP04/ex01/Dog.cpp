/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inowak-- <inowak--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 09:23:44 by inowak--          #+#    #+#             */
/*   Updated: 2025/03/28 15:43:13 by inowak--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Dog.hpp"
# include "colors.hpp"

Dog::Dog(){
	brain = new Brain();
	type = "Dog";
	std::cout << GREEN << "Dog class constructor\n" << RESET;
}

Dog::~Dog(){
	delete brain;
	std::cout << GREEN << "Dog class destructor\n" << RESET;
}

Dog::Dog(const Dog &cp): Animal (cp){
	brain = new Brain(*cp.brain);	
}

Dog &Dog::operator=(const Dog& op){
	if (this != &op){
		Animal::operator=(op);
		*brain = *op.brain;
	}
	return (*this);        
}

void Dog::makeSound() const {
	std::cout << GREEN << "WOOOOOOOFFFF !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\n" << RESET;
}

Brain *Dog::getBrain(){
	return (brain);
}