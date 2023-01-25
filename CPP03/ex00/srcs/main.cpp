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
	ClapTrap	minion("Minion");
	ClapTrap	clap;

	minion.attack("CL4P-TP"); //OK -1EP
	clap.takeDamage(2); //OK -2HP
	clap.beRepaired(2); //OK -1EP +2HP
	clap.beRepaired(2); //Error case HP = 10
	std::cout << std::endl;

	for (int i = 0; i < 10; i++) //-10 EP, last one Error case EP = 0
		minion.attack("CL4P-TP");
	std::cout << std::endl;

	for (int i = 0; i < 3; i++) //-9HP, all OK
		clap.takeDamage(3);
	std::cout << std::endl;

	clap.takeDamage(2); //1HP -2HP, Overkill case
	clap.takeDamage(2); //Error case HP = 0
	std::cout << std::endl;

	clap.beRepaired(3); //Error case HP = 0
	minion.beRepaired(3); //Error case HP = 10
	std::cout << std::endl;

	minion.attack("CL4P-TP"); //Error case EP = 0
	clap.attack("Minion"); //Error case HP = 0

	std::cout << "----------------------" << std::endl;

	ClapTrap	copyTrap(minion);

	copyTrap.attack("ouaf");
	copyTrap.beRepaired(2);
	copyTrap.takeDamage(4);
	copyTrap.beRepaired(2);
	return (0);
}
