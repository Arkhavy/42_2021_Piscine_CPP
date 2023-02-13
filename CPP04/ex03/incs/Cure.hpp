/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljohnson <ljohnson@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 19:12:05 by ljohnson          #+#    #+#             */
/*   Updated: 2023/02/13 18:45:25 by ljohnson         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <AMateria.hpp>
#include <ICharacter.hpp>

class ICharacter;

class Cure : public AMateria
{
	public:
		Cure(); //Default constructor
		Cure(std::string const& type);
		Cure(Cure const& src); //Copy constructor
		~Cure(); //override Default destructor

		Cure*	clone() const; //override
		void	use(ICharacter& target); //override

		Cure&	operator=(Cure const& rhs); //Assignment operator overload
};