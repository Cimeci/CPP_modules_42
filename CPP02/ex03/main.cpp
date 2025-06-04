/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inowak-- <inowak--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 08:46:42 by inowak--          #+#    #+#             */
/*   Updated: 2025/03/13 17:31:33 by inowak--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include "Point.hpp"

int main( void ) {
    
    Point a(0, 0);
    Point b(20, 0);
    Point c(40, 40);
    Point p(10, 10);
    bool res = bsp(a, b, c, p);
    std::cout << "    x | y\n";
    std::cout << "-------------\n";
    std::cout << "a : " << a.getX() << " | " << a.getY() << std::endl;
    std::cout << "b : " << b.getX() << " | " << b.getY() << std::endl;
    std::cout << "c : " << c.getX() << " | " << c.getY() << std::endl;
    std::cout << "-------------\n";
    std::cout << "p : " << p.getX() << " | " << p.getY() << std::endl;
    std::cout << "-------------\n";
    if (res == true)
        std::cout << "point IN the triangle\n";
    else
        std::cout << "point OUT the triangle\n";
    return 0;
}