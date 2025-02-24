/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ple-guya <ple-guya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 15:09:58 by ple-guya          #+#    #+#             */
/*   Updated: 2025/02/23 16:09:01 by ple-guya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
#define ITER_HPP

#include <iostream>

template <typename T,typename Func>
void iter(T &arr, size_t n, Func f)
{
    for (size_t i = 0; i < n; i++)
       f(arr[i]);
}

template <typename T>
void add_one(T& x)
{
    x++;
}

template <typename T>
void print_with_space(T x)
{
    std::cout << x << " ";
}

#endif