/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ple-guya <ple-guya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 14:21:53 by ple-guya          #+#    #+#             */
/*   Updated: 2025/02/15 15:52:04 by ple-guya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERY_CREATION_FORM_HPP
#define SHRUBBERY_CREATION_FORM_HPP

#include "AForm.hpp"
#include <fstream>
#define SHRUBBERY_SIGN 147
#define SHRUBERRY_EXEC 137

class ShrubberyCreationForm : public AForm
{
    private :
        std::string target;
    public :
        ShrubberyCreationForm();
        ShrubberyCreationForm(std::string &target);
        ShrubberyCreationForm(ShrubberyCreationForm &cpy);
        ~ShrubberyCreationForm();
        ShrubberyCreationForm &operator=(ShrubberyCreationForm &rhs);
        void execute(Bureaucrat const & executor);
};

#endif