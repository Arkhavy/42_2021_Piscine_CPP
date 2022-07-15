/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljohnson <ljohnson@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 14:59:11 by ljohnson          #+#    #+#             */
/*   Updated: 2022/07/15 10:53:07 by ljohnson         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <Zombie.Class.hpp>

int	main(void)
{
	Zombie	stud("Skunk");
	stud.announce();

	stud.randomChump("Worm");

	Zombie*	piscineux = stud.newZombie("Blobfish");
	piscineux->announce();

	delete piscineux;
}