/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maintest.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljohnson <ljohnson@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 19:07:44 by ljohnson          #+#    #+#             */
/*   Updated: 2023/02/22 19:30:20 by ljohnson         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cstdlib>
#include <string>
#include <climits>
#include <cfloat>


int	main(int ac, char** av)
{
	if (ac != 2)
		return (1);
	std::string	str = av[1];
	// long int	a = std::strtol(str.data(), NULL, 10);
	// if (*endp != 0)
	// {
	// 	std::cout << "overflow woo: " << a << std::endl;
	// }
	// else if (endp == str.c_str())
	// {
	// 	std::cout << "overflow woo: " << a << std::endl;
	// }
	return (0);
}