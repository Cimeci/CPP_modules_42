/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inowak-- <inowak--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 10:31:16 by inowak--          #+#    #+#             */
/*   Updated: 2025/04/18 15:46:29 by inowak--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "RPN.hpp"

//* RPN EXCEPTION *//

RPNEXCEPTION::RPNEXCEPTION(const std::string& msg) : _msg(msg) {}

const char* RPNEXCEPTION::what() const throw() {
	return _msg.c_str();
}

RPNEXCEPTION::~RPNEXCEPTION() throw() {}


//* --------- // CANONICAL FORM // --------- *//

RPN::RPN(){}

RPN::RPN(const RPN &cp){ *this = cp; }

RPN &RPN::operator=(const RPN &op){
	if (this != &op)
		nbStack = op.nbStack;
	return *this;
}

RPN::~RPN(){}

//* --------- // ALGORITHM | PUBLIC // --------- *//

void RPN::process(const std::string input) {
	try {loadStack(input);}
	catch (RPNEXCEPTION &e){ERROR_LOADSTACK;}
	
	DEBUG_NBSTACK;
	DEBUG_OPSTACK;

	try {calcul();}
	catch (RPNEXCEPTION &e){ERROR_CALCUL;}
}

//* --------- // ALGORITHM | PRIVATE // --------- *//

std::string reverseString(const std::string& input) {
	std::string reversed;
	for (int i = input.length() - 1; i >= 0; --i) {
		reversed += input[i];
	}
	return reversed;
}

void RPN::loadStack(const std::string &input){

	std::string res;
	size_t savepos;
	std::string rev  = reverseString(input);

	if (rev.find(" ") == std::string::npos)
		throw RPNEXCEPTION("no space");

	res = rev.substr(0, rev.find(" "));
	if (res == "+" || res == "-" || res == "/" || res == "*"){
		opStack.push(res);
	}
	else if (std::atoi(res.c_str()) >= 0 && std::atoi(res.c_str()) <= 9){
		nbStack.push(std::atoi(res.c_str()));
	}
	savepos = rev.find(" ");
	for (size_t i = 0; i <= rev.size(); i++)
	{
		size_t newsave = rev.find(" ", savepos + 1);
		if (newsave == std::string::npos)
			break;
		res = rev.substr(savepos + 1, newsave - savepos - 1);
		if (res == "+" || res == "-" || res == "/" || res == "*"){
			opStack.push(res);
		}
		else if (std::atoi(res.c_str()) >= 0 && std::atoi(res.c_str()) <= 9){
			nbStack.push(std::atoi(res.c_str()));
		}
		else
			throw RPNEXCEPTION(res + " is invalid");
		savepos = newsave;
	}
	// après la boucle for
	res = rev.substr(savepos + 1);
	if (!res.empty())
	{
		if (res == "+" || res == "-" || res == "/" || res == "*"){
			opStack.push(res);
		}
		else if (std::atoi(res.c_str()) >= 0 && std::atoi(res.c_str()) <= 9){
			nbStack.push(std::atoi(res.c_str()));
		}
		else
			throw RPNEXCEPTION(res + " is invalid");
	}
}

void RPN::calcul(){
	double nb1;
	double nb2;
	std::string op[4] = {"+", "-", "/", "*"};

	while ((opStack.size() != 0) && (nbStack.size() != 1))
	{
		size_t j = 0;
		while (j < 4 && op[j] != opStack.top())
			j++;
		nb1 = nbStack.top();
		nbStack.pop();
		nb2 = nbStack.top();
		nbStack.pop();
		DEBUG_SEPARATION
		DEBUG_CALCUL
		opStack.pop();
		switch (j){
			case 0: nbStack.push(nb1 + nb2);break;
			case 1: nbStack.push(nb1 - nb2);break;
			case 2:
				if (nb2 != 0) 
					nbStack.push(nb1 / nb2);
				else
					throw RPNEXCEPTION("division by 0");
				break;
			case 3: nbStack.push(nb1 * nb2);break;
		}
		DEBUG_NBSTACK
	}
	if (nbStack.size() > 1)
		throw RPNEXCEPTION("some numbers remain");
	if (opStack.size() > 0)
		throw RPNEXCEPTION("some operator remain");
	DEBUG_SEPARATION
	std::cout << GREEN << "result: " << nbStack.top() << RESET << std::endl;
}