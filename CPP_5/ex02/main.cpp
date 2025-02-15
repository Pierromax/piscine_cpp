/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ple-guya <ple-guya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 18:51:11 by ple-guya          #+#    #+#             */
/*   Updated: 2025/02/15 21:30:07 by ple-guya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main()
{
    ShrubberyCreationForm Shubbery("home");  
    RobotomyRequestForm Robot("home");
    PresidentialPardonForm President("home");

    std::cout << Shubbery << std::endl;
    try {
        Bureaucrat b1("Bob", 1);
        b1.signForm(Shubbery);
        b1.executeForm(Shubbery);
    } catch (const std::exception &e){
        std::cerr << e.what() << std::endl;
    }
    std::cout << std::endl << Robot << std::endl;
    try {
        Bureaucrat b2("Robert", 25);
        b2.signForm(Robot);
        b2.executeForm(Robot);
    } catch (const std::exception & e) {
        std::cerr << e.what() << std::endl;
    }
    std::cout << std::endl << President << std::endl;
    try {
        Bureaucrat b3("Roberto", 5);
        b3.signForm(President);
        b3.executeForm(President);
    } catch (const std::exception & e) {
        std::cerr << e.what() << std::endl;
    } 
    return 0;
}