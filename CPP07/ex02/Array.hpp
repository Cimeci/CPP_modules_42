/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inowak-- <inowak--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 14:19:40 by inowak--          #+#    #+#             */
/*   Updated: 2025/04/11 17:50:05 by inowak--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# pragma once 

# include <exception>
# include <iostream>
# include <cstdlib>
# include <ctime>


#define nullptr 0

template <typename T>

class Array{

	private:
		unsigned int n; // SIZE OF ARRAY
		T *array;

	public:
	
// ------------ // DEFAULT CONSTRUCTOR // ------------ //
		Array() : n(0), array(nullptr){}


// -- // CONSTRUCTOR WITH UNSIGNED INT PARAMETER // -- //
		Array(unsigned int n) : n(n) { array = new T[n](); }


// -------------- // COPY CONSTRUCTOR // ------------- //
		Array(const Array &cp) : n(cp.n), array(new T[cp.n]){
			for (unsigned int i = 0; i < n; i++)
				array[i] = cp.array[i];
		}


// ----------- // ASSIGNEMENT OPERATOR = // ---------- //
		Array &operator=( const Array &op ){
			if (this != &op){
				delete[] array;
				n = op.n;
				array = new T[n];
				for (unsigned int i = 0; i < n; i++)
					array[i] = op.array[i];
			}
			return (*this);
		}


// ---------- // ASSIGNEMENT OPERATOR [] // ---------- //
		T& operator[](unsigned int index){
			if (index >= n)
				throw std::exception();
			return array[index];
		}


// ----------------- // GETER SIZE // ---------------- //
		unsigned int size(){ return n; }


// ----------------- // DESTRUCTOR // ---------------- //
		~Array(){ delete[] array; }
};