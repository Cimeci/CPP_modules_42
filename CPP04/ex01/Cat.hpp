/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inowak-- <inowak--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 09:20:57 by inowak--          #+#    #+#             */
/*   Updated: 2025/03/28 14:35:55 by inowak--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP

# include "Animal.hpp"
# include "Brain.hpp"

class Cat: public Animal{
   
    private:
        Brain* brain;

    public:
        Cat();
        Cat(const Cat &cp);
        Cat &operator=(const Cat& op);
        ~Cat();

        void makeSound() const;
        Brain   *getBrain();
};

#endif