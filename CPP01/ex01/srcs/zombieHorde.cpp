/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljohnson <ljohnson@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 11:24:03 by ljohnson          #+#    #+#             */
/*   Updated: 2022/07/15 13:46:50 by ljohnson         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <Zombie.hpp>

Zombie*	Zombie::zombieHorde(int N, std::string name)
{
	Zombie*	zombieHorde;

	if (N <= 0)
		return (NULL);
	zombieHorde = new Zombie[N];
	for (int i = 0; i < N; i++)
		zombieHorde[i].name = name;
	return (zombieHorde);
}