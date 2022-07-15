/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.Class.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljohnson <ljohnson@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 14:41:26 by ljohnson          #+#    #+#             */
/*   Updated: 2022/07/15 09:56:29 by ljohnson         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_CLASS_HPP
# define ZOMBIE_CLASS_HPP

# include <iostream>
# include <string>

class	Zombie
{
	private:
		std::string	name;

	public:
		Zombie(std::string name);
		~Zombie();

		void announce();
		Zombie* newZombie(std::string name);
		void randomChump(std::string name);
};

#endif /* ZOMBIE_CLASS_HPP */