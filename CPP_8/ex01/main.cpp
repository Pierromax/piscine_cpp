/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ple-guya <ple-guya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 15:21:54 by ple-guya          #+#    #+#             */
/*   Updated: 2025/02/25 15:21:54 by ple-guya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

int main()
{

    //subject test
    Span sp = Span(5);

    sp.addNumber(5);
    sp.addNumber(3);
    sp.addNumber(17);
    sp.addNumber(9);
    sp.addNumber(11);

    std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
    std::cout << "Longest span: " << sp.longestSpan() << std::endl;

    //own test
    try {
        sp.addNumber(42);
    }
    catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
    }

    Span sp2 = Span(10000);
    for (int i = 0; i < 10000; i++)
        sp2.addNumber(i);
    std::cout << "Shortest span: " << sp2.shortestSpan() << std::endl;
    std::cout << "Longest span: " << sp2.longestSpan() << std::endl;

    Span spcpy = sp2;
    try{
        spcpy.addNumber(98);
    }catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
    }
    srand(time(NULL));
    Span sp3 = Span(10000);
    for (int i = 0; i < 10000; i++)
        sp3.addNumber(rand() % 1000000000);
    std::cout << "Shortest span: " << sp3.shortestSpan() << std::endl;
    std::cout << "Longest span: " << sp3.longestSpan() << std::endl;


    return 0;
}