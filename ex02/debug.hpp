/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inowak-- <inowak--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 19:16:29 by inowak--          #+#    #+#             */
/*   Updated: 2025/04/17 16:39:16 by inowak--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifdef HELP
    #define DEBUG_MODE 1
#else
    #define DEBUG_MODE 0
#endif


#if DEBUG_MODE
    # define DEBUG_NBSTACK 	std::cout << std::endl << "nbStack" << std::endl;std::stack<long double> tmp1 = nbStack;while (!tmp1.empty()) {std::cout << tmp1.top() << std::endl;tmp1.pop();};
    # define DEBUG_OPSTACK 	std::cout << std::endl << "opStack" << std::endl;std::stack<std::string> tmp2 = opStack;while (!tmp2.empty()) {std::cout << tmp2.top() << std::endl;tmp2.pop();};
	# define DEBUG_CALCUL std::cout << nb1 << opStack.top() << nb2 << std::endl;

	# define DEBUG_SEPARATION std::cout << std::endl << "--------------------" << std::endl << std::endl;

#else
    # define DEBUG_NBSTACK
	# define DEBUG_OPSTACK 
	# define DEBUG_CALCUL
	# define DEBUG_SEPARATION

#endif