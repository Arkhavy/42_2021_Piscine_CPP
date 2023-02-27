/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljohnson <ljohnson@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 10:39:44 by ljohnson          #+#    #+#             */
/*   Updated: 2023/02/27 13:27:11 by ljohnson         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <Array.hpp>

#define MAX_VAL 750
int main(int, char**)
{
	Array<int> numbers(MAX_VAL);
	int* mirror = new int[MAX_VAL];
	srand(time(NULL));
	for (int i = 0; i < MAX_VAL; i++)
	{
		const int value = rand();
		numbers[i] = value;
		mirror[i] = value;
	}
	std::cout << "----------" << std::endl;
	{
		Array<int> tmp = numbers;
		Array<int> test(tmp);
	}
	std::cout << "----------" << std::endl;
	for (int i = 0; i < MAX_VAL; i++)
	{
		if (mirror[i] != numbers[i])
		{
			std::cerr << "didn't save the same value!!" << std::endl;
			return 1;
		}
	}
	std::cout << "----------" << std::endl;
	try
	{
		numbers[-2] = 0;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	std::cout << "----------" << std::endl;
	try
	{
		numbers[MAX_VAL] = 0;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	std::cout << "----------" << std::endl;
	for (int i = 0; i < MAX_VAL; i++)
	{
		numbers[i] = rand();
	}
	std::cout << "--------------------------------------------------" << std::endl;
	numbers[2] = 123;
	if (numbers[2] != mirror[2])
		std::cout << "ouaf" << std::endl;
	mirror[3] = 1234;
	if (numbers[3] != mirror[3])
		std::cout << "ouaf again" << std::endl;
	delete [] mirror;
	return 0;
}