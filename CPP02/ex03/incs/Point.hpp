/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljohnson <ljohnson@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/24 15:28:07 by ljohnson          #+#    #+#             */
/*   Updated: 2023/01/24 08:37:51 by ljohnson         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
# define POINT_HPP

# include <Fixed.hpp>

class	Point
{
	private:
		Fixed const	x;
		Fixed const	y;

	public:
		Point(); //Default constructor
		Point(float const x, float const y);
		Point(Point const& src); //Copy constructor
		~Point(); //Default destructor

		float	getFloatX() const;
		float	getFloatY() const;

		Point&	operator=(Point const& rhs);
};

bool bsp( Point const a, Point const b, Point const c, Point const point);

#endif /* POINT_HPP */