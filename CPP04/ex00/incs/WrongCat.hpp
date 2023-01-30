/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljohnson <ljohnson@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 11:30:46 by ljohnson          #+#    #+#             */
/*   Updated: 2023/01/30 11:32:10 by ljohnson         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <WrongAnimal.hpp>

class WrongCat : public WrongAnimal
{
	public:
		WrongCat(); //Default constructor
		WrongCat(std::string type);
		WrongCat(WrongCat const& src); //Copy constructor
		~WrongCat(); //Default destructor

		void	makeSound();

		WrongCat&	operator=(WrongCat const& rhs); //Assignment operator overload
};