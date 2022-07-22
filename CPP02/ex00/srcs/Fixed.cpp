/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljohnson <ljohnson@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 08:45:28 by ljohnson          #+#    #+#             */
/*   Updated: 2022/07/22 08:49:42 by ljohnson         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <Fixed.hpp>

Fixed::Fixed()
{
	std::cout << "\033[2m" << "Fixed Constructor called." << "\033[0m" << std::endl;
	return ;
}

Fixed::Fixed(Fixed const& src)
{
	std::cout << "\033[2m" << "Fixed Copy Constructor called." << "\033[0m" << std::endl;
	*this = src;
	return ;
}

Fixed::~Fixed()
{
	std::cout << "\033[2m" << "Fixed Destructor called." << "\033[0m" << std::endl;
	return ;
}
