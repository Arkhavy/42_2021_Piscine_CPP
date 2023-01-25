/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljohnson <ljohnson@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 13:03:16 by ljohnson          #+#    #+#             */
/*   Updated: 2023/01/25 16:02:59 by ljohnson         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <ScavTrap.hpp>
#include <FragTrap.hpp>
#include <DiamondTrap.hpp>

// int	main(void)
// {
// 	ClapTrap	cp1;
// 	ScavTrap	sp1;
// 	FragTrap	fp1;

// 	std::cout << "--------------------" << std::endl;
	
// 	ClapTrap	cp2("Ouaf");
// 	ScavTrap	sp2("Graou");
// 	FragTrap	fp2("Meow");

// 	std::cout << "--------------------" << std::endl;

// 	ClapTrap	cp3(cp2);
// 	ScavTrap	sp3(sp2);
// 	FragTrap	fp3(fp2);
	
// 	std::cout << "--------------------" << std::endl;
// 	cp3.attack("Minion");
// 	cp3.beRepaired(2);
// 	cp3.takeDamage(3);
// 	cp3.beRepaired(2);

// 	std::cout << std::endl;
// 	sp3.attack("Minion");
// 	sp3.beRepaired(2);
// 	sp3.takeDamage(3);
// 	sp3.beRepaired(2);
// 	sp3.guardGate();

// 	std::cout << std::endl;
// 	fp3.attack("Minion");
// 	fp3.beRepaired(2);
// 	fp3.takeDamage(3);
// 	fp3.beRepaired(2);
// 	fp3.highFivesGuys();

// 	std::cout << "--------------------" << std::endl;
// 	return (0);
// }

int	main(void)
{
	DiamondTrap	dp1;

	dp1.whoAmI();
	dp1.attack("Minion");

	std::cout << "--------------------" << std::endl;
	DiamondTrap	dp2("ouaf");

	dp2.whoAmI();
	dp2.attack("Minion");

	std::cout << "--------------------" << std::endl;
	DiamondTrap	dp3(dp2);

	dp3.whoAmI();
	dp3.attack("Minion");

	std::cout << "--------------------" << std::endl;
	return (0);
}
