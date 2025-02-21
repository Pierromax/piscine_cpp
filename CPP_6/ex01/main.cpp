/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ple-guya <ple-guya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 13:22:47 by ple-guya          #+#    #+#             */
/*   Updated: 2025/02/21 14:19:11 by ple-guya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

int main()
{
    uintptr_t oui = 80;
    Data *non;
    
    non = Serializer::deserialize(oui);
    std::cout << non << std::endl;
    oui = Serializer::serialize(non);
    std::cout << oui << std::endl;
    
    uintptr_t ptr;
    Data *test = new Data();
    Data *chad;
    test->a = 10;
    test->b = 50;
    
    std::cout << test << std::endl;
    ptr = Serializer::serialize(test);
    std::cout << ptr << std::endl;
    chad = Serializer::deserialize(ptr);
    std::cout << chad << std::endl;
    std::cout << "a: " << chad->a << " && b: " << chad->b << std::endl;
    
    delete test;
}