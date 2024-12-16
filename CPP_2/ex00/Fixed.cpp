/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ple-guya <ple-guya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 11:42:12 by ple-guya          #+#    #+#             */
/*   Updated: 2024/12/14 18:08:44 by ple-guya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed() : nb(0)
{
	std::cout << "default constructor called" << std::endl;
}

Fixed::~Fixed()
{
	std::cout << "destructor called" << std::endl;
}

Fixed::Fixed(const Fixed &fixedNB) : nb(fixedNB.nb) 
{
	std::cout << "copy constructor called" << std::endl;
};

Fixed	&Fixed::operator=(const Fixed &fixedNB)
{
	if (this != &fixedNB)
		nb = fixedNB.nb;
	return *this;
}

int	Fixed::getRawBits(void) const
{
	std::cout << "get Raw Bit function called" << std::endl;
	return nb;
}

void	Fixed::setRawBits(int const raw)
{
	nb = raw;
}