/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Karen.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljohnson <ljohnson@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/17 12:36:17 by ljohnson          #+#    #+#             */
/*   Updated: 2022/07/17 16:02:34 by ljohnson         ###   ########lyon.fr   */
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
	if (!level.empty())
	{
		for (int i = 0; i < (int)level.size(); i++)
			level[i] = std::toupper(level[i]);
		switch (level[0])
		{
			case 'D':
				this->debug();
			case 'I':
				this->info();
			case 'W':
				this->warning();
			case 'E':
				this->error();
		}
		return ;
	}
	print_error("Argument given is not a level ! Try DEBUG, INFO, WARNING or ERROR !");
}