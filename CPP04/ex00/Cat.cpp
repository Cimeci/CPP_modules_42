/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inowak-- <inowak--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 09:23:44 by inowak--          #+#    #+#             */
/*   Updated: 2025/03/17 10:44:02 by inowak--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Cat.hpp"
# include "colors.hpp"

Cat::Cat(){
	type = "Cat";
	std::cout << BLUE << "Cat class constructor\n" << RESET;
}

Cat::~Cat(){
	std::cout << BLUE << "Cat class destructor\n" << RESET;
}

Cat::Cat(const Cat &cp){
	*this = cp;
}

Cat &Cat::operator=(const Cat& op){
	if (this != &op)
		Animal::operator=(op);
	return (*this);        
}

void Cat::makeSound() const {
	std::cout << BLUE << "MIAOUUUUUUUU !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\n" << RESET;
}