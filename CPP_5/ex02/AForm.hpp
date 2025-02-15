/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ple-guya <ple-guya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 05:17:08 by ple-guya          #+#    #+#             */
/*   Updated: 2025/02/15 18:42:50 by ple-guya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP  

#include <string>
#include <iostream>
#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
    private:
        const std::string   name;
        bool                is_signed;
        const int           grade_to_sign;
        const int           grade_to_execute;

    public:
        AForm();
        AForm(const std::string& name, int grade_to_sign, int grade_to_execute);
        AForm(AForm &cpy);
        AForm &operator=(AForm &rhs);
        ~AForm();

        virtual const std::string& getName() const;
        virtual bool getSigned() const;
        virtual int getGradeToSign() const;
        virtual int getGradeToExecute() const;
        virtual void beSigned(const Bureaucrat &signer);
        virtual void execute(Bureaucrat const &executor) const;

        class GradeTooHighException : public std::exception {
            public:
                const char* what() const throw();
        };
        class GradeTooLowException : public std::exception {
            public:
                const char* what() const throw();
        };
        class NotSignedException : public std::exception {
            public:
                const char* what() const throw();
        };
};

std::ostream& operator<<(std::ostream& os, const AForm& form);

#endif