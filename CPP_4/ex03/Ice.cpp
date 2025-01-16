/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ple-guya <ple-guya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 15:22:31 by ple-guya          #+#    #+#             */
/*   Updated: 2025/01/16 13:40:09 by ple-guya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"

Ice::Ice() : AMateria("ice") {}

Ice::Ice(const Ice &src) : AMateria(src) {}

Ice::~Ice() {}

Ice &Ice::operator=(const Ice &src)
{
    if (this != &src)
        AMateria::operator=(src);
    return *this;
}

AMateria *Ice::clone() const
{
    
    return new Ice(*this);
}

void Ice::use(ICharacter &target)
{
    std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}