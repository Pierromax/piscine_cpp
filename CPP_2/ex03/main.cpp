/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ple-guya <ple-guya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 13:45:16 by ple-guya          #+#    #+#             */
/*   Updated: 2025/01/14 16:39:04 by ple-guya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include "Point.hpp"

int main()
{
    Point a(Fixed(0), Fixed(0));
    Point b(Fixed(5), Fixed(0));
    Point c(Fixed(2.5f), Fixed(5));

    Point p1(Fixed(2.5f), Fixed(2)); // Intérieur
    Point p2(Fixed(5), Fixed(5));    // Extérieur
    Point p3(Fixed(2.5f), Fixed(0)); // Sur AB
    Point p4(Fixed(0), Fixed(0));    // Sur A
    Point p5(Fixed(2), Fixed(1));    // Intérieur

    bsp(a, b, c, p1) ? std::cout << "p1 is in" << std::endl : std::cout << "p1 is out" << std::endl;
    bsp(a, b, c, p2) ? std::cout << "p2 is in" << std::endl : std::cout << "p2 is out" << std::endl;
    bsp(a, b, c, p3) ? std::cout << "p3 is in" << std::endl : std::cout << "p3 is out" << std::endl;
    bsp(a, b, c, p4) ? std::cout << "p4 is in" << std::endl : std::cout << "p4 is out" << std::endl;
    bsp(a, b, c, p5) ? std::cout << "p5 is in" << std::endl : std::cout << "p5 is out" << std::endl;

    return 0;
}

