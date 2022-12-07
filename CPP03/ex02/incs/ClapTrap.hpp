/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljohnson <ljohnson@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/24 17:59:47 by ljohnson          #+#    #+#             */
/*   Updated: 2022/12/07 13:26:51 by ljohnson         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# include <iostream>
# include <string>

class	ClapTrap
{
	protected:
		std::string		name;
		unsigned int	hit_points;
		unsigned int	energy_points;
		unsigned int	attack_damage;

		unsigned int	max_hit_points;
		unsigned int	max_energy_points;

	public:
		ClapTrap(); //Default constructor
		ClapTrap(std::string name);
		ClapTrap(ClapTrap const& src); //Copy constructor
		~ClapTrap(); //Default destructor
		
		void	attack(const std::string& target);
		void	takeDamage(unsigned int amount);
		void	beRepaired(unsigned int amount);
		
		ClapTrap&	operator=(ClapTrap const& rhs);
};

#endif /* CLAPTRAP_HPP */