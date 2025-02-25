/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ple-guya <ple-guya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 13:22:47 by ple-guya          #+#    #+#             */
/*   Updated: 2025/02/21 14:53:49 by ple-guya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

int main()
{
    uintptr_t ptr;
    Data test;
    Data *chad;
    test.a = 10;
    test.b = 50;
    
    std::cout << "original Data adress :" << &test << std::endl;
    ptr = Serializer::serialize(&test);
    std::cout << "serialized adress: " << &ptr << std::endl << "ptr value : " << ptr<< std::endl;
    chad = Serializer::deserialize(ptr);
    std::cout << "dezerialized adress: " << chad << std::endl;
    std::cout << "a: " << chad->a << " && b: " << chad->b << std::endl;
}