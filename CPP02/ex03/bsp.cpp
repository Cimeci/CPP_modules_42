/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inowak-- <inowak--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 14:27:08 by inowak--          #+#    #+#             */
/*   Updated: 2025/03/13 15:15:59 by inowak--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

float calculateArea(const Point& a, const Point& b, const Point& c) {
    return std::abs(
        (a.getX().toFloat() * (b.getY().toFloat() - c.getY().toFloat()) +
         b.getX().toFloat() * (c.getY().toFloat() - a.getY().toFloat()) +
         c.getX().toFloat() * (a.getY().toFloat() - b.getY().toFloat())) / 2.0f
    );
}

bool bsp( Point const a, Point const b, Point const c, Point const point)
{
    float areaABC = calculateArea(a, b, c);
    
    float areaPAB = calculateArea(point, a, b);
    float areaPBC = calculateArea(point, b, c);
    float areaPCA = calculateArea(point, c, a);

    if ((areaPAB + areaPBC + areaPCA) == areaABC)
        return true;
    return false;
}