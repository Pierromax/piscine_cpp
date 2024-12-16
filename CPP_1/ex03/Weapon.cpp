/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ple-guya <ple-guya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 00:47:50 by ple-guya          #+#    #+#             */
/*   Updated: 2024/12/08 17:43:47 by ple-guya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(std::string type) : type(type) {}

Weapon::~Weapon()
{
	std::cout << "weapon has been destroy" << std::endl;
}

std::string Weapon::getType(void) const
{
	return type;
}

void Weapon::setType(const std::string &newtype)
{
	type = newtype;
}

