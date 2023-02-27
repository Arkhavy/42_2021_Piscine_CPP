/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljohnson <ljohnson@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 10:39:44 by ljohnson          #+#    #+#             */
/*   Updated: 2023/02/27 14:10:56 by ljohnson         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <Array.hpp>

#define MAX_VAL 750
int main(int, char**)
{
	std::cout << CYAN << BOLD;
	std::cout << "numbers & mirror creation and array fill";
	std::cout << FWHITE << std::endl;

	Array<int> numbers(MAX_VAL);
	int* mirror = new int[MAX_VAL];
	srand(time(NULL));
	for (int i = 0; i < MAX_VAL; i++)
	{
		const int value = rand();
		numbers[i] = value;
		mirror[i] = value;
	}

//////////////////////////////////////////////////////////////////////

	std::cout << std::endl;
	std::cout << CYAN << BOLD;
	std::cout << "scope double copy test";
	std::cout << FWHITE << std::endl;

	{
		Array<int> tmp = numbers;
		Array<int> test(tmp);
	}

//////////////////////////////////////////////////////////////////////

	std::cout << std::endl;
	std::cout << CYAN << BOLD;
	std::cout << "Check if numbers and mirror got the same values";
	std::cout << FWHITE << std::endl;

	for (int i = 0; i < MAX_VAL; i++)
	{
		if (mirror[i] != numbers[i])
		{
			std::cerr << "didn't save the same value!!" << std::endl;
			return (1);
		}
	}

//////////////////////////////////////////////////////////////////////

	std::cout << std::endl;
	std::cout << CYAN << BOLD;
	std::cout << "Out of Range exception tests -2 and MAX_VAL as index";
	std::cout << FWHITE << std::endl;

	try {numbers[-2] = 0;}
	catch(const std::exception& e) {std::cerr << e.what() << '\n';}
	try {numbers[MAX_VAL] = 0;}
	catch(const std::exception& e) {std::cerr << e.what() << '\n';}
	
//////////////////////////////////////////////////////////////////////

	std::cout << std::endl;
	std::cout << CYAN << BOLD;
	std::cout << "Change numbers array, mirror should still be different";
	std::cout << FWHITE << std::endl;

	for (int i = 0; i < MAX_VAL; i++)
		numbers[i] = rand();
	if (numbers[0] != mirror[0])
		std::cout << "numbers[0] & mirror[0] are different" << std::endl;
	if (numbers[22] != mirror[22])
		std::cout << "numbers[22] & mirror[22] are different" << std::endl;
	if (numbers[300] != mirror[300])
		std::cout << "numbers[300] & mirror[300] are different" << std::endl;
	delete [] mirror;
	return (0);
}