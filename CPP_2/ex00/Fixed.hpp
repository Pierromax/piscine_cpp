/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ple-guya <ple-guya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 11:48:17 by ple-guya          #+#    #+#             */
/*   Updated: 2024/12/09 13:47:10 by ple-guya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <string>
#include <iostream>

class Fixed
{
	private:
		int					nb;
		static const int	nb_bit;
	public:
		Fixed();
		Fixed(const Fixed &fixedNB);
		Fixed &operator=(const Fixed &fixedNB);
		int getRawBits( void ) const;
		void setRawBits( int const raw );
		~Fixed();
};

#endif