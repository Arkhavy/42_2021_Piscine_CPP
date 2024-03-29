/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljohnson <ljohnson@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 12:15:08 by ljohnson          #+#    #+#             */
/*   Updated: 2022/12/07 12:47:55 by ljohnson         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

# include <ClapTrap.hpp>

class ScavTrap : public ClapTrap
{
	public:
		ScavTrap(); //Default constructor
		ScavTrap(std::string name);
		ScavTrap(ScavTrap const& src); //Copy constructor
		~ScavTrap(); //Default destructor

		void	attack(const std::string& target);
		void	guardGate();

		ScavTrap&	operator=(ScavTrap const& rhs);
};

#endif /* SCAVTRAP_HPP */