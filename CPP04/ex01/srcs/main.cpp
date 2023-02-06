/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljohnson <ljohnson@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 14:41:46 by ljohnson          #+#    #+#             */
/*   Updated: 2023/02/06 14:57:00 by ljohnson         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <Animal.hpp>
#include <Brain.hpp>
#include <Dog.hpp>
#include <Cat.hpp>
#include <WrongAnimal.hpp>
#include <WrongCat.hpp>

int	main()
{
	const Animal* j = new Dog();
	const Animal* i = new Cat();

	delete j;
	delete i;
	
	std::cout << std::endl;
	std::cout << "--------------------------------------------------" << std::endl;
	std::cout << "Cat tests" << std::endl;
	std::cout << "--------------------------------------------------" << std::endl;

	Cat	c1;
	Cat	c2("c2");
	Cat	c3(c1);

	c1.display_ideas();
	std::cout << "--------------------------------------------------" << std::endl;
	c1.set_brain_idea(25, "ouaf ouaf");
	c1.set_brain_idea(50, "ouef ouef");
	c1.set_brain_idea(75, "ouif ouif");
	c1.display_ideas();

	std::cout << std::endl;
	std::cout << "--------------------------------------------------" << std::endl;
	std::cout << "Dog tests" << std::endl;
	std::cout << "--------------------------------------------------" << std::endl;

	Dog	d1;
	Dog	d2("d2");
	Dog	d3(d1);

	d1.display_ideas();
	std::cout << "--------------------------------------------------" << std::endl;
	d1.set_brain_idea(25, "arf arf");
	d1.set_brain_idea(50, "erf erf");
	d1.set_brain_idea(75, "irf irf");
	d1.display_ideas();

	std::cout << std::endl;
	std::cout << "--------------------------------------------------" << std::endl;
	std::cout << "Mandatory tests" << std::endl;
	std::cout << "--------------------------------------------------" << std::endl;

	Animal*	alist[10];

	for (int i = 0; i < 5; i++)
		alist[i] = new Dog();
	for (int i = 5; i < 10; i++)
		alist[i] = new Cat();

	for (int i = 0; i < 10; i++)
		delete alist[i];
	std::cout << "--------------------------------------------------" << std::endl;
	return (0);
}