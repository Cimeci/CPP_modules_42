/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inowak-- <inowak--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 18:00:56 by inowak--          #+#    #+#             */
/*   Updated: 2025/04/25 15:47:02 by inowak--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "iter.hpp"
# include "colors.hpp"

int main( void ) {

	std::cout << UNDERLINE << "First test: " << RESET << std::endl;
	int array1[10] = {0, 1, 2, 3, 4, 5, 6 ,7, 8, 9};
	iter(array1, 10, funct<const int>);
	std::cout << std::endl;

	std::cout << std::endl;

	std::cout << UNDERLINE << "Second test: " << RESET << std::endl;
	std::string array2[10] = {"hello", "corrector", "I", "hope", "you", "pass", "a", "good", "day", ":)" };
	iter(array2, 10, funct<std::string>);
	std::cout << std::endl;
	
	std::cout << std::endl;
	
	std::cout << UNDERLINE << "Third test: " << RESET << std::endl;
	double array3[10] = {0.0, 1.1, 2.2, 3.3, 4.4, 5.5, 6.6 ,7.7, 8.8, 9.9};
	iter(array3, 10, funct<double>);
	std::cout << std::endl;
}

// #include "iter.hpp"

// class Awesome
// {
//   public:
//     Awesome( void ) : _n( 42 ) { return; }
//     int get( void ) const { return this->_n; }
//   private:
//     int _n;
// };

// std::ostream & operator<<( std::ostream & o, Awesome const & rhs )
// {
//   o << rhs.get();
//   return o;
// }

// template< typename T >
// void print( T& x )
// {
//   std::cout << x << std::endl;
//   return;
// }

// int main() {
//   int tab[] = { 0, 1, 2, 3, 4 };
//   Awesome tab2[5];

//   iter( tab, 5, print<const int> );
//   iter( tab2, 5, print<Awesome> );

//   return 0;
// }