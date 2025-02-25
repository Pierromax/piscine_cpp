/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ple-guya <ple-guya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 15:55:28 by ple-guya          #+#    #+#             */
/*   Updated: 2025/02/24 17:29:24 by ple-guya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <iostream>
#include <algorithm>

template <typename T>
int easyfind(T &container, int n)
{
    typename T::iterator it;
    
    it = std::find(container.begin(), container.end(), n);
    if (it == container.end())
        throw(std::out_of_range("can't find the value"));
    return(*it);
}

#endif