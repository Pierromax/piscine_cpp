/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ple-guya <ple-guya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 14:21:41 by ple-guya          #+#    #+#             */
/*   Updated: 2025/02/17 16:30:43 by ple-guya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

/********************************************/
/*       Constructor et destructor          */
/********************************************/

RobotomyRequestForm::RobotomyRequestForm() : AForm("Robotomy Request", ROBO_SIGN, ROBO_EXEC)
{
    this->target = "default";
}

RobotomyRequestForm::RobotomyRequestForm(std::string const &target) : AForm("Robotomy request", ROBO_SIGN, ROBO_EXEC)
{
    this->target = target;
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm &cpy) : AForm(cpy), target(cpy.target) {}

RobotomyRequestForm::~RobotomyRequestForm() {}

RobotomyRequestForm &RobotomyRequestForm::operator=(RobotomyRequestForm &rhs)
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

void RobotomyRequestForm::execute(Bureaucrat const &executor) const
{
    AForm::execute(executor);
    srand(time(NULL));
    if (rand() % 2)
        std::cout << this->target << " has been robotomized successfully" << std::endl;
    else
        std::cout << this->target << " has failed to be robotomized" << std::endl;
}
