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

# define ERROR_FORMAT std::cerr << RED << "[ERROR] " << RESET << "./RPN \"expression\"" << std::endl; return 1
# define ERROR_PROCESS std::cerr << RED << "[ERROR] " << RESET << e.what() << std::endl; return 1;
