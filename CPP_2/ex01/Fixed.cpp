/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ple-guya <ple-guya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 11:42:12 by ple-guya          #+#    #+#             */
/*   Updated: 2024/12/14 18:09:12 by ple-guya         ###   ########.fr       */
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
}

Fixed::Fixed(const int intvalue) : nb(intvalue << nb_bit)
{
	std::cout << "int constructor called" << std::endl;
}

Fixed::Fixed(const float floatvalue) : nb(roundf(floatvalue * (1 << nb_bit)))
{
	std::cout << "float constructor called" << std::endl;
}

int	Fixed::toInt( void ) const
{
	return nb >> nb_bit;
}

float Fixed::toFloat(void) const
{
	//pour cast (float) ou static_cast<float>
	return float(nb) / (1 << nb_bit);
}

Fixed	&Fixed::operator=(const Fixed &fixedNB)
{
	if (this != &fixedNB)
		nb = fixedNB.nb;
	std::cout << "Copy assignment operator called" << std::endl;
	return *this;
}

std::ostream &operator<<(std::ostream &out, const Fixed &fixedNB)
{
	out << fixedNB.toFloat();
	return out;
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