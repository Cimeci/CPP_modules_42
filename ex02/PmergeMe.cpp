/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inowak-- <inowak--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 15:51:51 by inowak--          #+#    #+#             */
/*   Updated: 2025/04/24 15:52:58 by inowak--         ###   ########.fr       */
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
	isPair = true;
	if (size % 2 != 0){
		isPair = false;
		loneNumber = Cvector.back();
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

	for (size_t i = 0; i < jaco.size(); ++i){
		if (jaco[i] < n)
			order.push_back(jaco[i]);
	}

	for (size_t i = 0; i < n; ++i){
		if (std::find(order.begin(), order.end(), i) == order.end())
			order.push_back(i);
	}
	return order;
}



template<typename T>
void PmergeMe::sort(T &container){

	std::vector<std::pair<int, int> > pairs;

	size_t i = 0;
	for (; i + 1 < container.size(); i += 2)
	{
		int a = container[i];
		int b = container[i + 1];
		if (a < b)
			std::swap(a, b);
		pairs.push_back(std::make_pair(a, b));
	}
	for (size_t j = 0; j < pairs.size(); ++j)
		std::cout << "(" << pairs[j].first << "," << pairs[j].second << ") ";
	std::cout << std::endl;


	T large;
	T small;
	for (size_t j = 0; j < pairs.size(); ++j){
		DEBUG_PRINT("pairs[j].first");
		DEBUG_PRINT(pairs[j].first);
		large.push_back(pairs[j].first);
		
		DEBUG_PRINT("pairs[j].second");
		DEBUG_PRINT(pairs[j].second);
		small.push_back(pairs[j].second);
	}

	if (!(isSorted(large.begin(), large.end())))
		sort(large);

	std::vector<size_t> insertionOrder = getJacobsthalInsertionOrder(small.size());
	for (size_t i = 0; i < insertionOrder.size(); ++i) {
		int value = small[insertionOrder[i]];
		typename T::iterator pos = std::lower_bound(large.begin(), large.end(), value);
		large.insert(pos, value);
		DEBUG_PRINT_CONTAINER(large);
	}
	if (!isPair && container.size() == Cvector.size()){
		std::cout << "LoneNumber: " << loneNumber << std::endl;
		typename T::iterator pos = std::lower_bound(large.begin(), large.end(), loneNumber);
		large.insert(pos, loneNumber);
	}
		

	container.clear();
	container.insert(container.end(), large.begin(), large.end());
	DEBUG_PAIRS;
	DEBUG_SEPARATION;
}