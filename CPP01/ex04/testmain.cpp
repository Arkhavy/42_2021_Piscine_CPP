/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testmain.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljohnson <ljohnson@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 02:07:09 by ljohnson          #+#    #+#             */
/*   Updated: 2023/01/18 02:47:31 by ljohnson         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <string>

int	main(void)
{
	std::ifstream	infile("text.txt");
	char	len;
	std::string	s1 = "ouaf";

	if (infile)
	{
		infile.seekg(0, infile.beg);
		for (int i = 1; i < 5; i++)
		{
			len = infile.peek();
			std::cout << len << std::endl;
			infile.seekg(i, infile.beg);
		}
	}
}