/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   macro.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inowak-- <inowak--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 10:32:01 by inowak--          #+#    #+#             */
/*   Updated: 2025/04/18 15:55:56 by inowak--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# define ERROR_FORMAT std::cout << RED << "[ERROR]" << RESET << "./PmergeMe nb nb nb nb nb nb ..." << std::endl; return 1
# define ERROR_INPUT std::cout << RED << "[ERROR]" << RESET << e.what() << " is a invalid number" << std::endl; return 1
# define ERROR_CALCUL std::cout << RED << "[ERROR]" << RESET << "calcul: " << e.what() << std::endl
