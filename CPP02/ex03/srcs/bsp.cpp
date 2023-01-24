/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljohnson <ljohnson@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/24 15:31:58 by ljohnson          #+#    #+#             */
/*   Updated: 2023/01/24 20:07:27 by ljohnson         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <Point.hpp>

// //Create a vector given an origin and a point
// static Point const	ft_create_vector(Point const p, Point const o)
// {
// 	float const	x = p.getFloatX() - o.getFloatX();
// 	float const	y = p.getFloatY() - o.getFloatY();

// 	Point const	v(x, y);
// 	return (v);
// }

// //Cross product of two vectors
// static Point const	ft_cross_product(Point const va, Point const vb)
// {
// 	float const	vc1 = va.getFloatX() * vb.getFloatY();
// 	float const	vc2 = va.getFloatY() * vb.getFloatX();
	
// 	Point const	vc(vc1, vc2);
// 	return (vc);
// }

// //Dot product of two vectors
// // if positive	=	angle < 90d
// // if negative	=	angle > 90d
// // if 0			=	angle == 90d
// static float	ft_dot_product(Point const va, Point const vb)
// {
// 	float	vx = va.getFloatX() * vb.getFloatX();
// 	float	vy = va.getFloatY() * vb.getFloatY();

// 	return (vx + vy);
// }

// static bool	ft_check_side(Point const p1, Point const p2, Point const a, Point const b)
// {
// 	Point const	vba(ft_create_vector(b, a));
// 	Point const	vp1(ft_create_vector(p1, a));
// 	Point const	vp2(ft_create_vector(p2, a));
// 	Point const	cp1(ft_cross_product(vba, vp1));
// 	Point const	cp2(ft_cross_product(vba, vp2));
	
// 	if (ft_dot_product(cp1, cp2) > 0)
// 		return (true);
// 	return (false);
// }

// bool bsp(Point const a, Point const b, Point const c, Point const point)
// {
// 	if (ft_check_side(point, a, b, c)
// 		&& ft_check_side(point, b, a, c)
// 		&& ft_check_side(point, c, a, b))
// 		return (true);
// 	return (false);
// }

//NEW BSP
float	get_one_point(float x, float y1, float y2) {return (x * (y1 - y2));}

float	get_triangle_area(Point const a, Point const b, Point const c)
{
	float	p1 = get_one_point(a.getFloatX(), b.getFloatY(), c.getFloatY());
	float	p2 = get_one_point(b.getFloatX(), c.getFloatY(), a.getFloatY());
	float	p3 = get_one_point(c.getFloatX(), a.getFloatY(), b.getFloatY());

	return (abs((p1 + p2 + p3) / 2.0));
}

bool	bsp(Point const a, Point const b, Point const c, Point const point)
{
	float	p = get_triangle_area(a, b, c);
	float	p1 = get_triangle_area(point, b, c);
	float	p2 = get_triangle_area(a, point, c);
	float	p3 = get_triangle_area(a, b, point);

	return (p == (p1 + p2 + p3));
}

/*
ATTENTION : SPECIAL CASES
-> If Point is on corner or side, need to return false
This actual code is not enough to cover those !

*/