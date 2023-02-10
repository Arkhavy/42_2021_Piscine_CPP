/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljohnson <ljohnson@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 19:12:05 by ljohnson          #+#    #+#             */
/*   Updated: 2023/02/10 19:45:23 by ljohnson         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <AMateria.hpp>

class Cure : public AMateria
{
	public:
		Cure(); //Default constructor
		Cure(std::string const& type);
		Cure(Cure const& src); //Copy constructor
		~Cure(); //Default destructor

		Cure*	clone() const; //override
		void	use(ICharacter& target); //override

		Cure&	operator=(Cure const& rhs); //Assignment operator overload
};