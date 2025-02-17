/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ple-guya <ple-guya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 16:20:47 by ple-guya          #+#    #+#             */
/*   Updated: 2025/02/17 16:20:47 by ple-guya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern()
{
    forms[0] = &Intern::createShrubbery;
    forms[1] = &Intern::createRobotomy;
    forms[2] = &Intern::createPresidential;
}

Intern::Intern(Intern &cpy)
{
    *this = cpy;
}

Intern::~Intern() {}

Intern &Intern::operator=(Intern &rhs)
{
    if (this == &rhs)
        return *this;
    return *this;
}

AForm* Intern::makeForm(std::string const &name, std::string const &target)
{
    for (int i = 0; i < 3; i++)
    {
        if (name == SHRUBBERY)
            return (this->*forms[0])(target);
        if (name == ROBOTOMY)
            return (this->*forms[1])(target);
        if (name == PRESIDENTIAL)
            return (this->*forms[2])(target);
    }
    return NULL;
}   

AForm* Intern::createShrubbery(std::string const &target)
{
    return new ShrubberyCreationForm(target);
}

AForm* Intern::createRobotomy(std::string const &target)
{
    return new RobotomyRequestForm(target);
}

AForm* Intern::createPresidential(std::string const &target)
{
    return new PresidentialPardonForm(target);
}  