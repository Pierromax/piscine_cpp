/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ple-guya <ple-guya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 11:42:12 by ple-guya          #+#    #+#             */
/*   Updated: 2024/12/14 21:31:20 by ple-guya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed() : nb(0) {}

Fixed::~Fixed() {}

Fixed::Fixed(const Fixed &fixedNB) : nb(fixedNB.nb) {}

Fixed::Fixed(const int intvalue) : nb(intvalue << nb_bit) {}

Fixed::Fixed(const float floatvalue) : nb(roundf(floatvalue * (1 << nb_bit))) {}

int	Fixed::getRawBits(void) const {return nb;}

void	Fixed::setRawBits(int const raw) {nb = raw;}

int	Fixed::toInt( void ) const
{
	return nb >> nb_bit;
}

float	Fixed::toFloat(void) const
{
	//pour cast (float) ou static_cast<float>
	return float(nb) / (1 << nb_bit);
}

//liste des operateurs
//assignement
Fixed	&Fixed::operator=(const Fixed &fixedNB)
{
	if (this != &fixedNB)
		nb = fixedNB.nb;
	std::cout << "Copy assignment operator called" << std::endl;
	return *this;
}
//ecriture
std::ostream &operator<<(std::ostream &out, const Fixed &fixedNB)
{
	out << fixedNB.toFloat();
	return out;
}

//operateur de comparaison
bool	operator==(Fixed const &a, Fixed const &b)
{
	return a.getRawBits() == b.getRawBits();
}

bool	operator!=(Fixed const &a, Fixed const &b)
{
	return !(a == b);
}

bool	operator<(Fixed const &a, Fixed const &b) 
{
	return (a.getRawBits() < b.getRawBits());
}

bool	operator>(Fixed const &a, Fixed const &b) 
{
	return (a.getRawBits() > b.getRawBits());
}

bool	operator<=(Fixed const &a, Fixed const &b)
{
	return (a.getRawBits() <= b.getRawBits());
}
bool	operator>=(Fixed const &a, Fixed const &b)
{
	return (a.getRawBits() >= b.getRawBits());
}

//pre incrementation
Fixed &Fixed::operator++()
{
	++nb;
	return *this;
}

Fixed &Fixed::operator--()
{
	--nb;
	return *this;
}

// post-incrementation
Fixed Fixed::operator++(int)
{
	Fixed temp = *this;
	++(*this);
	return temp;
}

Fixed Fixed::operator--(int)
{
	Fixed temp = *this;
	--(*this);
	return temp;
}

Fixed Fixed::operator+(Fixed const &fixed)
{
	Fixed res(this->toFloat() + fixed.toFloat());
	return (res);
}

Fixed Fixed::operator-(Fixed const &fixed)
{
	Fixed res(this->toFloat() - fixed.toFloat());
	return (res);
}

Fixed Fixed::operator*(Fixed const &fixed)
{
	Fixed res(this->toFloat() * fixed.toFloat());
	return (res);
}

Fixed Fixed::operator/(Fixed const &fixed)
{
	Fixed res(this->toFloat() / fixed.toFloat());
	return (res);
}

Fixed &Fixed::min(Fixed &ref1, Fixed &ref2)
{
	return (ref1 < ref2) ? ref1 : ref2;
}

const Fixed &Fixed::min(Fixed const &ref1, Fixed const &ref2)
{
	return (ref1 < ref2) ? ref1 : ref2;
}

Fixed &Fixed::max(Fixed &ref1, Fixed &ref2)
{
	return (ref1 > ref2) ? ref1 : ref2;
}

const Fixed &Fixed::max(Fixed const &ref1, Fixed const &ref2)
{
	return (ref1 > ref2) ? ref1 : ref2;
}
