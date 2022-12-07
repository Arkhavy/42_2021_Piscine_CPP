/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljohnson <ljohnson@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 13:03:16 by ljohnson          #+#    #+#             */
/*   Updated: 2022/12/07 13:29:35 by ljohnson         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <ScavTrap.hpp>

int	main(void)
{
	ClapTrap	cp1;
	ScavTrap	sp1;
	
	std::cout << "--------------------" << std::endl;

	ClapTrap	cp2("ouaf");
	ScavTrap	sp2("graou");

	std::cout << "--------------------" << std::endl;

	ClapTrap	cp3(cp2);
	ScavTrap	sp3(sp2);
	std::cout << "--------------------" << std::endl;

	ClapTrap	cp4("sbire");
	ScavTrap	sp4("guardian");

	cp4.attack("guardian");
	sp4.guardGate();
	sp4.takeDamage(0); // OK -0HP
	sp4.beRepaired(2); // Error Case HP max
	sp4.takeDamage(1); // OK -1HP
	sp4.beRepaired(2); // Semi Error Case beyond HP max
	sp4.attack("sbire");
	cp4.takeDamage(20); // One Shot lol

	std::cout << "--------------------" << std::endl;
	return (0);
}
