/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljohnson <ljohnson@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 11:23:48 by ljohnson          #+#    #+#             */
/*   Updated: 2023/01/17 08:52:10 by ljohnson         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <Zombie.hpp>

int	main(void)
{
	Zombie		first_z("ljohnson");
	Zombie		default_z;
	Zombie*		horde_z;
	int const	N = 5;

	first_z.announce();
	default_z.announce();

	horde_z = zombieHorde(N, "Horde");
	for (int i = 0; i < N; i++)
		horde_z[i].announce();

	delete [] horde_z;
	return (0);
}
