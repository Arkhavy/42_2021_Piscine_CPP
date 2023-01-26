/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljohnson <ljohnson@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 00:20:13 by ljohnson          #+#    #+#             */
/*   Updated: 2023/01/26 08:57:35 by ljohnson         ###   ########lyon.fr   */
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
	
	public:
		DiamondTrap(); //Default constructor
		DiamondTrap(std::string name);
		DiamondTrap(DiamondTrap const& src); //Copy constructor
		~DiamondTrap(); //Default destructor

		void	whoAmI();

		DiamondTrap&	operator=(DiamondTrap const& rhs);
};

#endif /* DIAMONDTRAP_HPP */