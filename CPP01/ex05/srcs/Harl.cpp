/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Karen.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljohnson <ljohnson@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/17 13:30:10 by ljohnson          #+#    #+#             */
/*   Updated: 2023/01/19 13:25:42 by ljohnson         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <Harl.hpp>
int	print_error(std::string message);

/* ************************************************************************** */
/* Constructors & Destructors */
/* ************************************************************************** */
Harl::Harl()
{
	std::cout << "\033[2m";
	std::cout << "Harl Constructor called.";
	std::cout << "\033[0m" << std::endl;
	return ;
}

Harl::~Harl()
{
	std::cout << "\033[2m";
	std::cout << "Harl Destructor called.";
	std::cout << "\033[0m" << std::endl;
	return ;
}


/* ************************************************************************** */
/* Private member functions */
/* ************************************************************************** */
void	Harl::debug() {std::cout << "Debug : Ouaf" << std::endl;}

void	Harl::info() {std::cout << "Info : Woof" << std::endl;}

void	Harl::warning() {std::cout << "Warning : Bark" << std::endl;}

void	Harl::error() {std::cout << "Error : Meow" << std::endl;}

/* ************************************************************************** */
/* Public member functions */
/* ************************************************************************** */
void	Harl::complain(std::string level)
{
	std::string	level_type[4] =
			{
				"DEBUG",
				"INFO",
				"WARNING",
				"ERROR"
			};
	void	(Harl::*func[4])(void) =
			{
				&Harl::debug,
				&Harl::info,
				&Harl::warning,
				&Harl::error
			};

	if (!level.empty())
	{
		for (int i = 0; i < (int)level.size(); i++)
			level[i] = std::toupper(level[i]);
		for (int i = 0; i < 4; i++)
		{
			if (level == level_type[i])
			{
				(this->*func[i])();
				return ;
			}
		}
	}
	print_error("Argument given is not a level ! Try DEBUG, INFO, WARNING or ERROR !");
}
