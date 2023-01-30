/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljohnson <ljohnson@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 11:22:51 by ljohnson          #+#    #+#             */
/*   Updated: 2023/01/30 17:02:39 by ljohnson         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <Animal.hpp>
#include <Brain.hpp>

class Cat : public Animal
{
	private:
		Brain*	brain;

	public:
		Cat(); //Default constructor
		Cat(std::string type);
		Cat(Cat const& src); //Copy constructor
		~Cat(); //Default destructor

		void	makeSound() const;
		void	display_ideas() const;

		Cat&	operator=(Cat const& rhs); //Assignment operator overload
};
