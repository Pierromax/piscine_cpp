/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ple-guya <ple-guya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 17:09:13 by ple-guya          #+#    #+#             */
/*   Updated: 2025/02/25 17:09:13 by ple-guya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <iostream>
#include <stack>
#include <algorithm>
#include <iterator>

template <typename T>
class MutantStack : public std::stack<T>
{
    public:
        MutantStack();
        MutantStack(MutantStack const &cpy);
        MutantStack & operator=(MutantStack const &rhs);
        ~MutantStack();

        typedef typename std::stack<T>::container_type::iterator iterator;
        iterator begin();
        iterator end();
};

#include "MutantStack.tpp"

#endif
