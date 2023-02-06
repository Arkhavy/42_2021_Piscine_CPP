/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljohnson <ljohnson@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 11:22:51 by ljohnson          #+#    #+#             */
/*   Updated: 2023/02/06 15:14:31 by ljohnson         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <AAnimal.hpp>
#include <Brain.hpp>

class Cat : public AAnimal
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
		void	set_brain_idea(unsigned int const index, std::string const& idea);

		Cat&	operator=(Cat const& rhs); //Assignment operator overload
};
