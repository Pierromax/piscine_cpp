/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ple-guya <ple-guya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 14:44:42 by ple-guya          #+#    #+#             */
/*   Updated: 2025/02/23 14:50:39 by ple-guya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
#define WHATEVER_HPP

template <typename T>
void swap(T& a, T& b)
{
    T tmp;
    
    tmp = a;
    a = b;
    b = tmp;
}

template <typename T>
T max(T a, T b)
{
    if (a > b)
        return a;
    return b;
}

template <typename T>
T min(T a, T b)
{
    if (a < b)
        return a;
    return b;
}


#endif