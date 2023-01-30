/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljohnson <ljohnson@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 11:25:12 by ljohnson          #+#    #+#             */
/*   Updated: 2023/01/30 11:32:20 by ljohnson         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <Animal.hpp>

class Dog : public Animal
{
	public:
		Dog(); //Default constructor
		Dog(std::string type);
		Dog(Dog const& src); //Copy constructor
		~Dog(); //Default destructor

		void	makeSound();
		
		Dog&	operator=(Dog const& rhs); //Assignment operator overload
};
