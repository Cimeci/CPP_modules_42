/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inowak-- <inowak--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 14:30:45 by inowak--          #+#    #+#             */
/*   Updated: 2025/03/13 16:25:06 by inowak--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point(): x(0), y(0){}

Point::Point(const float a, const float b): x(a), y(b){}

Point::Point(Point &cp){
	*this = cp;
}

Point &Point::operator=(const Point& op){
	const_cast<Fixed&>(x) = op.getX();
	const_cast<Fixed&>(y) = op.getY();
	return *this;
}

Point::~Point(){}

Fixed Point::getX() const{
	return x;
}

Fixed Point::getY() const{
	return y;
}
