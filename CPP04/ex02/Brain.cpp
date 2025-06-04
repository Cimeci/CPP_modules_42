/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inowak-- <inowak--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 11:16:35 by inowak--          #+#    #+#             */
/*   Updated: 2025/03/17 11:35:13 by inowak--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Brain.hpp"
# include "colors.hpp"

Brain::Brain(){
    std::cout << PURPLE << "Brain class constructor\n" << RESET;
}

Brain::Brain(const Brain &cp){
    for (int i = 0; i < 100; i++){
        ideas[i] = cp.ideas[i];
    }
}

Brain &Brain::operator=(const Brain &op){
    if (this != &op){
        for (int i = 0; i < 100; i++)
            ideas[i] = op.ideas[i];
    }
    return (*this);
}

Brain::~Brain(){
    std::cout << PURPLE << "Brain class destructor\n" << RESET;
}