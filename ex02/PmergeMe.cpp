/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inowak-- <inowak--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 15:51:51 by inowak--          #+#    #+#             */
/*   Updated: 2025/05/27 13:56:42 by inowak--         ###   ########.fr       */
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

	DEBUG_PRINT("\n------------------------------------\n\n");

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
	
	//* n = x - 1 + 2(x - 2) *//
	for (size_t i = 2; i <= n; i++)
		container.push_back(container[i - 1] + 2 * container[i - 2]);
	return container;
}

std::vector<size_t> PmergeMe::getJacobsthalInsertionOrder(size_t n) {
    if (n == 0)
		return std::vector<size_t>();
    
    std::vector<size_t> order;
    std::vector<size_t> jaco = jacobsthal(20);

    //* start by 0 *//
    order.push_back(0);
    if (n == 1)
		return order;
    
    size_t jaco_index = 2;
    
    while (order.size() < n && jaco_index < jaco.size()) {
        size_t limit = std::min(jaco[jaco_index], n - 1);
        size_t start = jaco[jaco_index - 1];
        
		//* Add elements in descending order from limit to start+1 *//
        //* (start is excluded because it belongs to the previous group, except for the first group) *//
        for (size_t i = limit; i > start && order.size() < n; --i)
            order.push_back(i);
        jaco_index++;
    }
    
    return order;
}

template<typename T>
void PmergeMe::sort(T &container) {
    if (container.size() <= 1)
        return;

    T main_chain;
    T pend;
    bool hasOdd = false;
    int loneNumber = -1;

//* 1) Pairs *//

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
			else{
                main_chain.push_back(second);
                pend.push_back(first);
            }
        }
		else{
            hasOdd = true;
            loneNumber = first;
        }
    }

    DEBUG_PRINT("Main chain before recursive sort:");
    DEBUG_PRINT_CONTAINER(main_chain);
    DEBUG_PRINT("Pend before insertion:");
    DEBUG_PRINT_CONTAINER(pend);

//* 2) Recursive sorting main_chain *//

    sort(main_chain);

    DEBUG_PRINT("Main chain after recursive sort:");
    DEBUG_PRINT_CONTAINER(main_chain);

//* 3) Insert pend elements in Jacobsthal order *//

    if (!pend.empty()){
        std::vector<size_t> insertionOrder = getJacobsthalInsertionOrder(pend.size());
        
		DEBUG_PRINT("Jacobsthal insertion order:");
		# ifdef HELP
        	for (size_t i = 0; i < insertionOrder.size(); ++i)
         	   std::cout << insertionOrder[i] << " ";
        	std::cout << std::endl;
		# endif
		
        for (size_t i = 0; i < insertionOrder.size(); ++i){
            size_t index = insertionOrder[i];
            if (index >= pend.size())
                continue;

            int value = pend[index];
            
            //* Binary search for insertion position *//
            typename T::iterator pos = std::lower_bound(main_chain.begin(), main_chain.end(), value);
			# ifdef HELP
           		size_t insertion_index = std::distance(main_chain.begin(), pos);
            # endif
            DEBUG_PRINT("Inserting pend[" << index << "] = " << value << " at position " << insertion_index);
            main_chain.insert(pos, value);
        }
    }

//* 4) Inserting the odd element *//

    if (hasOdd) {
        typename T::iterator pos = std::lower_bound(main_chain.begin(), main_chain.end(), loneNumber);
        # ifdef HELP
			size_t lone_index = std::distance(main_chain.begin(), pos);
		# endif
        DEBUG_PRINT("Inserting odd element " << loneNumber << " at position " << lone_index);
        main_chain.insert(pos, loneNumber);
    }

    container = main_chain;
    
//? Check is sort ?//

    if (!isSorted(container.begin(), container.end())) {
        throw PMERGEMEEXCEPTION("Sorting failed - container is not sorted");
    }
}
