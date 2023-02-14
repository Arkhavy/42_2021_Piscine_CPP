/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljohnson <ljohnson@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 16:51:00 by ljohnson          #+#    #+#             */
/*   Updated: 2023/02/14 11:02:47 by ljohnson         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <ICharacter.hpp>
#include <Character.hpp>
#include <AMateria.hpp>
#include <Cure.hpp>
#include <Ice.hpp>
#include <IMateriaSource.hpp>
#include <MateriaSource.hpp>

int	main(void)
{
	IMateriaSource* src = new MateriaSource();

	src->learnMateria(new Ice());
	src->learnMateria(new Cure());

	ICharacter* me = new Character("me");
	AMateria* tmp;

	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);

	ICharacter* bob = new Character("bob");

	me->use(0, *bob);
	me->use(1, *bob);

	delete bob;
	delete me;
	delete src;

	std::cout << std::endl << "--------------------------------------------------" << std::endl << std::endl;

	IMateriaSource*	ms1 = new MateriaSource();
	IMateriaSource*	ms2 = new MateriaSource();
	*ms2 = *ms1;
	AMateria*		am1;

	ms2->learnMateria(new Ice());
	am1 = ms1->createMateria("ice"); //can´t create because didn´t learn
	delete am1;
	am1 = ms1->createMateria("cure"); //can´t create because didn´t learn

	ms1->learnMateria(new Cure());
	am1 = ms1->createMateria("cure"); //can create
	delete am1;
	am1 = ms2->createMateria("cure"); //can´t create because didn´t learn

	delete ms1;
	delete ms2;
	return (0);
}
