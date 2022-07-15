/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljohnson <ljohnson@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 13:58:57 by ljohnson          #+#    #+#             */
/*   Updated: 2022/07/15 14:14:47 by ljohnson         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

int	main(void)
{
	std::string		str = "HI THIS IS BRAIN";
	std::string*	stringPTR = &str;
	std::string&	stringREF = str;

	std::cout << "memory adress of str = ";
	std::cout << "\033[33m" << &str << "\033[0m" << std::endl;
	
	std::cout << "memory adress of stringPTR = ";
	std::cout << "\033[33m" << stringPTR << "\033[0m" << std::endl;
	
	std::cout << "memory adress of stringREF = ";
	std::cout << "\033[33m" << &stringREF << "\033[0m" << std::endl;

	std::cout << std::endl;

	std::cout << "value of str = ";
	std::cout << "\033[32m" << str << "\033[0m" << std::endl;
	
	std::cout << "value of stringPTR = ";
	std::cout << "\033[32m" << *stringPTR << "\033[0m" << std::endl;
	
	std::cout << "value of stringREF = ";
	std::cout << "\033[32m" << stringREF << "\033[0m" << std::endl;

	return (0);
}