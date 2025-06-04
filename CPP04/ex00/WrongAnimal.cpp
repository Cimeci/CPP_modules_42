/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inowak-- <inowak--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 10:21:27 by inowak--          #+#    #+#             */
/*   Updated: 2025/03/17 10:26:01 by inowak--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal(): type("WrongAnimal"){
    std::cout << "WrongAnimal class constructor\n";
}

WrongAnimal::~WrongAnimal(){
    std::cout << "WrongAnimal class destructor\n";
}

WrongAnimal::WrongAnimal(const WrongAnimal &cp){
    *this = cp;
}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal& op){
    if (this != &op)
        this->type = op.type;
    return (*this);        
}

std::string WrongAnimal::getType(void) const{
    return type;
}

void WrongAnimal::makeSound() const{
	std::cout << "WrongAnimal sound\n";
}