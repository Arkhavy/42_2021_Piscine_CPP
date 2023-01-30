/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljohnson <ljohnson@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 11:14:59 by ljohnson          #+#    #+#             */
/*   Updated: 2023/01/30 11:56:55 by ljohnson         ###   ########lyon.fr   */
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

class Animal
{
	protected:
		std::string	type;

	public:
		Animal(); //Default constructor
		Animal(std::string type);
		Animal(Animal const& src); //Copy constructor
		~Animal(); //Default destructor

		virtual void	makeSound();
		std::string		getType();

		Animal&	operator=(Animal const& rhs); //Assignment operator overload
};
