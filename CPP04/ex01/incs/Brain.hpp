/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljohnson <ljohnson@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 14:22:36 by ljohnson          #+#    #+#             */
/*   Updated: 2023/01/30 15:24:48 by ljohnson         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>

#define YELLOW "\033[33m"
#define CYAN "\033[36m"
#define PURPLE "\033[35m"
#define RED "\033[31m"
#define GREEN "\033[32m"
#define BOLD "\033[1m"
#define FAINT "\033[2m"
#define FWHITE "\033[0m"

class Brain
{
	private:
		std::string	ideas[100];

	public:
		Brain(); //Default constructor
		Brain(Brain const& src); //Copy constructor
		~Brain(); //Default destructor

		void	set_one_idea(const unsigned int index, const std::string& idea);
		void	display_ideas() const;

		Brain&	operator=(Brain const& rhs); //Assignment operator overload
};
