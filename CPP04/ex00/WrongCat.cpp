/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inowak-- <inowak--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 10:26:46 by inowak--          #+#    #+#             */
/*   Updated: 2025/03/17 10:43:22 by inowak--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "WrongCat.hpp"
# include "colors.hpp"

WrongCat::WrongCat(){
	type = "WrongCat";
	std::cout << RED << "WrongCat class constructor\n" << RESET;
}

WrongCat::~WrongCat(){
	std::cout << RED << "WrongCat class destructor\n" << RESET;
}

WrongCat::WrongCat(const WrongCat &cp){
	*this = cp;
}

WrongCat &WrongCat::operator=(const WrongCat& op){
	if (this != &op)
		WrongAnimal::operator=(op);
	return (*this);        
}

void WrongCat::makeSound() const {
	std::cout << RED << "WRONG MIAOUUUUUUUU !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\n" << RESET;
}