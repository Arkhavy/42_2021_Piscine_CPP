/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljohnson <ljohnson@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 13:03:16 by ljohnson          #+#    #+#             */
/*   Updated: 2023/01/25 14:26:32 by ljohnson         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <ScavTrap.hpp>

void	test_virtual(ClapTrap& vt)
{
	vt.attack("Ouaf");
}

int	main(void)
{
	ClapTrap	cp1;
	ScavTrap	sp1;
	
	std::cout << "--------------------" << std::endl;

	ClapTrap	cp2("Ouaf");
	ScavTrap	sp2("Graou");

	std::cout << "--------------------" << std::endl;

	ClapTrap	cp3(cp2);
	ScavTrap	sp3(sp2);

	std::cout << "--------------------" << std::endl;

	ClapTrap	cp4("Minion");
	ScavTrap	sp4("Guardian");

	std::cout << "--------------------" << std::endl;

	cp4.attack("Guardian");
	sp4.guardGate();
	sp4.takeDamage(0); // OK -0HP
	sp4.beRepaired(2); // Error Case HP max
	sp4.takeDamage(1); // OK -1HP
	sp4.beRepaired(2); // Semi Error Case beyond HP max
	sp4.attack("Minion");
	cp4.takeDamage(20); // One Shot lol

	std::cout << "--------------------" << std::endl;
	test_virtual(sp4);
	return (0);
}
