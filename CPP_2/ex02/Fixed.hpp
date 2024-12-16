/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ple-guya <ple-guya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 11:48:17 by ple-guya          #+#    #+#             */
/*   Updated: 2024/12/09 17:50:43 by ple-guya         ###   ########.fr       */
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
		//constructor
		Fixed();
		Fixed(const Fixed &fixedNB);
		Fixed(const int intvalue);
		Fixed(const float floatvalue);
		//member functions
		float	toFloat(void) const;
		int		toInt(void) const;
		int		getRawBits( void ) const;
		void	setRawBits( int const raw );
		//operateur
		Fixed	&operator=(const Fixed &fixedNB);
		friend	std::ostream &operator<<(std::ostream &out, const Fixed &fixedNB);
		//operateur d'incrementaton
		//pre-incremetation
		Fixed	&operator++(void);
		Fixed	&operator--(void);
		//post-incrementation
		Fixed	operator++(int);
		Fixed	operator--(int);
		//comparaison
		friend bool	operator==(Fixed const &a, Fixed const &b);
		friend bool operator!=(Fixed const &a, Fixed const &b);
		friend bool	operator<(Fixed const &a, Fixed const &b);
		friend bool	operator>(Fixed const &a, Fixed const &b);
		friend bool	operator<=(Fixed const &a, Fixed const &b);
		friend bool	operator>=(Fixed const &a, Fixed const &b);
		Fixed		operator+(Fixed const &fixed);
		Fixed		operator-(Fixed const &fixed);
		Fixed		operator*(Fixed const &fixed);
		Fixed		operator/(Fixed const &fixed);
		//static member function
		static const Fixed	&min(Fixed  const &ref1, const Fixed &ref2);
		static const Fixed	&max(Fixed const &ref1, Fixed const &ref2);
		static Fixed		&min(Fixed &ref1, Fixed &ref2);
		static Fixed		&max(Fixed &ref1, Fixed &ref2);
		//destructor
		~Fixed();
};

#endif