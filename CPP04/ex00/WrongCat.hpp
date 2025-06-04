/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inowak-- <inowak--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 10:27:10 by inowak--          #+#    #+#             */
/*   Updated: 2025/03/28 10:38:24 by inowak--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGCAT_HPP
# define WRONGCAT_HPP

#include "WrongAnimal.hpp"

class WrongCat: public WrongAnimal{

	public:
		WrongCat();
		WrongCat(const WrongCat &cp);
		WrongCat &operator=(const WrongCat& op);
		~WrongCat();

		void makeSound() const;
};

#endif