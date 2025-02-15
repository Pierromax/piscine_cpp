/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ple-guya <ple-guya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 07:18:15 by ple-guya          #+#    #+#             */
/*   Updated: 2025/02/12 09:47:39 by ple-guya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

const char* Form::GradeTooHighException::what() const throw()
{
	return ("form Grade too high");
}

const char* Form::GradeTooLowException::what() const throw()
{
	return ("form Grade too Low");
}

Form::Form() :
    name("default"), is_signed(false), grade_to_sign(150), grade_to_execute(150) {}

Form::Form(const std::string& name, int grade_to_sign, int grade_to_execute) :
    name(name), is_signed(false), grade_to_sign(grade_to_sign), grade_to_execute(grade_to_execute) 
{
    if (grade_to_sign < 1 || grade_to_execute < 1)
        throw GradeTooHighException();
    if (grade_to_sign > 150 || grade_to_execute > 150)
        throw GradeTooLowException();
}

Form::Form(Form &cpy) :
    name(cpy.name), is_signed(cpy.is_signed), grade_to_sign(cpy.grade_to_sign), grade_to_execute(cpy.grade_to_execute) {}

Form &Form::operator=(Form &rhs) 
{
    if (this != &rhs) {
        this->is_signed = rhs.is_signed;
    }
    return *this;
}

Form::~Form() {}

const std::string& Form::getName() const 
{
    return name;
}

bool Form::getSigned() const
{
    return is_signed;
}

int Form::getGradeToSign() const 
{
    return grade_to_sign;
}

int Form::getGradeToExecute() const 
{
    return grade_to_execute;
}

void Form::beSigned(const Bureaucrat& signer)
{
    if (signer.getGrade() > grade_to_sign)
        throw GradeTooLowException();
    this->is_signed = true;
}

std::ostream& operator<<(std::ostream& out, const Form& form) 
{
    out << "Form " << form.getName() << ", Sign status: " << (form.getSigned() ? "signed" : "not signed")
       << ", Grade to sign: " << form.getGradeToSign() << ", Grade to execute: " << form.getGradeToExecute();
    return out;
}