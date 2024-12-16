/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ple-guya <ple-guya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 18:07:18 by ple-guya          #+#    #+#             */
/*   Updated: 2024/12/14 20:46:33 by ple-guya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
#define POINT_HPP

#include "Fixed.hpp"

class Point
{
	private:
		Fixed	x;
		Fixed	y;
	public:
		Point();
		Point(const Fixed &coord_x, const Fixed &coord_y);
		Point(const Point &cpy);
		Point	&operator=(const Point &cpy);
		Fixed	getXcoord(void) const;
		Fixed	getYcoord(void) const;
		~Point();
};

bool	bsp(Point const a, Point const b, Point const c, Point const point);

#endif