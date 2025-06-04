/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inowak-- <inowak--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 18:00:56 by inowak--          #+#    #+#             */
/*   Updated: 2025/05/26 17:16:11 by inowak--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "PmergeMe.hpp"

int main(int argc, char **argv)
{
	if (argc < 2){ERROR_FORMAT;}

	PmergeMe pmerge;

	pmerge.process(argv);
}