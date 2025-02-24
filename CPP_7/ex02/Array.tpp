/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ple-guya <ple-guya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 13:33:43 by ple-guya          #+#    #+#             */
/*   Updated: 2025/02/24 15:09:33 by ple-guya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

template <typename T>
Array<T>::Array() : _size(0), array(new T[0]) {}
    
template <typename T>
Array<T>::Array(unsigned int n) : _size(n), array(new T[n]) {}

template <typename T>
Array<T>::Array(const Array &cpy) : _size(cpy._size), array(new T[cpy._size]) 
{
    for (unsigned int i = 0; i < this->_size; i++)
        this->array[i] = cpy.array[i];
}

template <typename T>
Array<T>   &Array<T>::operator=(const Array &rhs)
{
    if (rhs != *this)
    {
        delete [] this->array;
        this->_size = rhs._size;
        this->array = new T[rhs._size];
        for (unsigned int i = 0; i < rhs._size ; i++)
            this->array[i] = rhs.array[i];
    }
    return *this;
}

template <typename T>
T &Array<T>::operator[](unsigned int n)
{
    if (n < 0 || n >= this->_size)
        throw(std::out_of_range("index out of bounds"));
    return (array[n]);
}

template <typename T>
unsigned int    Array<T>::size() {return this->_size;}

template <typename T>
Array<T>::~Array()
{
    delete [] array;
}
