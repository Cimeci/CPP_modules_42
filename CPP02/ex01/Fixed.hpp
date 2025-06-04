/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inowak-- <inowak--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 08:45:52 by inowak--          #+#    #+#             */
/*   Updated: 2025/03/13 17:47:28 by inowak--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <cmath>

class Fixed{
  
	private:
		int fix;
		static const int nb;

	public:
		Fixed();
		Fixed(const Fixed &a);
		Fixed &operator=(const Fixed& op);
		~Fixed();

		int getRawBits( void ) const;
		void setRawBits( int const raw );

		Fixed(int const nb_int);
		Fixed(float const nb_float);

		
		float	toFloat( void ) const;
		int		toInt( void ) const;
	};
	std::ostream& operator<<(std::ostream& os, const Fixed& obj);

#endif