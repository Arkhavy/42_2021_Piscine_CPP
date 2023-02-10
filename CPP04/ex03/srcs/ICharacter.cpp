/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ICharacter.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljohnson <ljohnson@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 19:38:35 by ljohnson          #+#    #+#             */
/*   Updated: 2023/02/10 20:09:04 by ljohnson         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/* Constructors & Destructors */
/* ************************************************************************** */

/* ************************************************************************** */
/* Operator Overloads */
/* ************************************************************************** */

/* ************************************************************************** */
/* Public Member Functions */
/* ************************************************************************** */

/*
Notes :
Materia can be given to equip() with clone() member function
	We need a way to delete those if unequip() is used
	unequip() can't delete the Materia
		idea 1 : get the address before calling unequip() in main()
		idea 2 : materia destructor can delete, but stack init materias will cause problems
inventory of character is empty at its construction
	It means that Materias have to be created before being equipped with equip()
		Clone gives a heap pointer, can still save it in a list ?

equip(AMateria* m) puts a materia in the first empty slot found
	if no empty slot is found, don't do anything

unequip(int idx) removes a materia from the idx slot given
	if wrong idx or empty slot, don't do anything

use(int idx, ICharacter& target)
	if wrong idx or empty slot, don't do anything
	use() can delete the materia
		question : what happen if we delete a stack initialized materia ?
	this function has to call the Materia use() function
*/