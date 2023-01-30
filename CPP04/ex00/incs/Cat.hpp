/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljohnson <ljohnson@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 11:22:51 by ljohnson          #+#    #+#             */
/*   Updated: 2023/01/30 12:16:14 by ljohnson         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <Animal.hpp>

class Cat : public Animal
{
	public:
		Cat(); //Default constructor
		Cat(std::string type);
		Cat(Cat const& src); //Copy constructor
		~Cat(); //Default destructor

		void	makeSound() const;
		
		Cat&	operator=(Cat const& rhs); //Assignment operator overload
};
