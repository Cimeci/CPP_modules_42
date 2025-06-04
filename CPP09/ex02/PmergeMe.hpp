/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inowak-- <inowak--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 15:47:42 by inowak--          #+#    #+#             */
/*   Updated: 2025/05/26 17:19:26 by inowak--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# pragma once

# include "debug.hpp"

# include "colors.hpp"
# include "macro.hpp"

# include <iostream>
# include <vector>
# include <deque>
# include <algorithm>
# include <ctime>
# include <iomanip>
# include <limits>
# include <set>

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
		std::vector<int> Cvector;
		std::deque<int> Cdeque;

		clock_t Vstart;
		clock_t Dstart;

		size_t size;

		std::vector<size_t> jacobsthal(size_t n);
		std::vector<size_t> getJacobsthalInsertionOrder(size_t n);

		void loadContainer(char **argv);
		void isValid(const std::string nb) const;

		template<typename T>
		void sort(T &container);

	public:
		PmergeMe();
		PmergeMe(const PmergeMe &cp);
		PmergeMe &operator=(const PmergeMe &op);
		~PmergeMe();

		void process(char **argv);
};
