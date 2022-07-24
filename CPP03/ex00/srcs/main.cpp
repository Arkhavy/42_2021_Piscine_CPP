/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbire <sbire@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/24 16:53:06 by sbire          #+#    #+#             */
/*   Updated: 2022/07/24 17:50:02 by sbire         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <ClapTrap.hpp>

int	main(void)
{
	ClapTrap	sbire("Sbire");
	ClapTrap	piscineux;

	sbire.attack("CL4P-TP"); //OK -1EP
	piscineux.takeDamage(2); //OK -2HP
	piscineux.beRepaired(2); //OK -1EP +2HP
	piscineux.beRepaired(2); //Error case HP = 10
	std::cout << std::endl;

	for (int i = 0; i < 10; i++) //-10 EP, last one Error case EP = 0
		sbire.attack("CL4P-TP");
	std::cout << std::endl;

	for (int i = 0; i < 3; i++) //-9HP, all OK
		piscineux.takeDamage(3);
	std::cout << std::endl;

	piscineux.takeDamage(2); //Overkill case
	piscineux.takeDamage(2); //Error case HP = 0
	std::cout << std::endl;

	piscineux.beRepaired(3); //Error case HP = 0
	sbire.beRepaired(3); //Error case HP = 10
	std::cout << std::endl;

	sbire.attack("CL4P-TP"); //Error case EP = 0
	piscineux.attack("Sbire"); //Error case HP = 0
	return (0);
}