/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ple-guya <ple-guya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 11:48:17 by ple-guya          #+#    #+#             */
/*   Updated: 2025/01/16 14:40:20 by ple-guya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <string>
#include <iostream>
#include <cmath>

class Fixed
{
	private:
		int					nb;
		static const int	nb_bit = 8;
	public:
		Fixed();
		Fixed(const Fixed &fixedNB);
		Fixed(const int intvalue);
		Fixed(const float floatvalue);
		Fixed &operator=(const Fixed &fixedNB);
		float toFloat(void) const;
		int toInt(void) const;
		int getRawBits( void ) const;
		void setRawBits( int const raw );
		~Fixed();
};

std::ostream &operator<<(std::ostream &out, const Fixed &fixedNB);

#endif