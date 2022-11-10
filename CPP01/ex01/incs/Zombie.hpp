/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljohnson <ljohnson@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 11:15:49 by ljohnson          #+#    #+#             */
/*   Updated: 2022/11/10 15:32:00 by ljohnson         ###   ########lyon.fr   */
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

		void	setName(std::string name);
		void	announce() const;

};

Zombie*	newZombie(std::string name);
void	randomChump(std::string name);

Zombie*	zombieHorde(int N, std::string name);

#endif /* ZOMBIE_HPP */