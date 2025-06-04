/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inowak-- <inowak--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 08:46:27 by inowak--          #+#    #+#             */
/*   Updated: 2025/03/14 10:45:08 by inowak--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

// ex 00 //

const int Fixed::nb = 8;

Fixed::Fixed(){
	fix = 0;
}

Fixed::Fixed(const Fixed &a){
	*this = a;
}

Fixed& Fixed::operator=(const Fixed& op) {
	if (this != &op)
		fix = op.fix;
	return (*this);  
}

Fixed::~Fixed(){
}

int Fixed::getRawBits(void) const{
	return (fix); 
}

void Fixed::setRawBits( int const raw ){
	fix = raw;    
}

Fixed::Fixed(int const nb_int){
	fix = nb_int << nb;	
}

Fixed::Fixed(float const nb_float){
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

// ex02

bool Fixed::operator>(const Fixed &comp){
	return (fix > comp.fix);
}

bool Fixed::operator<(const Fixed &comp){
	return (fix < comp.fix);
}

bool Fixed::operator>=(const Fixed &comp){
	return (fix >= comp.fix);
}

bool Fixed::operator<=(const Fixed &comp){
	return (fix <= comp.fix);
}

bool Fixed::operator==(const Fixed &comp){
	return fix == comp.fix;
}

bool Fixed::operator!=(const Fixed &comp){
	return !(fix == comp.fix);
}

Fixed Fixed::operator+(const Fixed &comp){
	Fixed c;
	c.setRawBits(getRawBits() + comp.getRawBits());
	return c;
}

Fixed Fixed::operator-(const Fixed &comp){
	Fixed c;
	c.setRawBits(getRawBits() - comp.getRawBits());
	return c;
}

Fixed Fixed::operator*(const Fixed &comp){
	Fixed c;
	c.setRawBits((getRawBits() * comp.getRawBits()) >> nb);
	return c;
}

Fixed Fixed::operator/(const Fixed &comp){
	Fixed c;
	c.setRawBits((getRawBits() << nb) / comp.getRawBits());
	return c;
}

Fixed& Fixed::operator++(void){
	++fix;
	return *this;
}

Fixed Fixed::operator++(int){
	Fixed tmp = *this;
	++fix;
	return tmp;
}

Fixed& Fixed::operator--(void){
	--fix;
	return *this;
}

Fixed Fixed::operator--(int){
	Fixed tmp = *this;
	--fix;
	return tmp;
}

Fixed Fixed::min(Fixed &a, Fixed &b)
{
	if (a.fix < b.fix)
		return (a);
	return (b);
}

Fixed Fixed::min(const Fixed &a, const Fixed &b)
{
	if (a.fix < b.fix)
		return (a);
	return (b);
}

Fixed Fixed::max(Fixed &a, Fixed &b)
{
	if (a.fix < b.fix)
		return (b);
	return (a);
}

Fixed Fixed::max(const Fixed &a, const Fixed &b)
{
	if (a.fix < b.fix)
		return (b);
	return (a);
}