/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   newZombie.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljohnson <ljohnson@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 11:22:21 by ljohnson          #+#    #+#             */
/*   Updated: 2022/11/10 15:25:02 by ljohnson         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <Zombie.hpp>

Zombie*	newZombie(std::string name)
{
	Zombie*	new_zombie;
	
	new_zombie = new Zombie(name);
	return (new_zombie);
}
