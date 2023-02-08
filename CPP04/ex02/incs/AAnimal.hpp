/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljohnson <ljohnson@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 11:14:59 by ljohnson          #+#    #+#             */
/*   Updated: 2023/02/08 18:00:59 by ljohnson         ###   ########lyon.fr   */
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

class AAnimal
{
	protected:
		std::string	type;

	public:
		AAnimal(); //Default constructor
		AAnimal(std::string type);
		AAnimal(AAnimal const& src); //Copy constructor
		virtual	~AAnimal(); //Default destructor

		virtual void		makeSound() const = 0;
		const std::string&	getType() const;
		void				setType(std::string type);

		AAnimal&	operator=(AAnimal const& rhs); //Assignment operator overload
};
