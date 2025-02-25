/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ple-guya <ple-guya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 18:47:58 by ple-guya          #+#    #+#             */
/*   Updated: 2025/02/21 15:31:47 by ple-guya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("Grade too high !");
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("Grade too Low !");
}


/********************************************/
/*       Constructor et destructor          */
/********************************************/

Bureaucrat::Bureaucrat(int grade) : name(""), grade(grade) 
{
	if (grade < 1) {
        throw GradeTooHighException();
    }
    if (grade > 150) {
        throw GradeTooLowException();
    }
    std::cout << "default bureaucrat constrcutor called" << std::endl;
}

Bureaucrat::Bureaucrat(const std::string &newname, int newgrade) : name(newname) , grade(newgrade) 
{
	if (newgrade < 1) {
        throw GradeTooHighException();
    }
    if (newgrade > 150) {
        throw GradeTooLowException();
    }
    std::cout << "Bureaucrat constructor called" << std::endl;   
}

Bureaucrat::Bureaucrat(Bureaucrat &src) : name(src.name), grade(src.grade) 
{
    std::cout << "bureaucrat copy constructor called" << std::endl; 
}  

Bureaucrat::~Bureaucrat() 
{
    std::cout << "a bas la bureauctratie (destructor called)" << std::endl;
}

/********************************************/
/*            Member functions              */
/********************************************/

void Bureaucrat::incrementGrade()
{
	if (this->grade <= 1) {
		throw GradeTooHighException();
	}
	this->grade--;
}

void Bureaucrat::decrementGrade()
{
	if (this->grade >= 150) {
		throw GradeTooLowException();
	}
	this->grade++;
}

/********************************************/
/*                Getter                    */
/********************************************/

std::string Bureaucrat::getName() const
{
    return this->name;
}

int Bureaucrat::getGrade() const
{
    return this->grade;
}

/********************************************/
/*          surcharge d'operateur           */
/********************************************/

Bureaucrat  &Bureaucrat::operator=(Bureaucrat &rhs)
{
    if (this != &rhs)
        this->grade = rhs.grade;
    return *this;
}

std::ostream &operator<<(std::ostream &out, const Bureaucrat &buro)
{
    out << buro.getName() << ", bureaucrat grade " << buro.getGrade();
    return out;
}