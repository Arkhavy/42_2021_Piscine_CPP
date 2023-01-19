/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljohnson <ljohnson@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 00:58:06 by ljohnson          #+#    #+#             */
/*   Updated: 2023/01/19 13:51:14 by ljohnson         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <fstream>

int	print_error(std::string message)
{
	std::cout << "\033[31m" << "\033[1m";
	std::cout << message;
	std::cout << "\033[0m" << std::endl;
	return (1);
}

int	get_file_content(const char* filename, std::string& fcontent)
{
	std::ifstream	ifs;
	std::string		line;

	ifs.open(filename, std::ifstream::in);
	if (!ifs.good())
		return (print_error("ERROR: Infile does not exist or cannot be opened."));
	while (42)
	{
		std::getline(ifs, line);
		fcontent += line;
		if (ifs.eof())
			break ;
		fcontent += "\n";
	}
	ifs.close();
	return (0);
}

void	replace_str_content(std::string& fcontent, std::string& s1, std::string& s2)
{
	size_t	index = 0;
	
	index = fcontent.find(s1);
	while (index != std::string::npos)
	{
		fcontent.erase(index, s1.size());
		fcontent.insert(index, s2);
		index = fcontent.find(s1, index + s2.length());
		if (index == std::string::npos)
			break ;
	}
}

int	write_new_file(std::string& fcontent, std::string filename)
{
	std::ofstream	ofs(filename);

	if (!ofs.good())
		return (print_error("ERROR: Outfile already exist and can't be opened."));
	ofs << fcontent;
	ofs.close();
	return (0);
}

std::string	change_filename(const char* filename)
{
	std::string	newfilename;

	newfilename = filename;
	newfilename.append(".replace");
	return (newfilename);
}

int	sed(const char*	filename, std::string& s1, std::string& s2)
{
	std::string		fcontent;

	if (get_file_content(filename, fcontent))
		return (1);
	replace_str_content(fcontent, s1, s2);
	if (write_new_file(fcontent, change_filename(filename)))
		return (1);
	return (0);
}


int	check_user_input(int ac, char **av)
{
	std::string	s1;
	std::string	s2;

	if (ac != 4)
	{
		print_error("ERROR: Invalid number of Arguments.");
		return (print_error("Usage: ./replace <file> <str1> <str2>"));
	}
	for (int i = 1; i < ac; i++)
		if (!av[i] || !av[i][0])
			return (print_error("ERROR: Invalid arg in user input."));
	s1 = av[2];
	s2 = av[3];
	if (s1 == s2)
		return (print_error("ERROR: Identical comparison strings."));
	return (0);
}

int	main(int ac, char **av)
{
	std::string	s1;
	std::string	s2;

	if (check_user_input(ac, av))
		return (1);
	s1 = av[2];
	s2 = av[3];
	sed(av[1], s1, s2);
	return (0);
}