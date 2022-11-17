/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljohnson <ljohnson@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/24 15:22:21 by ljohnson          #+#    #+#             */
/*   Updated: 2022/11/17 14:20:04 by ljohnson         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <Point.hpp>

void	ft_display(Point& p, std::string name)
{
	std::cout << name << " = ";
	std::cout << "[" << &p << "]";
	std::cout << "[" << p.getFloatX() << "]";
	std::cout << "[" << p.getFloatY() << "]";
	std::cout << std::endl;
	
}

// Test Copy and copy assignment overload
// int	main(void)
// {
// 	Point p0;
// 	Point p1(1.1f, 4.2f);
// 	Point p2(p1);
// 	Point p3 = p1;

// 	p0 = p1;
// 	ft_display(p0, "p0");
// 	ft_display(p1, "p1");
// 	ft_display(p2, "p2");
// 	ft_display(p3, "p3");

// 	return (0);
// }

int	main(void)
{
	Point	pa(0, 0);
	Point	pb(10, 2);
	Point	pc(0, 15);

	ft_display(pa, "pa");
	ft_display(pb, "pb");
	ft_display(pc, "pc");
	for (float i = 0.0f; i < 20; i += 0.25f)
	{
		for (float j = 0.0f; j < 20; j += 0.25f)
		{
			Point	tmp(i, j);
			std::cout << "point ";
			if (bsp(pa, pb, pc, tmp))
				std::cout << "is ";
			else
				std::cout << "is NOT ";
			std::cout << "in Triangle ABC ! ";
			std::cout << "[" << i << "][" << j << "]" << std::endl;
		}
	}
	return (0);
}
