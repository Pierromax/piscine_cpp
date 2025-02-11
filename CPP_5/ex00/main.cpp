/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ple-guya <ple-guya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 18:51:11 by ple-guya          #+#    #+#             */
/*   Updated: 2025/02/05 17:58:51 by ple-guya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main()
{
    Bureaucrat b0("Robert", 150);
    Bureaucrat b1("Bob", 1);

    try {
        b0.decrementGrade();
    } catch (const std::exception& e) {
        std::cerr << b0.getName() << " : " << e.what() << '\n';
    }
    try {
        b1.incrementGrade();
    } catch (const std::exception &e){
        std::cerr << b1.getName() << " : " << e.what() << '\n';
    }
    
}