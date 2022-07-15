/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljohnson <ljohnson@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 11:23:48 by ljohnson          #+#    #+#             */
/*   Updated: 2022/07/15 13:53:24 by ljohnson         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <Zombie.hpp>

int	main(void)
{
	Zombie		firstZombie("ljohnson");
	Zombie*		zombieHorde;
	int const	N = 5;

	firstZombie.announce();

	zombieHorde = firstZombie.zombieHorde(5, "Horde");
	for (int i = 0; i < N; i++)
		zombieHorde[i].announce();
	
	delete [] zombieHorde;
	return (0);
}