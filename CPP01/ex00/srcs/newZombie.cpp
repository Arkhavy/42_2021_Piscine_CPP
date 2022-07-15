/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   newZombie.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljohnson <ljohnson@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 14:58:42 by ljohnson          #+#    #+#             */
/*   Updated: 2022/07/15 09:57:28 by ljohnson         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <Zombie.Class.hpp>

Zombie*	Zombie::newZombie(std::string name)
{
	Zombie* newZombie = new Zombie(name);
	return (newZombie);
}
