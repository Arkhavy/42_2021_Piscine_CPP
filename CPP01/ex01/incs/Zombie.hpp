/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljohnson <ljohnson@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 11:15:49 by ljohnson          #+#    #+#             */
/*   Updated: 2022/07/15 13:37:35 by ljohnson         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <iostream>
# include <string>

class	Zombie
{
	private:
		std::string	name;

	public:
		Zombie();
		Zombie(std::string name);
		~Zombie();

		void	announce();
		Zombie*	newZombie(std::string name);
		void	randomChump(std::string name);

		Zombie*	zombieHorde(int N, std::string name);
};

#endif /* ZOMBIE_HPP */