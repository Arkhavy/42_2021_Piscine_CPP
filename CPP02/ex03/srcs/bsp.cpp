/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljohnson <ljohnson@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/24 15:31:58 by ljohnson          #+#    #+#             */
/*   Updated: 2023/01/25 13:00:58 by ljohnson         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <Point.hpp>

//Check point coordinates to see if it matches triangle corners
bool	check_point_coordinates(Point const a, Point const b, Point const c, Point const point)
{
	if (point.getFloatX() == a.getFloatX() && point.getFloatY() == a.getFloatY())
		return (true);
	else if (point.getFloatX() == b.getFloatX() && point.getFloatY() == b.getFloatY())
		return (true);
	else if (point.getFloatX() == c.getFloatX() && point.getFloatY() == c.getFloatY())
		return (true);
	return (false);
}

float	get_area(Point const point, Point const a, Point const b)
{
	float	apx = (a.getFloatX() - point.getFloatX());
	float	apy = (a.getFloatY() - point.getFloatY());
	float	bpx = (b.getFloatX() - point.getFloatX());
	float	bpy = (b.getFloatY() - point.getFloatY());

	return ((apx * bpy) - (apy * bpx));
}

bool	bsp(Point const a, Point const b, Point const c, Point const point)
{
	if (check_point_coordinates(a, b, c, point))
		return (false);

	float	AB = get_area(point, a, b);
	float	AC = get_area(point, c, a);
	float	BC = get_area(point, b, c);

	if ((AB > 0 && AC > 0 && BC > 0) || (AB < 0 && AC < 0 && BC < 0))
		return (true);
	return (false);
}
