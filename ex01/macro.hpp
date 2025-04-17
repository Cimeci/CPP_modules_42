/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   macro.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inowak-- <inowak--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 10:32:01 by inowak--          #+#    #+#             */
/*   Updated: 2025/04/17 14:34:08 by inowak--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# define ERROR_FORMAT std::cout << RED << "[ERROR]" << RESET << "./RPN \"expression\"" << std::endl; return 1
# define ERROR_LOADSTACK std::cout << RED << "[ERROR]" << RESET << "loadStack: " << e.what() << std::endl
# define ERROR_CALCUL std::cout << RED << "[ERROR]" << RESET << "calcul: " << e.what() << std::endl
