/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inowak-- <inowak--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 10:55:16 by inowak--          #+#    #+#             */
/*   Updated: 2025/03/17 11:00:56 by inowak--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
# define BRAIN_HPP

# include <iostream>

class Brain{
    
    protected:
        std::string ideas[100];

    public:
        Brain();
        Brain(const Brain &cp);
        Brain &operator=(const Brain &op);
        ~Brain();
};

#endif