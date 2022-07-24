/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljohnson <ljohnson@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/24 15:29:08 by ljohnson          #+#    #+#             */
/*   Updated: 2022/07/24 15:48:48 by ljohnson         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <Point.hpp>

/* ************************************************************************** */
/* Constructor & Destructors */
/* ************************************************************************** */
Point::Point() : x(0), y(0)
{
	std::cout << "\033[2m" << "Default Point constructor called" << "\033[0m" << std::endl;
	return ;
}

Point::Point(float const x, float const y) : x(x), y(y)
{
	std::cout << "\033[2m" << "Second Point constructor called" << "\033[0m" << std::endl;
	return ;
}

Point::Point(Point const& src)
{
	std::cout << "\033[2m" << "Copy Point constructor called" << "\033[0m" << std::endl;
	*this = src;
	return ;
}

Point::~Point()
{
	std::cout << "\033[2m" << "Point destructor called" << "\033[0m" << std::endl;
	return ;
}

Point&	Point::operator=(Point const& rhs)
{
	//Fixed const wut ?
	return (*this);
}