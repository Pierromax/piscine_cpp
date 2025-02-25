/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ple-guya <ple-guya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 14:57:17 by ple-guya          #+#    #+#             */
/*   Updated: 2025/02/25 14:57:17 by ple-guya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

/***********************************/
/*    Constructors & Destructors   */
/***********************************/

Span::Span()
{
    vec.reserve(0);
}

Span::Span(unsigned int n) 
{
    vec.reserve(n);
}

Span::Span(Span const &cpy) : vec(cpy.vec) {}

Span::~Span() {}

/***********************************/
/*       Menmeber FUnctions        */
/***********************************/

void Span::addNumber(int n)
{
    if (vec.size() < vec.capacity())
        vec.push_back(n);
    else
        throw std::out_of_range("Span is full");
}

int Span::shortestSpan() const
{
    if (vec.size() <= 1)
        throw std::out_of_range("Not enough elements to find a span");

    std::vector<int> sorted_v = vec;
    std::sort(sorted_v.begin(), sorted_v.end());
    std::vector<int> diff(vec.size());
    std::adjacent_difference(sorted_v.begin(), sorted_v.end(), diff.begin());
    int min = *std::min_element(diff.begin() + 1, diff.end());
    return min;
}

int Span::longestSpan() const
{
    if (vec.size() <= 1)
        throw std::out_of_range("Not enough elements to find a span");

    int min = *std::min_element(vec.begin(), vec.end());
    int max = *std::max_element(vec.begin(), vec.end());

    return (max - min);
}

/***********************************/
/*         Operator Overload       */
/***********************************/

Span &Span::operator=(Span const & rhs)
{
    if (this != &rhs)
        vec = rhs.vec;
    return *this;
}