/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inowak-- <inowak--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 19:16:29 by inowak--          #+#    #+#             */
/*   Updated: 2025/04/16 19:21:13 by inowak--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifdef HELP
    #define DEBUG_MODE 1
#else
    #define DEBUG_MODE 0
#endif


#if DEBUG_MODE
    # define DEBUG_DATE std::cout << GREEN <<  "real date in the database " << date << RESET << std::endl

#else
    #define DEBUG_DATE

#endif