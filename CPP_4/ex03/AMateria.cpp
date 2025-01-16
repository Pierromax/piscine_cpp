/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ple-guya <ple-guya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 15:03:25 by ple-guya          #+#    #+#             */
/*   Updated: 2025/01/10 16:03:53 by ple-guya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

AMateria::AMateria() : type("") {}

AMateria::AMateria(std::string const &type) : type(type) {}

AMateria::AMateria(const AMateria &src) : type(src.type) {}

AMateria::~AMateria() {}

AMateria &AMateria::operator=(const AMateria &src)
{
    if (this != &src)
        this->type = src.type;
    return *this;
}

std::string const &AMateria::getType() const
{
    return this->type;
}

void AMateria::use(ICharacter &target)
{
    (void)target;
}