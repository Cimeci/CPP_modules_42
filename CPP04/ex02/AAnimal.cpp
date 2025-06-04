/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inowak-- <inowak--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 09:23:44 by inowak--          #+#    #+#             */
/*   Updated: 2025/03/17 14:17:56 by inowak--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "AAnimal.hpp"

AAnimal::AAnimal(): type("AAnimal"){
    std::cout << "AAnimal class constructor\n";
}

AAnimal::~AAnimal(){
    std::cout << "AAnimal class destructor\n";
}

AAnimal::AAnimal(const AAnimal &cp){
    *this = cp;
}

AAnimal &AAnimal::operator=(const AAnimal& op){
    if (this != &op)
        this->type = op.type;
    return (*this);        
}

std::string AAnimal::getType(void) const{
    return type;
}

void AAnimal::makeSound() const{
	std::cout << "AAnimal sound\n";
}