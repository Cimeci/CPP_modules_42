/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inowak-- <inowak--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 11:20:49 by inowak--          #+#    #+#             */
/*   Updated: 2025/03/28 10:27:38 by inowak--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Cure.hpp"

Cure::Cure() : AMateria("cure"){
    // std::cout << "Cure constructor\n";
}

Cure::Cure(const Cure &cp){
    // std::cout << "Cure copy constructor\n";
    *this = cp;
}

Cure &Cure::operator=(const Cure &op){
    // std::cout << "Cure assignement operator\n";
    if (this != &op)
        type = op.type;
    return (*this); 
}

Cure::~Cure(){
    // std::cout << "Cure destructor\n";p
}

Cure* Cure::clone() const {
    return new Cure(*this); // deep copy
}

void Cure::use(ICharacter& target) {
    std::cout << ORANGE << "CURE USE " << RESET << "* heals " << target.getName() << "'s wounds *\n";
}