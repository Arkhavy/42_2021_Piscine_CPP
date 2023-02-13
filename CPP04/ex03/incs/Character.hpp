/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljohnson <ljohnson@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 11:09:18 by ljohnson          #+#    #+#             */
/*   Updated: 2023/02/13 11:36:51 by ljohnson         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <ICharacter.hpp>

class Character : public ICharacter
{
	public:
		Character(); //Default constructor
		Character(std::string name);
		Character(Character const& src); //Copy constructor
		~Character(); //override Default destructor

		std::string const&	getName() const; //override
		void				equip(AMateria* m); //override
		void				unequip(int idx); //override
		void				use(int idx, Character& target); //override

		Character&	operator=(Character const& rhs); //Assignment operator overload
};