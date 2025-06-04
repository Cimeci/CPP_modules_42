/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inowak-- <inowak--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 08:46:27 by inowak--          #+#    #+#             */
/*   Updated: 2025/03/13 17:47:26 by inowak--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

// ex 00 //

const int Fixed::nb = 8;

Fixed::Fixed(){
	std::cout << "Default constructor called\n";
	fix = 0;
}

Fixed::Fixed(const Fixed &a){
	std::cout << "Copy constructor called\n";
	*this = a;
}

Fixed& Fixed::operator=(const Fixed& op) {
	std::cout << "Copy assignment operator called\n";
	if (this != &op)
		fix = op.fix;
	return (*this);  
}

Fixed::~Fixed(){
	std::cout << "Destructor called\n";
}

int Fixed::getRawBits(void) const{
	std::cout << "getRawBits member function called\n";
	return (fix); 
}

void Fixed::setRawBits( int const raw ){
	fix = raw;    
}

Fixed::Fixed(int const nb_int){
	std::cout << "Int constructor called\n";
	fix = nb_int << nb;	
}

Fixed::Fixed(float const nb_float){
	std::cout << "Float constructor called\n";
	fix = static_cast<int>(roundf(nb_float * (1 << nb)));
}

float	Fixed::toFloat(void) const{
	return (static_cast<float>(fix) / (1 << nb));
}

int	Fixed::toInt(void) const{
	return (fix >> nb);
}

std::ostream& operator<<(std::ostream& os, const Fixed& obj){
	os << obj.toFloat();
	return (os);
}