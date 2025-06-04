/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inowak-- <inowak--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 09:22:24 by inowak--          #+#    #+#             */
/*   Updated: 2025/03/28 15:59:45 by inowak--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "colors.hpp"

# include "Animal.hpp"
# include "Dog.hpp"
# include "Cat.hpp"

int main(void)
{
    const int size = 10;

    Animal* animal[size];

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

    std::cout << "\n=== START ===" << std::endl;
    std::cout << "\n=== Testing deep copy for Dog ===" << 
    
    std::endl;
    Dog originalDog;
    originalDog.getBrain()->setIdea(0, "I want to chase cats");
    originalDog.getBrain()->setIdea(1, "I love bones");
    
    Dog copyDog = originalDog;
    
    std::cout << "adress : " << originalDog.getBrain() <<  "| Original dog idea 0: " << originalDog.getBrain()->getIdea(0) << std::endl;
    std::cout << "adress : " << copyDog.getBrain() << "| Copy     dog idea 0: " << copyDog.getBrain()->getIdea(0) << std::endl;
    
    copyDog.getBrain()->setIdea(0, "I want to sleep");
    std::cout << "After modification:" << std::endl;
    std::cout << "adress : " << originalDog.getBrain() << "| Original dog idea 0: " << originalDog.getBrain()->getIdea(0) << std::endl;
    std::cout << "adress : " << copyDog.getBrain() << "| Copy     dog idea 0: " << copyDog.getBrain()->getIdea(0) << std::endl;
    
    std::cout << "\n=== Testing deep copy for Cat ===" << std::endl;
    Cat originalCat;
    originalCat.getBrain()->setIdea(0, "I want to sleep all day");
    originalCat.getBrain()->setIdea(1, "Humans are my servants");
    
    Cat copyCat = originalCat;

    std::cout << "adress : " << originalCat.getBrain() << "| Original cat idea 0: " << originalCat.getBrain()->getIdea(0) << std::endl;
    std::cout << "adress : " << copyCat.getBrain() << "| Copy     cat idea 0: " << copyCat.getBrain()->getIdea(0) << std::endl;
    
    copyCat.getBrain()->setIdea(0, "I want to eat fish");
    std::cout << "After modification:" << std::endl;
    std::cout << "adress : " << originalCat.getBrain() << "| Original cat idea 0: " << originalCat.getBrain()->getIdea(0) << std::endl;
    std::cout << "adress : " << copyCat.getBrain() << "| Copy     cat idea 0: " << copyCat.getBrain()->getIdea(0) << std::endl;

    std::cout << "\n=== END ===\n" << std::endl;

    return 0;
}