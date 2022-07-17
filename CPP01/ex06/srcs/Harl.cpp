/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljohnson <ljohnson@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/17 12:36:17 by ljohnson          #+#    #+#             */
/*   Updated: 2022/07/17 13:25:31 by ljohnson         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <Harl.hpp>

/* ************************************************************************** */
/* Constructors & Destructors */
/* ************************************************************************** */
Harl::Harl()
{
	std::cout << "\033[2m" << "Harl Constructor called." << "\033[0m" << std::endl;
	return ;
}

Harl::~Harl()
{
	std::cout << "\033[2m" << "Harl Destructor called." << "\033[0m" << std::endl;
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
	if (level.empty())
		return ;
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
}