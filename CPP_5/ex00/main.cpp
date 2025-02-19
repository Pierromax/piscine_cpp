/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ple-guya <ple-guya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 18:51:11 by ple-guya          #+#    #+#             */
/*   Updated: 2025/02/19 10:20:29 by ple-guya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main()
{
    try {
        Bureaucrat b0("Robert", 150);
        b0.decrementGrade();
    } catch (const std::exception &e) {
        std::cerr << e.what() << '\n';
    }
    try {
        Bureaucrat b1("Bob", 1);
        b1.incrementGrade();
    } catch (const std::exception &e){
        std::cerr << " : " << e.what() << '\n';
    }
}