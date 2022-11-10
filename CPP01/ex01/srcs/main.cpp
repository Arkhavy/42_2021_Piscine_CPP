/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljohnson <ljohnson@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 11:23:48 by ljohnson          #+#    #+#             */
/*   Updated: 2022/11/10 15:35:30 by ljohnson         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <Zombie.hpp>

int	main(void)
{
	Zombie		first_zombie("ljohnson");
	Zombie*		zombie_horde;
	int const	N = 5;

	first_zombie.announce();

	zombie_horde = zombieHorde(N, "Horde");
	for (int i = 0; i < N; i++)
		zombie_horde[i].announce();

	delete [] zombie_horde;
	return (0);
}
