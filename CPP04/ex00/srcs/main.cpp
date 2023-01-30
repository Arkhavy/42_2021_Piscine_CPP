/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljohnson <ljohnson@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 11:09:45 by ljohnson          #+#    #+#             */
/*   Updated: 2023/01/30 13:50:02 by ljohnson         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <Cat.hpp>
#include <Dog.hpp>
#include <WrongCat.hpp>

int main()
{
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	i->makeSound(); //will output the cat sound!
	j->makeSound();
	meta->makeSound();

	delete meta;
	delete j;
	delete i;

	std::cout << std::endl;
	std::cout << "--------------------------------------------------" << std::endl;
	std::cout << "Animal tests" << std::endl;
	std::cout << "--------------------------------------------------" << std::endl;

	Animal	a1;
	Animal	a2("a2");
	Animal	a3(a1);

	a1.makeSound();
	a2.makeSound();
	a3.makeSound();
	a3.setType("a3");
	a3.makeSound();
	
	std::cout << std::endl;
	std::cout << "--------------------------------------------------" << std::endl;
	std::cout << "Cat tests" << std::endl;
	std::cout << "--------------------------------------------------" << std::endl;
	
	Cat		c1;
	Cat		c2("c2");
	Cat		c3(c1);
	
	c1.makeSound();
	c2.makeSound();
	c3.makeSound();
	c3.setType("c3");
	c3.makeSound();
	
	std::cout << std::endl;
	std::cout << "--------------------------------------------------" << std::endl;
	std::cout << "Dog tests" << std::endl;
	std::cout << "--------------------------------------------------" << std::endl;
	
	Dog		d1;
	Dog		d2("d2");
	Dog		d3(d1);
	
	d1.makeSound();
	d2.makeSound();
	d3.makeSound();
	d3.setType("d3");
	d3.makeSound();

	std::cout << std::endl;
	std::cout << "--------------------------------------------------" << std::endl;
	std::cout << "WrongAnimal tests" << std::endl;
	std::cout << "--------------------------------------------------" << std::endl;
	
	WrongAnimal		wa1;
	WrongAnimal		wa2("wa2");
	WrongAnimal		wa3(wa1);
	
	wa1.makeSound();
	wa2.makeSound();
	wa3.makeSound();
	wa3.setType("wa3");
	wa3.makeSound();

	std::cout << std::endl;
	std::cout << "--------------------------------------------------" << std::endl;
	std::cout << "WrongCat tests" << std::endl;
	std::cout << "--------------------------------------------------" << std::endl;
	
	WrongCat	wc1;
	WrongCat	wc2("wc2");
	WrongCat	wc3(wc1);
	
	wc1.makeSound();
	wc2.makeSound();
	wc3.makeSound();
	wc3.setType("wc3");
	wc3.makeSound();

	std::cout << std::endl;
	std::cout << "--------------------------------------------------" << std::endl;
	std::cout << "Other Animal tests" << std::endl;
	std::cout << "--------------------------------------------------" << std::endl;
	
	Animal*			aa = new Animal();
	Animal*			ac = new Cat();
	Animal*			ad = new Dog();
	WrongAnimal*	waa = new WrongAnimal();
	WrongAnimal*	wac = new WrongCat();

	aa->makeSound();
	aa->setType("aa-ouaf");
	aa->makeSound();
	ac->makeSound();
	ac->setType("ac-ouaf");
	ac->makeSound();
	ad->makeSound();
	ad->setType("ad-ouaf");
	ad->makeSound();
	waa->makeSound();
	waa->setType("waa-ouaf");
	waa->makeSound();
	wac->makeSound();
	wac->setType("wac-ouaf");
	wac->makeSound();

	delete ac;
	delete ad;
	delete aa;
	delete waa;
	delete wac;
	
	std::cout << "--------------------------------------------------" << std::endl;
	return (0);
}
