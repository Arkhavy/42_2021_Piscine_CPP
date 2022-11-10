/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Karen.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljohnson <ljohnson@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/17 13:30:10 by ljohnson          #+#    #+#             */
/*   Updated: 2022/07/17 16:02:42 by ljohnson         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <Karen.hpp>
int	print_error(std::string message);

/* ************************************************************************** */
/* Constructors & Destructors */
/* ************************************************************************** */
Karen::Karen()
{
	std::cout << "\033[2m";
	std::cout << "Karen Constructor called.";
	std::cout << "\033[0m" << std::endl;
	return ;
}

Karen::~Karen()
{
	std::cout << "\033[2m";
	std::cout << "Karen Destructor called.";
	std::cout << "\033[0m" << std::endl;
	return ;
}


/* ************************************************************************** */
/* Private member functions */
/* ************************************************************************** */
void	Karen::debug() {std::cout << "Debug : Ouaf" << std::endl;}

void	Karen::info() {std::cout << "Info : Woof" << std::endl;}

void	Karen::warning() {std::cout << "Warning : Bark" << std::endl;}

void	Karen::error() {std::cout << "Error : Meow" << std::endl;}

/* ************************************************************************** */
/* Public member functions */
/* ************************************************************************** */
void	Karen::complain(std::string level)
{
	std::string	level_type[4] =
			{
				"DEBUG",
				"INFO",
				"WARNING",
				"ERROR"
			};
	void	(Karen::*func[4])(void) =
			{
				&Karen::debug,
				&Karen::info,
				&Karen::warning,
				&Karen::error
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
