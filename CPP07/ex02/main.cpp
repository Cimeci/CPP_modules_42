/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inowak-- <inowak--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 18:00:56 by inowak--          #+#    #+#             */
/*   Updated: 2025/04/24 14:18:53 by inowak--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Array.hpp"
# include "colors.hpp"

int main() {
	
    Array<int> a(5);
	a[0] = 1;
	a[1] = 2;
	a[2] = 3;
	a[3] = 4;
	a[4] = 5;

	std::cout << "ARRAY A:" << std::endl;

    for (unsigned int i = 0; i < a.size() - 1; ++i){
        std::cout << a[i] << ", ";
	}
	std::cout << a[a.size() - 1] << std::endl;

	
	std::cout  << std::endl;
	
	
	Array<int> b(a);

	std::cout << "ARRAY B:" << std::endl;

    for (unsigned int i = 0; i < b.size() - 1; ++i){
        std::cout << b[i] << ", ";
	}
	std::cout << b[b.size() - 1] << std::endl;

    std::cout << std::endl;
	
	std::cout << std::endl << GREEN << "------------- MODIFICATION ------------" << RESET << std::endl << std::endl;

	std::cout << "a[0] = 999" << std::endl; a[0] = 999;

	std::cout << "b[0] = -42" << std::endl; b[0] = -42;

	std::cout << std::endl << BLUE << "------------- PRINT ARRAY -------------" << RESET << std::endl << std::endl;


	
	std::cout << "ARRAY A:" << std::endl;

    for (unsigned int i = 0; i < a.size() - 1; ++i){
        std::cout << a[i] << ", ";
	}
	std::cout << a[a.size() - 1] << std::endl;

	
	std::cout  << std::endl;
	

	std::cout << "ARRAY B:" << std::endl;

    for (unsigned int i = 0; i < b.size() - 1; ++i){
        std::cout << b[i] << ", ";
	}
	std::cout << b[b.size() - 1] << std::endl;

	std::cout  << std::endl;

	std::cout << "ARRAY C:" << std::endl;
	
	std::srand(std::time(0));
    unsigned int size = std::rand() % 30 + 1;
    Array<int> c(size);

    for (unsigned int i = 0; i < c.size(); ++i)
        c[i] = std::rand() % 100;

    std::cout << "Array of random size " << c.size() << " and radom number is:\n";
    for (unsigned int i = 0; i < c.size() - 1; ++i){
        std::cout << c[i] << ", ";
	}
	std::cout << c[c.size() - 1] << std::endl;
	
	std::cout << std::endl << RED << "---------------- ERROR ----------------" << RESET << std::endl << std::endl;
	
	// try {Array<int> c(-56);}
	// catch (std::exception &e){std::cout << e.what() << std::endl;}

	std::cout << "try : " << std::endl;
	
	std::cout << "b[-56] : ";
	try{std::cout << b[-56] << std::endl;}
	catch (std::exception &e){std::cout << PURPLE << e.what() << RESET <<" because the index is negatif" << std::endl;}

	std::cout << "b[56] : ";
	try{std::cout << b[56] << std::endl;}
	catch (std::exception &e){std::cout << PURPLE << e.what() << RESET << " because the index is upper than " << b.size() << std::endl;}
}

// #include <iostream>
// #include "Array.hpp"

// #define MAX_VAL 750
// int main(int, char**)
// {
//     Array<int> numbers(MAX_VAL);
//     int* mirror = new int[MAX_VAL];
//     srand(time(NULL));
//     for (int i = 0; i < MAX_VAL; i++)
//     {
//         const int value = rand();
//         numbers[i] = value;
//         mirror[i] = value;
//     }
//     //SCOPE
//     {
//         Array<int> tmp = numbers;
//         Array<int> test(tmp);
//     }

//     for (int i = 0; i < MAX_VAL; i++)
//     {
//         if (mirror[i] != numbers[i])
//         {
//             std::cerr << "didn't save the same value!!" << std::endl;
//             return 1;
//         }
//     }
//     try
//     {
//         numbers[-2] = 0;
//     }
//     catch(const std::exception& e)
//     {
//         std::cerr << e.what() << '\n';
//     }
//     try
//     {
//         numbers[MAX_VAL] = 0;
//     }
//     catch(const std::exception& e)
//     {
//         std::cerr << e.what() << '\n';
//     }

//     for (int i = 0; i < MAX_VAL; i++)
//     {
//         numbers[i] = rand();
//     }
//     delete [] mirror;//
//     return 0;
// }