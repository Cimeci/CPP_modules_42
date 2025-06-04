/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inowak-- <inowak--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 09:23:44 by inowak--          #+#    #+#             */
/*   Updated: 2025/03/17 09:56:22 by inowak--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Animal.hpp"

Animal::Animal(): type("Animal"){
    std::cout << "Animal class constructor\n";
}

Animal::~Animal(){
    std::cout << "Animal class destructor\n";
}

Animal::Animal(const Animal &cp){
    *this = cp;
}

Animal &Animal::operator=(const Animal& op){
    if (this != &op)
        this->type = op.type;
    return (*this);        
}

std::string Animal::getType(void) const{
    return type;
}

void Animal::makeSound() const{
	std::cout << "Animal sound\n";
}