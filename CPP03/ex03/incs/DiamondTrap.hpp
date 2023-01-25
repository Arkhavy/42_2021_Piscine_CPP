/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljohnson <ljohnson@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 00:20:13 by ljohnson          #+#    #+#             */
/*   Updated: 2023/01/25 15:59:28 by ljohnson         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP

# include <ScavTrap.hpp>
# include <FragTrap.hpp>

class	DiamondTrap : public ScavTrap, public FragTrap
{
	private:
		std::string	name;
		using	FragTrap::hit_points;
		using	ScavTrap::energy_points;
		using	FragTrap::attack_damage;

		using	FragTrap::max_hit_points;
		using	ScavTrap::max_energy_points;
	
	public:
		DiamondTrap(); //Default constructor
		DiamondTrap(std::string name);
		DiamondTrap(DiamondTrap const& src); //Copy constructor
		~DiamondTrap(); //Default destructor

		void	whoAmI();

		DiamondTrap&	operator=(DiamondTrap const& rhs);
};

#endif /* DIAMONDTRAP_HPP */