/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   newZombie.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljohnson <ljohnson@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 14:58:42 by ljohnson          #+#    #+#             */
/*   Updated: 2023/01/19 13:33:55 by ljohnson         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <Zombie.hpp>

Zombie*	newZombie(std::string name)
{
	Zombie*	new_zombie;
	
	new_zombie = new Zombie(name);
	return (new_zombie);
}
