/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ple-guya <ple-guya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 18:51:11 by ple-guya          #+#    #+#             */
/*   Updated: 2025/02/17 16:35:27 by ple-guya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Intern.hpp"

int main()
{
    Intern someRandomIntern;
    AForm* rrf;
    AForm* srf;
    AForm* prf;
    
    rrf = someRandomIntern.makeForm("robotomy request", "Bender");
    std::cout << *rrf << std::endl;
    srf = someRandomIntern.makeForm("shrubbery creation", "Atrium");
    std::cout << *srf << std::endl;
    prf = someRandomIntern.makeForm("presidential pardon", "KobalaD");
    std::cout << *prf << std::endl;
}