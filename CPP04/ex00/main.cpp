/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inowak-- <inowak--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 09:22:24 by inowak--          #+#    #+#             */
/*   Updated: 2025/03/28 14:34:55 by inowak--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "colors.hpp"

# include "Animal.hpp"
# include "Dog.hpp"
# include "Cat.hpp"

#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main(void)
{   
    std::cout << PURPLE;
    std::cout << "+-----------------------------------+\n";
    std::cout << "|            Classic Part           |\n";
    std::cout << "+-----------------------------------+\n";
    std::cout << RESET;

    const Animal* meta = new Animal();
    const Animal* j = new Dog();
    const Animal* i = new Cat();
    
    std::cout << j->getType() << " " << std::endl;
    std::cout << i->getType() << " " << std::endl;

    i->makeSound();
    j->makeSound();
    meta->makeSound();

    delete meta;
    delete j;
    delete i;
    
    std::cout << ORANGE;
    std::cout << "+-----------------------------------+\n";
    std::cout << "|             Wrong Part            |\n";
    std::cout << "+-----------------------------------+\n";
    std::cout << RESET;
    
    const WrongAnimal* wrong = new WrongAnimal();
    const WrongAnimal* c = new WrongCat();
    
    std::cout << c->getType() << " " << std::endl;

    c->makeSound();
    wrong->makeSound();

    delete wrong;
    delete c;

    return 0;
}