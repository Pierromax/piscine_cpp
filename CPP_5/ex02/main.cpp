/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ple-guya <ple-guya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 18:51:11 by ple-guya          #+#    #+#             */
/*   Updated: 2025/02/15 18:44:45 by ple-guya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"

int main()
{
    ShrubberyCreationForm formulaire("home");   

    try {
        Bureaucrat b0("Robert", 150);
        b0.signForm(formulaire);
    } catch (const std::exception & e) {
        std::cerr << e.what() << std::endl;
    }
    try {
        Bureaucrat b1("Bob", 1);
        b1.signForm(formulaire);
        b1.executeForm(formulaire);
    } catch (const std::exception &e){
        std::cerr << e.what() << std::endl;
    }

}