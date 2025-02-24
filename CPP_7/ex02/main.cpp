/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ple-guya <ple-guya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 13:22:22 by ple-guya          #+#    #+#             */
/*   Updated: 2025/02/24 15:09:56 by ple-guya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"
#include <iostream>

int main()
{
    Array<int> a;
    Array<int> b(9);
    Array<char> c(9);

    std::cout << a.size() << std::endl;
    std::cout << b.size() << std::endl;
    for (unsigned int i = 0; i < b.size(); i++)
    {
        b[i] = i;
        c[i] = i + 'a';
    }
    for (unsigned int i = 0; i < b.size(); i++)
        std::cout << b[i] << ' '; 
    std::cout << std::endl;
    for (unsigned int i = 0; i < c.size(); i++)
        std::cout << c[i] << ' ';
    std::cout << std::endl;

    Array<char> d(c);
    for (unsigned int i = 0; i < d.size(); i++)
        std::cout << d[i] << ' ';
    std::cout << std::endl;
    
    try {
        std::cout << b[b.size() + 1] << std::endl;
    }catch(std::exception &e){
        std::cout << e.what() << std::endl;
    }
    try {
        std::cout << a[0] << std::endl;
    }catch(std::exception &e){
        std::cout << e.what() << std::endl;
    }
    
    return (0);
}