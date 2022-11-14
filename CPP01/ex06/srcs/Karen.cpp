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
// Function ptr solution, might not be the one wanted by the exercise
// void	Karen::complain(std::string level)
// {
// 	std::string	level_type[4] =
// 			{
// 				"DEBUG",
// 				"INFO",
// 				"WARNING",
// 				"ERROR"
// 			};
// 	void	(Karen::*func[4])(void) =
// 			{
// 				&Karen::debug,
// 				&Karen::info,
// 				&Karen::warning,
// 				&Karen::error
// 			};
// 	int	count = 5;
	
// 	if (!level.empty())
// 	{
// 		for (int i = 0; i < (int)level.size(); i++)
// 			level[i] = std::toupper(level[i]);
// 		for (int i = 0; i < 4; i++)
// 		{
// 			if (!level_type[i].compare(level))
// 			{
// 				count = i;
// 				break ;
// 			}
// 		}
// 		for (int i = 4; count < i; count++)
// 			(this->*func[count])();
// 	}
// 	if (count == 5)
// 		print_error("Argument given is not a level ! Try DEBUG, INFO, WARNING or ERROR !");
// }

// Switch Fallthrough solution, bad practice ?
// void	Karen::complain(std::string level)
// {
// 	if (!level.empty())
// 	{
// 		for (int i = 0; i < (int)level.size(); i++)
// 			level[i] = std::toupper(level[i]);
// 		switch (level[0])
// 		{
// 			case 'D':
// 				this->debug();
// 			case 'I':
// 				this->info();
// 			case 'W':
// 				this->warning();
// 			case 'E':
// 				this->error(); break ;
// 			default :
// 				print_error("Fallthrough error is annoying when you use it by design.");
// 		}
// 		return ;
// 	}
// 	print_error("Argument given is not a level ! Try DEBUG, INFO, WARNING or ERROR !");
// }

// Switch loop solution, that is NOT clean but exercise might want this one...
void	Karen::complain(std::string level)
{
	std::string	level_type[4] =
			{
				"ERROR",
				"WARNING",
				"INFO",
				"DEBUG"
			};
	void	(Karen::*func[4])(void) =
			{
				&Karen::error,
				&Karen::warning,
				&Karen::info,
				&Karen::debug
			};
	int	count = -2;

	if (!level.empty())
	{
		for (int i = 0; i < (int)level.size(); i++)
			level[i] = std::toupper(level[i]);
		for (int i = 0; i < 4; i++)
		{
			if (!level_type[i].compare(level))
			{
				count = i;
				break ;
			}
		}
		while (count >= 0)
		{
			switch (count)
			{
				case 0 :
					(this->*func[0])(); break ;
				case 1 :
					(this->*func[1])(); break ;
				case 2 :
					(this->*func[2])(); break ;
				case 3 :
					(this->*func[3])(); break ;
				default :
					print_error("Why am I even writing this error message ?");
			}
			count--;
		}
	}
	if (count == -2)
		print_error("Argument given is not a level ! Try DEBUG, INFO, WARNING or ERROR !");
}