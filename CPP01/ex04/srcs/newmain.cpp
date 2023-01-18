/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   newmain.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljohnson <ljohnson@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 00:58:06 by ljohnson          #+#    #+#             */
/*   Updated: 2023/01/18 02:59:40 by ljohnson         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <fstream>

/*
L'idéal serait de lire et d'écrire au fur et à mesure
L'index i1 de l'infile avance
L'écriture i2 de l'outfile avance en même temps

Infile >> String1 >> String2 >> Outfile ?
Infile >> String >> Outfile ?
	Potentiel souci de mémoire et perf si le fichier est gros (cf bible)
Infile >> Outfile avec read buffer == à s1.len()
	Version optimisée, potentiellement plus compliqué à exécuter

Algo :
Check User Input
	if ac != 4
		Invalid number of arguments
	av[1] = infile
		check arg validity
			error if empty
	av[2] = s1
		check arg validity
			error if empty
	av[3] = s2
		check arg validity
			error if empty
	check s1 == s2
		error if equal

Open infile
	check existence
		error if does not exist
	check access
		error if can't read

Create Outfile "infile.replace"

loop
	i1 peek in infile
	if (i1 == s1[0])
		itmp = i1;
		infile.seekg(i1 - 1, infile.beg);
		i1 read(buffer, s1.length());
		if (buffer == s1)
			write s2 >> outfile
		else
			i1 = itmp;
			infile.seekg(i1, infile.beg);
			put i1 >> outfile;
		free buffer
	else
		put i1 >> outfile

or use string operations to do the same thing if read is forbidden

Close infile
Close outfile
return main
*/

// void	ft_getline(std::string& str)
// {
// 	std::getline(std::cin, str);
// 	if (std::cin.eofbit != 0)
// 	{
// 		std::cin.clear();
// 		clearerr(stdin);
// 	}
// }

int	print_error(std::string message)
{
	std::cout << "\033[31m" << "\033[1m";
	std::cout << message;
	std::cout << "\033[0m" << std::endl;
	return (1);
}

static int	check_user_input(int ac, char **av)
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
	if (check_user_input(ac, av))
		return (1);
	return (0);
}