/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ICharacter.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljohnson <ljohnson@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 19:04:19 by ljohnson          #+#    #+#             */
/*   Updated: 2023/02/13 18:00:45 by ljohnson         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>

#include <Cure.hpp>
#include <Ice.hpp>

#define YELLOW "\033[33m"
#define CYAN "\033[36m"
#define PURPLE "\033[35m"
#define RED "\033[31m"
#define GREEN "\033[32m"
#define BOLD "\033[1m"
#define FAINT "\033[2m"
#define FWHITE "\033[0m"

class AMateria;

class ICharacter
{
	protected:
		AMateria*	inventory[4];
		std::string	name;

	public:
		ICharacter(); //Default constructor
		ICharacter(std::string name);
		ICharacter(ICharacter const& src); //Copy constructor
		virtual ~ICharacter(); //Default destructor

		virtual std::string const&	getName() const = 0;
		virtual void				equip(AMateria* m) = 0;
		virtual void				unequip(int idx) = 0;
		virtual void				use(int idx, ICharacter& target) = 0;

		ICharacter&	operator=(ICharacter const& rhs); //Assignment operator overload
};