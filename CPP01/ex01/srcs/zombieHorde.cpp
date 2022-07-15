/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljohnson <ljohnson@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 11:24:03 by ljohnson          #+#    #+#             */
/*   Updated: 2022/07/15 11:34:01 by ljohnson         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/Zombie.hpp"

Zombie*	Zombie::zombieHorde(int N, std::string name)
{
	Zombie*	zombieHorde;

	if (N <= 0)
		return (NULL);
	//will need to watch intra videos
	for (int i = 0; i < N; i++)
		zombieHorde[i] = this->newZombie(name);
	return (zombieHorde);
}