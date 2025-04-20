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
		stack = op.stack;
	return *this;
}

RPN::~RPN(){}

//* --------- // ALGORITHM | PUBLIC // --------- *//

void RPN::process(const std::string input) {
	try {isValidInput(input);}
	catch (RPNEXCEPTION &e){ERROR_LOADSTACK;}

	try {calcul(input);}
	catch (RPNEXCEPTION &e){ERROR_CALCUL;}

	std::cout << "Result: " << stack.top() << std::endl;
}

//* --------- // ALGORITHM | PRIVATE // --------- *//

bool isOperator(const char c){
	if (c == '+' || c == '-' || c == '/' || c == '*' )
		return true;
	return false;
}

void RPN::isValidInput(const std::string &input) const{
	if (input.size() < 2)
		throw RPNEXCEPTION("size invalid");
	for (size_t i = 0; i < input.size(); i++){
		if (input[i] != ' ' && !isdigit(input[i]) && !isOperator(input[i]))
			throw RPNEXCEPTION("character false : " + input[i]);
	}
}

void RPN::loadStack(const std::string &input, size_t op, size_t lastOp) {
	for (size_t i = lastOp; i < op; i++){
		if (isdigit(input[i]))
			stack.push(std::atoi(&input[i]));
	}
}

void RPN::operation(const char opfind){
	char op[4] = {'+', '-', '/', '*'};
	double nb1;
	double nb2;
	size_t i;

	DEBUG_STACK;
	if (stack.size() < 2)
		throw RPNEXCEPTION("stack not have 2 numbers");
	for (i = 0; opfind != op[i] && i < 4; i++);
	nb2 = stack.top();
	stack.pop();
	nb1 = stack.top();
	stack.pop();
	DEBUG_PRINT(nb1 << op[i] << nb2)
	switch (i){
		case 0: stack.push(nb1 + nb2);break;
		case 1: stack.push(nb1 - nb2);break;
		case 2:
			if (nb2 == 0) {throw RPNEXCEPTION("division by 0");}
			stack.push(nb1 / nb2);break;
		case 3: stack.push(nb1 * nb2);break;
	}
	DEBUG_SEPARATION
}

void RPN::isEnough(const std::string &input)
{
	size_t nbOp = 0;
	for (size_t i = 0; i < input.size(); i++)
	{
		if (isOperator(input[i]))
			nbOp++;
	}
	size_t nbNumber = 0;
	for (size_t i = 0; i < input.size(); i++)
	{
		if (isdigit(input[i]))
			nbNumber++;
	}

	DEBUG_PRINT(nbOp + 1)
	DEBUG_PRINT(stack.size())
	if (nbNumber < (nbOp + 1))
		throw RPNEXCEPTION("not enough number");
	if (nbNumber > (nbOp + 1))
		throw RPNEXCEPTION("not enough operator");
}

void RPN::calcul(const std::string &input){
	size_t opPos = 0;
	
	isEnough(input);
	for (size_t i = 1; i < input.size(); i++)
	{
		if (isOperator(input[i]))
		{
			loadStack(input, i, opPos);
			operation(input[i]);
			opPos = i;
		}
	}	
}