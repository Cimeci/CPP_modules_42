/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inowak-- <inowak--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 15:51:51 by inowak--          #+#    #+#             */
/*   Updated: 2025/04/18 16:42:54 by inowak--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "PmergeMe.hpp"

//* PMERGEME EXCEPTION *//

PMERGEMEEXCEPTION::PMERGEMEEXCEPTION(const std::string& msg) : _msg(msg) {}

const char* PMERGEMEEXCEPTION::what() const throw() {
	return _msg.c_str();
}

PMERGEMEEXCEPTION::~PMERGEMEEXCEPTION() throw() {}


//* --------- // CANONICAL FORM // --------- *//

PmergeMe::PmergeMe(){}

PmergeMe::PmergeMe(const PmergeMe &cp){ *this = cp; }

PmergeMe &PmergeMe::operator=(const PmergeMe &op){
	if (this != &op){
		Cvector = op.Cvector;
		Cdeque = op.Cdeque;
		Vstart = op.Vstart;
		Dstart = op.Dstart;
		size = op.size;
	}
	return *this;
}

PmergeMe::~PmergeMe(){}

//* --------- // ALGORITHM | PUBLIC // --------- *//

void PmergeMe::process(char **argv){
	
	try{loadContainer(argv);}
	catch(PMERGEMEEXCEPTION &e){ERROR_INPUT;}

	std::cout << "Before: "; 
	for (size_t i = 1; argv[i]; i++)
		std::cout << argv[i] << " ";
	std::cout << std::endl;

	try{
		Vstart = std::time(0);
		sort(Cvector);
	}
	catch(PMERGEMEEXCEPTION &e){ERROR_SORT;}

	try{
		Dstart = std::time(0);
		sort(Cdeque);
	}
	catch(PMERGEMEEXCEPTION &e){ERROR_SORT;}

	std::cout << "After: "; 
	for (size_t i = 1; argv[i]; i++)
		std::cout << argv[i] << " ";
	std::cout << std::endl;

	std::time_t printTime = std::time(0);
	std::cout << "Time to process a range of " << size << " elements with std::[vector] : " << printTime - Vstart << " us";
	std::cout << "Time to process a range of " << size << " elements with std::[deque] : " << printTime - Dstart << " us";
}

//* --------- // ALGORITHM | PRIVATE // --------- *//

void PmergeMe::loadContainer(char **argv){

	for (int i = 1; argv[i]; i++)
	{
		isValid(std::string(argv[i]));
		Cvector.push_back(std::atoi(argv[i]));
		Cdeque.push_back(std::atoi(argv[i]));
		size++;
	}
}


void PmergeMe::isValid(const std::string nb) const{
	for (size_t i = 0; i < nb.size(); i++){
		if (!isdigit(nb[i]))
			throw PMERGEMEEXCEPTION("invalid input: " + nb);
	}
}

template<typename T>
void PmergeMe::sort(T container){
	for (size_t i = 0; i < container.size(); i++)
}