/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inowak-- <inowak--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 10:55:16 by inowak--          #+#    #+#             */
/*   Updated: 2025/03/28 14:35:29 by inowak--         ###   ########.fr       */
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

        std::string getIdea(int idx) const;
        void setIdea(int index, const std::string& idea);
};

#endif