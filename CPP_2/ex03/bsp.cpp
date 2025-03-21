/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ple-guya <ple-guya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 18:27:57 by ple-guya          #+#    #+#             */
/*   Updated: 2025/01/07 18:47:11 by ple-guya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

//structure pour un plan d'une ligne en 2D
typedef	struct s_plan
{
	Fixed	a;
	Fixed	b;
	Fixed	c;
}	t_plan;

static t_plan create_plane(Point const p1, Point const p2)
{
	t_plan	plan;
	
	plan.a = p2.getYcoord() - p1.getYcoord();
	plan.b = p1.getXcoord() - p2.getXcoord();
	plan.c = p2.getXcoord() * p1.getYcoord() - p1.getXcoord() * p2.getYcoord();
	return plan;
}

static Fixed	get_relative_position(Point const p, t_plan plan)
{
	return ((plan.a * p.getXcoord()) + (plan.b * p.getYcoord()) + plan.c);
}

bool bsp(Point const a, Point const b, Point const c, Point const point)
{
	t_plan	ab;
	t_plan	bc;
	t_plan	ca;

	ab = create_plane(a,b);
	bc = create_plane(b,c);
	ca = create_plane(c, a);
	Fixed	pos_ab = get_relative_position(point, ab);
	Fixed	pos_bc = get_relative_position(point, bc);
	Fixed	pos_ca = get_relative_position(point, ca);
	if ((pos_ab > Fixed(0) && pos_bc > Fixed(0) && pos_ca > Fixed(0)) || (pos_ab < Fixed(0) && pos_bc < Fixed(0) && pos_ca < Fixed(0)))
		return(true);
	return(false);
}