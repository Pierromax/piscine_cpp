/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ple-guya <ple-guya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 13:45:16 by ple-guya          #+#    #+#             */
/*   Updated: 2024/12/14 21:31:07 by ple-guya         ###   ########.fr       */
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

    if (bsp(a, b, c, p1))
		std::cout << "is in" << std::endl;

    return 0;
}

