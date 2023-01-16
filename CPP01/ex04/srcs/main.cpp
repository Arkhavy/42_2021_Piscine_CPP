/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljohnson <ljohnson@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 15:00:49 by ljohnson          #+#    #+#             */
/*   Updated: 2023/01/16 18:03:25 by ljohnson         ###   ########lyon.fr   */
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

std::string	get_file_content(const char* filename) //fonction à refaire, getline fonctionne, jsuis con mdr
{
	std::ifstream	ifs;
	std::string		file_content;
	int				fcontent_len;
	char			*fcontent;

	ifs.open(filename, std::ifstream::in);
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

std::string	swap_content_parts(std::string content, std::string s1, std::string s2)
{
	size_t	index = 0;

	while (42)
	{
		index = content.find(s1); //boucle inf si caractère à remplacer présent dans le remplacement
		if (index == std::string::npos)
			break ;
		content.erase(index, s1.size());
		content.insert(index, s2);
	}
	return (content);
}

void	write_file_content(const char* filename, std::string content) //fonction potentiellement à refaire aussi
{
	std::ofstream	ofs;
	
	ofs.open(filename, std::ofstream::out);
	if (!ofs.good())
	{
		print_error("Outfile already exist and can't be opened.");
		return ;
	}
	ofs << content;
	ofs.close();
}

int	check_user_input(char **av)
{
	std::string		s1;
	std::string		s2;
	
	if (!av[0] || !av[1] || !av[2] || !av[0][0] || !av[1][0] || !av[2][0])
		return (print_error("Invalid argument somewhere in user input, try again !"));
	std::ifstream	ifs(av[0]);
	if (!ifs.good())
		return (print_error("Infile does not exist or can't be opened."));
	s1 = av[1];
	s2 = av[2];
	if (s1 == s2)
		return (print_error("both s1 and s2 are identical, please change one !"));
	ifs.close();
	return (0);
}

int	main(int ac, char **av)
{
	const char*	filename;
	std::string	newfilename;
	std::string	s1;
	std::string	s2;
	std::string	content;

	if (ac != 4)
	{
		print_error("Invalid number of Arguments");
		return (print_error("Usage : ./replace <file> <str1> <str2>"));
	}
	if (check_user_input(&av[1]))
		return (1);
	filename = av[1];
	newfilename = av[1];
	s1 = av[2];
	s2 = av[3];
	content = get_file_content(filename);
	content = swap_content_parts(content, s1, s2);
	newfilename.append(".replace");
	filename = newfilename.c_str();
	write_file_content(filename, content);
	return (0);
}