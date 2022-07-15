/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljohnson <ljohnson@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 14:59:11 by ljohnson          #+#    #+#             */
/*   Updated: 2022/07/15 13:53:38 by ljohnson         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <Zombie.hpp>

int	main(void)
{
	Zombie	stud("Normal Zombie");
	stud.announce();

	stud.randomChump("Random Chump");

	Zombie*	piscineux = stud.newZombie("New Zombie");
	piscineux->announce();

	delete piscineux;
	return (0);
}