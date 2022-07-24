/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljohnson <ljohnson@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/24 08:45:43 by ljohnson          #+#    #+#             */
/*   Updated: 2022/07/24 10:40:37 by ljohnson         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <Fixed.hpp>

int	main(void)
{
	Fixed	a(10);
	Fixed	b(5);

	std::cout << "a = " << a << std::endl;
	std::cout << "b = " << b << std::endl;
	std::cout << std::endl;

	std::cout << "aRaw = " << a.getRawBits() << std::endl;
	std::cout << "bRaw = " << b.getRawBits() << std::endl;
	std::cout << std::endl;
	
	std::cout << "a + b = ";
	std::cout << a + b << std::endl;
	std::cout << std::endl;
	
	std::cout << "a - b = ";
	std::cout << a - b << std::endl;
	std::cout << std::endl;
	
	std::cout << "a / b = ";
	std::cout << a / b << std::endl;
	std::cout << std::endl;
	
	std::cout << "a * b = ";
	std::cout << a * b << std::endl;
	std::cout << std::endl;

	std::cout << "---------------------------" << std::endl << std::endl;
	a.setRawBits(20);
	b.setRawBits(4);

	std::cout << "a = " << a << std::endl;
	std::cout << "b = " << b << std::endl;
	std::cout << std::endl;

	std::cout << "aRaw = " << a.getRawBits() << std::endl;
	std::cout << "bRaw = " << b.getRawBits() << std::endl;
	std::cout << std::endl;
	
	std::cout << "a + b = ";
	std::cout << a + b << std::endl;
	std::cout << std::endl;
	
	std::cout << "a - b = ";
	std::cout << a - b << std::endl;
	std::cout << std::endl;
	
	std::cout << "a / b = ";
	std::cout << a / b << std::endl;
	std::cout << std::endl;
	
	std::cout << "a * b = ";
	std::cout << a * b << std::endl;
	std::cout << std::endl;
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
