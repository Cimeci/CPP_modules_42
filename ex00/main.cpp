/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inowak-- <inowak--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 18:00:56 by inowak--          #+#    #+#             */
/*   Updated: 2025/04/16 17:20:15 by inowak--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "BitcoinExchange.hpp"
# include "colors.hpp"

int main(int argc, char **argv)
{
	if (argc != 2){ERROR_FORMAT;}

	std::string file = argv[1];

	// if (file.find(".csv", file.size() - 4) == std::string::npos){ERROR_EXTENSION;}

	BitcoinExchange btc;

	btc.process(file);
}