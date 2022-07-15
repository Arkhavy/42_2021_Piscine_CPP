/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljohnson <ljohnson@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 14:44:50 by ljohnson          #+#    #+#             */
/*   Updated: 2022/07/15 11:08:03 by ljohnson         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <Zombie.hpp>

Zombie::Zombie(std::string name)
{
	this->name = name;
	std::cout << "\033[2m" << "Constructor of " << this->name << " called." << "\033[0m" << std::endl;
	return ;
}

Zombie::~Zombie()
{
	std::cout << "\033[2m" << "Destructor of " << this->name << " called." << "\033[0m" << std::endl;
	return ;
}

void	Zombie::announce()
{
	std::cout << this->name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}
