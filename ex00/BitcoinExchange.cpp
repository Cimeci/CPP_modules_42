/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inowak-- <inowak--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 11:45:16 by inowak--          #+#    #+#             */
/*   Updated: 2025/04/16 20:27:16 by inowak--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "BitcoinExchange.hpp"

//* BITCOIN EXCEPTION *//

BitcoinException::BitcoinException(const std::string& msg) : _msg(msg) {}

const char* BitcoinException::what() const throw() {
	return _msg.c_str();
}

BitcoinException::~BitcoinException() throw() {}



//* CANONICAL FORM *//

BitcoinExchange::BitcoinExchange(){}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &cp){*this = cp;}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &op){
	if (this != &op)
		dataBase = op.dataBase;
	return (*this);
}

BitcoinExchange::~BitcoinExchange(){}



//* ALGORITHM | PUBLIC *//

void BitcoinExchange::process(const std::string &filePath){
	try{loadDataBase("data.csv");}
	catch(BitcoinException &e) {ERROR_LOAD;return;}
	
	std::ifstream file(filePath.c_str());
	
	try {
		if (!file.is_open())
			throw BitcoinException("Fail to load " + filePath);
	}
	catch (BitcoinException &e) {ERROR_LOAD;return;}

	std::string date = "0";
	std::string str_value = "0";
	float value = 0.0f;
	std::size_t separator = 0;
	std::string line;
	long i = 2;
	
	//* ---- // FIRST LINE // ---- *//
	try{
		std::getline(file, line);
		if (line != "date | value")
			throw BitcoinException("format of the first line: '" + line + "'");
	}
	catch (BitcoinException &e) {ERROR_INPUT;return;}
	
	//* ---- // FILE // ---- *//	
	while (std::getline(file, line)){
		
		try {

			separator = line.find("|");
			if (separator == std::string::npos){
				std::ostringstream oss;
				oss << "operator : " << i << " | " << line;
				throw BitcoinException(oss.str());
			}
			
			date = line.substr(0, separator - 1);
			if (!isValidDate(date)){
				std::ostringstream oss;
				oss << "date : " << i << " | " << line;
				throw BitcoinException(oss.str());
			}
			
			str_value = line.substr(separator + 2, line.size());
			if (!isValidValue(str_value)){
				std::ostringstream oss;
				oss << "value : " << i << " | " << line;
				throw BitcoinException(oss.str());
			}
			value = std::atof(str_value.c_str());
			while (dataBase.count(date) == 0 && date != "2009-01-02")
				date = decrementDate(date);
			DEBUG_DATE;
			std::cout << line.substr(0, separator - 1) << " => " << value << " = " << dataBase[date] * value << std::endl;
		}
		catch (BitcoinException &e) {ERROR_INPUT;}
		i++;
	}
}



//* ALGORITHM | PRIVATE  *//

void BitcoinExchange::loadDataBase(const std::string &filePath){
	std::ifstream file(filePath.c_str());
	
	if (!file.is_open())
		throw BitcoinException("Fail to load data.csv");
		
	std::string date = "0";
	float value = 0.0f;
	std::size_t separator = 0;
	std::string line;
	
	std::getline(file, line); // SKIP FIRST LINE //

	while (std::getline(file, line)){
		separator = line.find(",");
		date = line.substr(0, separator);
		value = std::atof(line.substr(separator + 1, line.size()).c_str());
		dataBase[date] = value;
	}
}

bool BitcoinExchange::isAllDigit(const std::string nb) const{
	for (unsigned int i = 0; i < nb.size(); i++){
		if (!isdigit(nb[i]))
			return (false);
	}
	return (true);
}

struct tm t_date;

std::string BitcoinExchange::decrementDate(const std::string &date) const{
	
	std::string Year = date.substr(0, 4);
	std::string Month = date.substr(5, 2);
	std::string Day = date.substr(8, 2);

	t_date.tm_year = std::atoi(Year.c_str()) - 1900;
	t_date.tm_mon  = std::atoi(Month.c_str()) - 1;
	t_date.tm_mday = std::atoi(Day.c_str());

	t_date.tm_mday--;

	mktime(&t_date);

	char buffer[11];
	std::strftime(buffer, sizeof(buffer), "%Y-%m-%d", &t_date);
	
	return std::string(buffer);
}

bool BitcoinExchange::isValidDate(const std::string &date) const{
	
	if (date.size() != 10)
		return false;

	std::string Year = date.substr(0, 4);
	std::string Month = date.substr(5, 2);
	std::string Day = date.substr(8, 2);

	int year = std::atoi(Year.c_str());
	int month = std::atoi(Month.c_str());
	int day = std::atoi(Day.c_str());
	
	if (date[4] != '-' || date[7] != '-' || !isAllDigit(Year) || !isAllDigit(Month) || !isAllDigit(Day))
		return false;

	if (year < 2009 || year > 2022)
		return false;
		
	if (month < 1 || month > 12)
		return false;

	//? BEGGIN OF THE YEARS FOR 30 OR 31 ?//

	if (month >= 1 && month <= 7 )
	{
		if (month % 2 == 1 && (day < 1 || day > 31))
			return false;
		if (month % 2 == 0 && (day < 1 || day > 30))
			return false;
	}

	//? END OF THE YEARS FOR 30 OR 31 ?//

	if (month >= 8 && month <= 12 )
	{
		if (month % 2 == 0 && (day < 1 || day > 31))
			return false;
		if (month % 2 == 1 && (day < 1 || day > 30))
			return false;
	}

	//! FEBRUARY MONTH !//
	
	if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
	{
		if (month == 2 && (day < 1 || day > 29))
			return false;
	}
	else if ((month == 2 && (day < 1 || day > 28)))
		return false;

	return true;
}

bool BitcoinExchange::isValidValue(const std::string &value) const{
	
	if (value.find(".") == std::string::npos && (std::atol(value.c_str()) < 0 || std::atol(value.c_str()) > 1000))
		return false;
	if (std::atof(value.c_str()) < -std::numeric_limits<float>::max() || std::atof(value.c_str()) > std::numeric_limits<float>::max())
		return false;
	return true;
}
