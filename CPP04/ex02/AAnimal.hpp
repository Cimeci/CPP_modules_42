/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inowak-- <inowak--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 09:15:45 by inowak--          #+#    #+#             */
/*   Updated: 2025/03/17 14:19:14 by inowak--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <iostream>

class AAnimal{ 
  
    protected:
        std::string type;

    public:
        AAnimal();
        AAnimal(const AAnimal &cp);
        AAnimal &operator=(const AAnimal& op);
        virtual ~AAnimal();

        std::string getType() const;
        virtual void makeSound() const = 0;
};

#endif