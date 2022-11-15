/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljohnson <ljohnson@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/24 08:45:43 by ljohnson          #+#    #+#             */
/*   Updated: 2022/11/15 11:06:57 by ljohnson         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <Fixed.hpp>

static void	display(Fixed& a, Fixed& b)
{
	std::cout << "a = " << a << std::endl;
	std::cout << "b = " << b << std::endl;
	std::cout << "aRaw = " << a.getRawBits() << std::endl;
	std::cout << "bRaw = " << b.getRawBits() << std::endl;
	std::cout << std::endl;

	std::cout << "a + b = " << (a + b) << std::endl;
	std::cout << "a - b = " << (a - b) << std::endl;
	std::cout << "a / b = " << (a / b) << std::endl;
	std::cout << "a * b = " << (a * b) << std::endl;
	std::cout << std::endl;

	std::cout << "a > b = " << (a > b) << std::endl;
	std::cout << "a < b = " << (a < b) << std::endl;
	std::cout << "a <= b = " << (a <= b) << std::endl;
	std::cout << "a >= b = " << (a >= b) << std::endl;
	std::cout << "a == b = " << (a == b) << std::endl;
	std::cout << "a != b = " << (a != b) << std::endl;
	std::cout << std::endl;

	std::cout << "a.min(a, b) = " << a.min(a, b) << std::endl;
	std::cout << "a.min(b, a) = " << a.min(b, a) << std::endl;
	std::cout << "b.min(a, b) = " << b.min(a, b) << std::endl;
	std::cout << "b.min(b, a) = " << b.min(b, a) << std::endl;
	std::cout << std::endl;

	std::cout << "a.max(a, b) = " << a.max(a, b) << std::endl;
	std::cout << "a.max(b, a) = " << a.max(b, a) << std::endl;
	std::cout << "b.max(a, b) = " << b.max(a, b) << std::endl;
	std::cout << "b.max(b, a) = " << b.max(b, a) << std::endl;
	std::cout << std::endl;
}

int	main(void)
{
	Fixed	a(10);
	Fixed	b(5);

	display(a, b);

	std::cout << "---------------------------" << std::endl << std::endl;

	a.setRawBits(5120); // 20
	b.setRawBits(1024); // 4
	display(a, b);

	std::cout << "---------------------------" << std::endl << std::endl;

	a.setRawBits(12800); // 50
	b.setRawBits(12800); // 50
	display(a, b);

	std::cout << "---------------------------" << std::endl << std::endl;
	a.setRawBits(2688); // 10.5f
	b.setRawBits(640); // 2.5f
	display(a, b);

	std::cout << "---------------------------" << std::endl << std::endl;
	// 6600
	// 7897
	a.setRawBits(6600); // 25.78f
	b.setRawBits(7897); // 30.848f
	display(a, b);

	std::cout << "---------------------------" << std::endl << std::endl;
	a.setRawBits(0);
	b.setRawBits(0);
	display(a, b);
	return (0);
}

// int	main(void)
// {
// 	Fixed a;
// 	Fixed const b(Fixed(5.05f) * Fixed(2));

// 	std::cout << a << std::endl;
// 	std::cout << ++a << std::endl;
// 	std::cout << a << std::endl;
// 	std::cout << a++ << std::endl;
// 	std::cout << a << std::endl;
// 	std::cout << b << std::endl;
// 	std::cout << Fixed::max(a, b) << std::endl;
// 	return (0);
// }
