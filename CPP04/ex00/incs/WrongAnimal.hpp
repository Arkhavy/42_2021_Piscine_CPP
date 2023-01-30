/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljohnson <ljohnson@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 11:28:14 by ljohnson          #+#    #+#             */
/*   Updated: 2023/01/30 12:16:40 by ljohnson         ###   ########lyon.fr   */
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

class WrongAnimal
{
	protected:
		std::string	type;

	public:
		WrongAnimal(); //Default constructor
		WrongAnimal(std::string type);
		WrongAnimal(WrongAnimal const& src); //Copy constructor
		~WrongAnimal(); //Default destructor

		virtual void		makeSound() const;
		const std::string&	getType() const;

		WrongAnimal&	operator=(WrongAnimal const& rhs); //Assignment operator overload
};
