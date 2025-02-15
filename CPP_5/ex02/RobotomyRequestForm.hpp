/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ple-guya <ple-guya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 14:21:44 by ple-guya          #+#    #+#             */
/*   Updated: 2025/02/15 19:08:42 by ple-guya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include "AForm.hpp"
#include <cstdlib>
#include <ctime>
#define ROBO_SIGN 72
#define ROBO_EXEC 45

class RobtomyRequestForm : public AForm
{
    private :
        std::string target;
    public :
        RobtomyRequestForm();
        RobtomyRequestForm(std::string const &target);
        RobtomyRequestForm(RobtomyRequestForm &cpy);
        ~RobtomyRequestForm();
        RobtomyRequestForm &operator=(RobtomyRequestForm &rhs);
        void execute(Bureaucrat const & executor) const;
};

#endif