/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljohnson <ljohnson@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 15:00:49 by ljohnson          #+#    #+#             */
/*   Updated: 2022/07/16 16:14:29 by ljohnson         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <fstream>

int	main(void)
{
	std::ifstream	ifs("ouaf");
	int				ia = 20;
	int				ib = 10;

	ifs >> ia >> ib;

	std::cout << ia << " " << ib << std::endl;
	ifs.close();
	return (0);
}