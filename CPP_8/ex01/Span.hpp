/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ple-guya <ple-guya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 14:54:54 by ple-guya          #+#    #+#             */
/*   Updated: 2025/02/25 14:54:54 by ple-guya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>
#include <vector>
#include <algorithm>
#include <exception>
#include <numeric>

class Span
{
    private:
        std::vector<int> vec;
    public:
        Span();
        Span(unsigned int n);
        Span(Span const &cpy);
        Span & operator=(Span const & rhs);
        ~Span();

        template <typename Iterator>
        void addNumbers(Iterator begin, Iterator end);
        void addNumber(int n);
        int shortestSpan() const;
        int longestSpan() const;
};

#endif