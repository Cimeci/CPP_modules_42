/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inowak-- <inowak--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 15:47:42 by inowak--          #+#    #+#             */
/*   Updated: 2025/04/18 16:24:09 by inowak--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# pragma once

# include "debug.hpp"

# include "colors.hpp"
# include "macro.hpp"

# include <iostream>
# include <vector>
# include <algorithm>

class PMERGEMEEXCEPTION : public std::exception {
	private:
		std::string _msg;
	public:
		PMERGEMEEXCEPTION(const std::string& msg);
		virtual const char* what() const throw();
		virtual ~PMERGEMEEXCEPTION() throw();
};

class PmergeMe{
	private:
		
		void loadContainer(const char **argv) const;
		bool isValid(const std::string nb) const;

	public:
		PmergeMe();
		PmergeMe(const PmergeMe &cp);
		PmergeMe &operator=(const PmergeMe &op);
		~PmergeMe();

		void process(const char **argv);
};

