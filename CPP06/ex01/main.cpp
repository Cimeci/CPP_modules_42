/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inowak-- <inowak--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 13:20:44 by inowak--          #+#    #+#             */
/*   Updated: 2025/04/09 19:45:21 by inowak--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Serializer.hpp"

int main(void)
{
	Data data;
	
	data.id = 1;
	data.name = "Ilan";
	std::cout << &data << "|" << data.id << "|" << data.name << std::endl;
	uintptr_t bridge = Serializer::serialize(&data);
	std::cout << &data << "|" << bridge << std::endl;
	Data *res = Serializer::deserialize(bridge);
	std::cout << res << "|" << res->id << "|" << res->name << std::endl;
}