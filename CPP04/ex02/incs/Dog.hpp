/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljohnson <ljohnson@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 11:25:12 by ljohnson          #+#    #+#             */
/*   Updated: 2023/02/14 16:21:16 by ljohnson         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <AAnimal.hpp>
#include <Brain.hpp>

class Dog : public AAnimal
{
	private:
		Brain*	brain;

	public:
		Dog(); //Default constructor
		Dog(std::string type);
		Dog(Dog const& src); //Copy constructor
		virtual ~Dog(); //Default destructor

		virtual void	makeSound() const;
		void			display_ideas() const;
		void			set_brain_idea(unsigned int const index, std::string const& idea);

		Dog&	operator=(Dog const& rhs); //Assignment operator overload
};
