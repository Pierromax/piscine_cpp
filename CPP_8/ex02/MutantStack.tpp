/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ple-guya <ple-guya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 17:11:43 by ple-guya          #+#    #+#             */
/*   Updated: 2025/02/25 17:11:43 by ple-guya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"

/***********************************/
/*    Constructors & Destructors   */
/***********************************/

template <typename T>
MutantStack<T>::MutantStack() {}

template <typename T>
MutantStack<T>::MutantStack(MutantStack const &cpy) : std::stack<T>(cpy) {}

template <typename T>
MutantStack<T> & MutantStack<T>::operator=(MutantStack const &rhs)
{
    if (this != &rhs)
        std::stack<T>::operator=(rhs);
    return *this;
}

template <typename T>
MutantStack<T>::~MutantStack() {}

template <typename T>
typename MutantStack<T>::iterator MutantStack<T>::begin()
{
    return this->c.begin();
};

template <typename T>
typename MutantStack<T>::iterator MutantStack<T>::end()
{
    return this->c.end();
};


