/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ple-guya <ple-guya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 16:57:04 by ple-guya          #+#    #+#             */
/*   Updated: 2025/02/24 14:46:30 by ple-guya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>

template <typename T>
class Array
{
    private:
    unsigned int _size;
    T  *array;
    public:
    Array();
    Array(unsigned int n);
    Array(const Array &cpy);
    ~Array();
    
    Array &operator=(const Array &rhs);
    T &operator[](unsigned int n);
    
    unsigned int size();
};

#include "Array.tpp"

#endif