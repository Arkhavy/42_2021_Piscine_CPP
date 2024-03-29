/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljohnson <ljohnson@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 18:27:14 by ljohnson          #+#    #+#             */
/*   Updated: 2022/12/07 18:30:15 by ljohnson         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

# include <ClapTrap.hpp>

class FragTrap : public ClapTrap
{
	public:
		FragTrap(); //Default constructor
		FragTrap(std::string name);
		FragTrap(FragTrap const& src); //Copy constructor
		~FragTrap(); //Default destructor

		void	highFivesGuys(void);

		FragTrap&	operator=(FragTrap const& rhs);
};

#endif /* FRAGTRAP_HPP */