/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ple-guya <ple-guya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 18:16:09 by ple-guya          #+#    #+#             */
/*   Updated: 2025/01/14 16:36:00 by ple-guya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"
#include "Fixed.hpp"

/*********************************/
/*    Constructor & destructor   */
/*********************************/

Point::Point() : x(0) , y(0) {}

Point::Point(const Fixed &coord_x,const Fixed &coord_y) : x(coord_x) , y(coord_y) {}

Point::Point(const Point &cpy) : x(cpy.x), y(cpy.y) {}

Point::~Point() {}

/*********************************/
/*            getter             */
/*********************************/

Fixed	Point::getXcoord(void) const {return this->x;}

Fixed	Point::getYcoord(void) const {return this->y;}

/*********************************/
/*     surcharge d'oprateur      */
/*********************************/

Point	&Point::operator=(const Point &cpy)
{
	if (this != &cpy)
	{
		x = cpy.getXcoord();
		y = cpy.getYcoord();
	}
	return(*this);
}
