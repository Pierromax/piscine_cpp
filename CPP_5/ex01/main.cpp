/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ple-guya <ple-guya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 18:51:11 by ple-guya          #+#    #+#             */
/*   Updated: 2025/02/12 09:37:05 by ple-guya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
    try {
        Bureaucrat b0("Robert", 150);
        Form formulaire("convention", 50, 50);
        b0.signForm(formulaire);
    } catch (const std::exception & e) {
        std::cerr << e.what() << std::endl;
    }
    try {
        Form formulaire("convention", 50, 50);
        Bureaucrat b1("Bob", 1);
        b1.signForm(formulaire);
    } catch (const std::exception &e){
        std::cerr << e.what() << std::endl;
    }
}