/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ple-guya <ple-guya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 16:18:33 by ple-guya          #+#    #+#             */
/*   Updated: 2025/02/17 16:18:33 by ple-guya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
#define INTERN_HPP

#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

#define SHRUBBERY "shrubbery creation"
#define ROBOTOMY "robotomy request"
#define PRESIDENTIAL "presidential pardon"

class Intern
{
    private :
        typedef AForm* (Intern::*form)(std::string const &target);
        form forms[3];
        AForm* createShrubbery(std::string const &target);
        AForm* createRobotomy(std::string const &target);
        AForm* createPresidential(std::string const &target);
    public :
        Intern();
        Intern(Intern &cpy);
        ~Intern();
        Intern &operator=(Intern &rhs);
        AForm* makeForm(std::string const &name, std::string const &target);
};

#endif