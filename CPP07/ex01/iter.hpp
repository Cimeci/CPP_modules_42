/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inowak-- <inowak--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 10:39:48 by inowak--          #+#    #+#             */
/*   Updated: 2025/04/25 15:45:33 by inowak--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# pragma once 

# include <iostream>

template <typename T, typename Func>

void iter(T *array, int length, Func func){
	for (int i = 0; i < length; i++){
		try{func(array[i]);}
		catch(...){std::cerr << "error\n";}
	}
}

template <typename T>
void funct(T &element){std::cout << element << ", ";}