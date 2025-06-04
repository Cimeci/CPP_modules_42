/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inowak-- <inowak--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 19:16:29 by inowak--          #+#    #+#             */
/*   Updated: 2025/04/24 15:41:34 by inowak--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifdef HELP
    #define DEBUG_MODE 1
#else
    #define DEBUG_MODE 0
#endif


#if DEBUG_MODE
	# define DEBUG_PRINT(x) std::cout << BLUE << "[DEBUG] " << RESET <<  x << std::endl;
    # define DEBUG_PRINT_CONTAINER(x) 	std::cout << "Container" << std::endl; for (size_t i = 0; i < x.size(); i++){std::cout << x[i] << std::endl;};
	# define DEBUG_PAIRS for (size_t j = 0; j < pairs.size(); ++j){std::cout << "Pair[" << j << "] = (" << pairs[j].first << ", " << pairs[j].second << ")" << std::endl;};
	# define DEBUG_SEPARATION std::cout << std::endl << "--------------------" << std::endl << std::endl;

#else
	# define DEBUG_PRINT(x)
    # define DEBUG_PRINT_CONTAINER(x)
	# define DEBUG_PAIRS
	# define DEBUG_SEPARATION

#endif