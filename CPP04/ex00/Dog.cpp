/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inowak-- <inowak--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 09:23:44 by inowak--          #+#    #+#             */
/*   Updated: 2025/03/17 10:43:43 by inowak--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Dog.hpp"
# include "colors.hpp"

Dog::Dog(){
    type = "Dog";
	std::cout << GREEN << "Dog class constructor\n" << RESET;
}

Dog::~Dog(){
	std::cout << GREEN << "Dog class destructor\n" << RESET;
}

Dog::Dog(const Dog &cp){
	*this = cp;
}

Dog &Dog::operator=(const Dog& op){
	if (this != &op)
        Animal::operator=(op);
	return (*this);        
}

void Dog::makeSound() const {
	std::cout << GREEN << "WOOOOOOOFFFF !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\n" << RESET;
}