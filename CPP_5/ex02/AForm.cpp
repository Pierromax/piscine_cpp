/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ple-guya <ple-guya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 07:18:15 by ple-guya          #+#    #+#             */
/*   Updated: 2025/02/17 16:16:01 by ple-guya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

const char* AForm::GradeTooHighException::what() const throw()
{
	return ("form Grade is too high");
}

const char* AForm::GradeTooLowException::what() const throw()
{
	return ("form Grade is too Low");
}

const char* AForm::NotSignedException::what() const throw()
{
    return ("Form not signed");
}

/********************************************/
/*       Constructor et destructor          */
/********************************************/

AForm::AForm() : name("default"), is_signed(false), grade_to_sign(150), grade_to_execute(150) {}

AForm::AForm(const std::string& name, int grade_to_sign, int grade_to_execute) :
    name(name), is_signed(false), grade_to_sign(grade_to_sign), grade_to_execute(grade_to_execute) 
{
    if (grade_to_sign < 1 || grade_to_execute < 1)
        throw GradeTooHighException();
    if (grade_to_sign > 150 || grade_to_execute > 150)
        throw GradeTooLowException();
}

AForm::AForm(AForm &cpy) :
    name(cpy.name), is_signed(cpy.is_signed), grade_to_sign(cpy.grade_to_sign), grade_to_execute(cpy.grade_to_execute) {}

AForm::~AForm() {}

/********************************************/
/*                Getter                    */
/********************************************/

const std::string& AForm::getName() const 
{
    return name;
}

bool AForm::getSigned() const
{
    return is_signed;
}

int AForm::getGradeToSign() const 
{
    return grade_to_sign;
}

int AForm::getGradeToExecute() const 
{
    return grade_to_execute;
}

/********************************************/
/*            Member functions              */
/********************************************/

void AForm::beSigned(const Bureaucrat& signer)
{
    if (signer.getGrade() > grade_to_sign)
        throw GradeTooLowException();
    this->is_signed = true;
}

void AForm::execute(Bureaucrat const &executor)
{
    if (this->is_signed == false)
        throw NotSignedException();
    if (getGradeToExecute() < executor.getGrade())
        throw GradeTooLowException();
}

/********************************************/
/*          surcharge d'operateur           */
/********************************************/

AForm &AForm::operator=(AForm &rhs) 
{
    if (this != &rhs) {
        this->name = rhs.name;
        this->grade_to_execute = rhs.grade_to_execute;
        this->grade_to_sign = rhs.grade_to_sign;
        this->is_signed = rhs.is_signed;
    }
    return *this;
}

std::ostream& operator<<(std::ostream& out, const AForm& form) 
{
    out << "Form " << form.getName() << ", Sign status: " << (form.getSigned() ? "signed" : "not signed")
       << ", Grade to sign: " << form.getGradeToSign() << ", Grade to execute: " << form.getGradeToExecute();
    return out;
}
