/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljohnson <ljohnson@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 14:41:46 by ljohnson          #+#    #+#             */
/*   Updated: 2023/01/30 15:27:47 by ljohnson         ###   ########lyon.fr   */
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


	std::cout << std::endl;
	std::cout << "--------------------------------------------------" << std::endl;
	std::cout << "Dog tests" << std::endl;
	std::cout << "--------------------------------------------------" << std::endl;

	std::cout << std::endl;
	std::cout << "--------------------------------------------------" << std::endl;
	std::cout << "Other Animal tests" << std::endl;
	std::cout << "--------------------------------------------------" << std::endl;

	std::cout << "--------------------------------------------------" << std::endl;
	return (0);
}