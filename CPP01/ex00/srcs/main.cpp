/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljohnson <ljohnson@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 14:59:11 by ljohnson          #+#    #+#             */
/*   Updated: 2022/11/10 15:07:02 by ljohnson         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <Zombie.hpp>

int	main(void)
{
	Zombie	stud("Normal Zombie");
	stud.announce();

	randomChump("Random Chump");

	Zombie*	piscineux = newZombie("New Zombie");
	piscineux->announce();

	delete piscineux;
	return (0);
}
