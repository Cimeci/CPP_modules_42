/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inowak-- <inowak--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 09:22:24 by inowak--          #+#    #+#             */
/*   Updated: 2025/03/17 14:18:32 by inowak--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "colors.hpp"

# include "AAnimal.hpp"
# include "Dog.hpp"
# include "Cat.hpp"

int main(void)
{
    const int size = 10;

    AAnimal* animal[size];

    for (int i = 0; i < size; i++)
    {
        if (i < size / 2)
            animal[i] = new Dog();
        else
            animal[i] = new Cat();
    }

    for (int i = 0; i < size; i++){
        animal[i]->makeSound();
    }
    
    for (int i = 0; i < size; i++){
        delete animal[i];
    }

    return 0;
}