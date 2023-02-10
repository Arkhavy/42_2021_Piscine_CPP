/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljohnson <ljohnson@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 18:18:20 by ljohnson          #+#    #+#             */
/*   Updated: 2023/02/10 19:45:21 by ljohnson         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>

#include <ICharacter.hpp>

#define YELLOW "\033[33m"
#define CYAN "\033[36m"
#define PURPLE "\033[35m"
#define RED "\033[31m"
#define GREEN "\033[32m"
#define BOLD "\033[1m"
#define FAINT "\033[2m"
#define FWHITE "\033[0m"

class AMateria
{
	protected:
		std::string	type;

	public:
		AMateria(); //Default constructor
		AMateria(std::string const& type);
		AMateria(AMateria const& src); //Copy constructor
		~AMateria(); //Default destructor

		std::string const&	getType() const; //Returns the materia type
		virtual AMateria*	clone() const = 0;
		virtual void		use(ICharacter& target);

		AMateria&	operator=(AMateria const& rhs); //Assignment operator overload
};