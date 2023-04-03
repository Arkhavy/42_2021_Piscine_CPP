/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljohnson <ljohnson@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 11:20:38 by ljohnson          #+#    #+#             */
/*   Updated: 2023/04/03 12:36:49 by ljohnson         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>
#include <iostream>
#include <exception>
#include <stack>

# define BLACK		"\033[30m"
# define RED		"\033[31m"
# define GREEN		"\033[32m"
# define YELLOW		"\033[33m"
# define BLUE		"\033[34m"
# define PURPLE		"\033[35m"
# define CYAN		"\033[36m"
# define WHITE		"\033[37m"

# define ERASE		"\033[2K\r"
# define RESET		"\033[0m"
# define BOLD		"\033[1m"
# define FAINT		"\033[2m"
# define ITALIC		"\033[3m"
# define UNDERLINE	"\033[4m"

class	RPN
{
	private:
	
	public:
	//Constructors & Destructors
		RPN();
		RPN(RPN const& src);
		virtual	~RPN();

	//Operator overloads
		RPN&	operator=(RPN const& rhs);

	//Getter & Setters
};

/* ************************************************************************** */
/* Exceptions */
/* ************************************************************************** */

/* ************************************************************************** */
/* Templates */
/* ************************************************************************** */
template<typename T>
T	ft_print_msg(std::string const& message, T const val);

#include <RPN.tpp>