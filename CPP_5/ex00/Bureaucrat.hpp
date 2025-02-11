/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ple-guya <ple-guya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 16:59:40 by ple-guya          #+#    #+#             */
/*   Updated: 2025/02/05 17:51:37 by ple-guya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <string>

class Bureaucrat 
{
    private :
        const std::string   name;
        int                 grade;
    public :
        Bureaucrat(int grade);
        Bureaucrat(const std::string &name, int grade);
        Bureaucrat(Bureaucrat &src);
        Bureaucrat  &operator=(Bureaucrat &rhs);
        ~Bureaucrat();
        
        std::string getName() const;
        int         getGrade() const;
        void        incrementGrade();
        void        decrementGrade();
        class GradeTooHighException : public std::exception {
            public :
                virtual const char* what() const throw();
        };

        class GradeTooLowException : public std::exception {
            public :
                virtual const char* what() const throw();
        };
    
};
    std::ostream &operator<<(std::ostream &out, const Bureaucrat &b);

#endif