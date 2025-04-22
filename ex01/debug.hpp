/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inowak-- <inowak--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 19:16:29 by inowak--          #+#    #+#             */
/*   Updated: 2025/04/22 15:37:07 by inowak--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifdef HELP
    #define DEBUG_MODE 1
#else
    #define DEBUG_MODE 0
#endif


#if DEBUG_MODE
    # define DEBUG_PRINT(x) std::cout << BLUE << "[DEBUG] " << RESET <<  x << std::endl;
    # define DEBUG_STACK std::cout << BLUE << "[DEBUG] " << RESET << std::endl << "stack" << std::endl;std::stack<double> tmp1 = stack;while (!tmp1.empty()) {std::cout << tmp1.top() << std::endl;tmp1.pop();}std::cout << std::endl;
	# define DEBUG_CALCUL std::cout << BLUE << "[DEBUG] " << RESET << nb1 << opStack.top() << nb2 << std::endl;
    # define DEBUG_SEPARATION std::cout << std::endl << "--------------------" << std::endl << std::endl;

#else
    # define DEBUG_PRINT(x)
    # define DEBUG_STACK
	# define DEBUG_CALCUL
	# define DEBUG_SEPARATION

#endif