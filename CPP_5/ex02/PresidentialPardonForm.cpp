/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ple-guya <ple-guya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 14:21:39 by ple-guya          #+#    #+#             */
/*   Updated: 2025/02/15 19:04:18 by ple-guya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

/********************************************/
/*       Constructor et destructor          */
/********************************************/

PresidentialPardonForm::PresidentialPardonForm() : AForm("Presidential_Pardon", SHRUBBERY_SIGN, SHRUBERRY_EXEC)
{
    this->target = "default";
}

PresidentialPardonForm::PresidentialPardonForm(std::string const &target) : AForm("Presidential_Pardon", SHRUBBERY_SIGN, SHRUBERRY_EXEC)
{
    this->target = target;
}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm &cpy) : AForm(cpy), target(cpy.target) {}

PresidentialPardonForm::~PresidentialPardonForm() {}

PresidentialPardonForm &PresidentialPardonForm::operator=(PresidentialPardonForm &rhs)
{
    if (this != &rhs)
    {
        AForm::operator=(rhs);
        this->target = rhs.target;
    }
    return (*this);
}

/********************************************/
/*            Member functions              */
/********************************************/

void PresidentialPardonForm::execute(Bureaucrat const &executor) const
{
    AForm::execute(executor);
    CreateTree(this->target);
}
