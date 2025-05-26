/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inowak-- <inowak--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 15:51:51 by inowak--          #+#    #+#             */
/*   Updated: 2025/05/26 17:20:34 by inowak--         ###   ########.fr       */
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
	for (size_t i = 0; i < Cvector.size(); i++)
		std::cout << Cvector[i] << " ";
	std::cout << std::endl;

	try{
		Vstart = clock();
		DEBUG_PRINT_CONTAINER(Cvector);
		DEBUG_SEPARATION;
		sort(Cvector);
	}
	catch(PMERGEMEEXCEPTION &e){ERROR_SORT;}

	std::cout << std::endl << "------------------------------------\n" << std::endl;

	try{
		Dstart = clock();
		DEBUG_PRINT_CONTAINER(Cdeque);;
		DEBUG_SEPARATION;
		sort(Cdeque);
	}
	catch(PMERGEMEEXCEPTION &e){ERROR_SORT;}

	std::cout << "After: "; 
	for (size_t i = 0; i < Cvector.size(); i++)
		std::cout << Cvector[i] << " ";
	std::cout << std::endl;

	clock_t printTime = clock();
	double Vduration_us = 100000.0 * (Dstart - Vstart) / CLOCKS_PER_SEC;
	double Dduration_us = 100000.0 * (printTime - Dstart) / CLOCKS_PER_SEC;
	std::cout << "Time to process a range of " << size << " elements with std::[vector] : " << std::setprecision(10) << Vduration_us << " us" << std::endl;
	std::cout << "Time to process a range of " << size << " elements with std::[deque] : " << std::setprecision(10) << Dduration_us << " us" << std::endl;
}

//* --------- // UTILS | PRIVATE // --------- *//

void PmergeMe::loadContainer(char **argv){

	size = 0;
	for (int i = 1; argv[i]; i++)
	{
		size++;
		isValid(std::string(argv[i]));
		Cvector.push_back(std::atoi(argv[i]));
		Cdeque.push_back(std::atoi(argv[i]));
	}
}

void PmergeMe::isValid(const std::string nb) const{
	for (size_t i = 0; i < nb.size(); i++){
		if (!isdigit(nb[i]))
			throw PMERGEMEEXCEPTION("invalid input: " + nb);
	}
}

template<typename Iterator>
bool isSorted(Iterator begin, Iterator end){
	if (begin == end)
		return true;
	
	Iterator next = begin;
	++next;
	while (next != end)
	{
		if (*next < *begin)
			return false;
		++begin;
		++next;
	}
	return true;
}

//* --------- // SORT | PRIVATE // --------- *//

std::vector<size_t> PmergeMe::jacobsthal(size_t n){
	std::vector<size_t> container;

	container.push_back(0);
	container.push_back(1);
	
	for (size_t i = 2; i <= n; i++)
	{
		container.push_back(container[i - 1] + 2 * container[i - 2]);
	}
	return container;
}

std::vector<size_t> PmergeMe::getJacobsthalInsertionOrder(size_t n){
	std::vector<size_t> order;
	std::vector<size_t> jaco = jacobsthal(n);
	std::set<size_t> seen;  // pour garder trace des indices déjà ajoutés

	for (size_t i = 0; i < jaco.size(); ++i){
		if (jaco[i] < n && seen.find(jaco[i]) == seen.end()) {
			order.push_back(jaco[i]);
			seen.insert(jaco[i]);
		}
	}

	for (size_t i = 0; i < n; ++i){
		if (seen.find(i) == seen.end()) {
			order.push_back(i);
			seen.insert(i);
		}
	}
	return order;
}


template<typename T>
void PmergeMe::sort(T &container){
    if (container.size() <= 1)
        return;

    T main_chain;
    T pend;
    bool isPair = true;
    int loneNumber = -1;

    typename T::iterator it = container.begin();
    while (it != container.end()){
        int first = *it;
        ++it;
        if (it != container.end()){
            int second = *it;
            ++it;

            if (first > second){
                main_chain.push_back(first);
                pend.push_back(second);
            }
			else {
                main_chain.push_back(second);
                pend.push_back(first);
            }
        }
		else {
            isPair = false;
            loneNumber = first;
        }
    }

    sort(main_chain);

    std::vector<size_t> insertionOrder = getJacobsthalInsertionOrder(pend.size());

    for (std::vector<size_t>::iterator it = insertionOrder.begin(); it != insertionOrder.end(); ++it){
        size_t index = *it;
        if (index >= pend.size())
            continue;
        int value = pend[index];

        typename T::iterator pos = std::lower_bound(main_chain.begin(), main_chain.end(), value);
		size_t insertion_index = std::distance(main_chain.begin(), pos);
		std::cout << "insert: " << value << " at index " << insertion_index << std::endl;
		main_chain.insert(pos, value);
		
    }

	if (!isPair){
		typename T::iterator pos = std::lower_bound(main_chain.begin(), main_chain.end(), loneNumber);
		size_t lone_index = std::distance(main_chain.begin(), pos);
		std::cout << "Impair, insert: " << loneNumber << " at index " << lone_index << std::endl;
		main_chain.insert(pos, loneNumber);		
	}
	

    container = main_chain;
}
