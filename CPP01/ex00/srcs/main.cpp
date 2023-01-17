/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljohnson <ljohnson@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 14:59:11 by ljohnson          #+#    #+#             */
/*   Updated: 2023/01/17 08:23:29 by ljohnson         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <Zombie.hpp>

int	main(void)
{
	Zombie	normal_z("Normal Zombie");
	normal_z.announce();

	Zombie*	new_z = newZombie("New Zombie");
	randomChump("Random Chump");
	new_z->announce();

	delete new_z;
	return (0);
}
