/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljohnson <ljohnson@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 15:00:49 by ljohnson          #+#    #+#             */
/*   Updated: 2022/07/17 11:08:33 by ljohnson         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <fstream>

void	print_error(std::string message)
{
	std::cout << "\033[31m" << "\033[1m";
	std::cout << message;
	std::cout << "\033[0m" << std::endl;
}

std::string	get_file_content(std::string filename)
{
	std::ifstream	ifs(filename);
	std::string		file_content;
	int				fcontent_len;
	char			*fcontent;

	ifs.seekg (0, ifs.end);
	fcontent_len = ifs.tellg();
	ifs.seekg (0, ifs.beg);
	
	fcontent = new char[fcontent_len];
	ifs.read(fcontent, fcontent_len);
	file_content = fcontent;

	delete [] fcontent;
	ifs.close();
	return (file_content);
}

std::string	swap_content_parts(std::string content, std::string arg1, std::string arg2)
{
	size_t	index = 0;

	while (1)
	{
		index = content.find(arg1);
		if (index == std::string::npos)
			break ;
		content.erase(index, arg1.size());
		content.insert(index, arg2);
	}
	std::cout << content << std::endl;
	return (content);
}

// void	write_file_content(std::string filename, std::string content)
// {
// 	std::ofstream	ofs(filename);
	
// 	ofs.close();
// }

int	main(int ac, char **av)
{
	std::string		filename;
	std::string		arg1;
	std::string		arg2;
	std::string		content;

	if (ac != 4)
	{
		print_error("Invalid number of Arguments");
		print_error("Usage : ./replace <file> <str1> <str2>");
		return (1);
	}
	filename = av[1];
	arg1 = av[2];
	arg2 = av[3];
	content = get_file_content(filename);
	content = swap_content_parts(content, arg1, arg2);
	filename.append(".replace");
	// write_file_content(filename, content);
	return (0);
}