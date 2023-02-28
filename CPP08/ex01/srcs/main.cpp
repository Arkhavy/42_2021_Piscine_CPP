/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljohnson <ljohnson@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 10:19:38 by ljohnson          #+#    #+#             */
/*   Updated: 2023/02/28 13:52:11 by ljohnson         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <Span.hpp>

void	ft_print_err(char const* what)
{
	std::cerr << RED << BOLD;
	std::cerr << what;
	std::cerr << FWHITE << std::endl;
}

void	ft_print_title(char const* title)
{
	std::cout << CYAN << BOLD;
	std::cout << title << "\n";
	std::cout << FWHITE << std::endl;
}

int	main(void)
{
	ft_print_title("Init span 1, add 10 numbers then throw an exception on 11th");
	Span	span(10);

	span.addNumber(70);
	span.addNumber(120);
	span.addNumber(15);
	span.addNumber(10);
	span.addNumber(50);
	span.addNumber(42);
	span.addNumber(147);
	span.addNumber(440);
	span.addNumber(20);
	span.addNumber(27);
	try{span.addNumber(199);} //throw NoSpaceLeftException lol
	catch (std::exception& e) {ft_print_err(e.what());}

	std::cout << FAINT << "----------" << FWHITE << std::endl;

	ft_print_title("Display full span, shortspan and longspan");

	std::cout << "span: " << span << std::endl;
	std::cout << "short: " << span.shortestSpan() << std::endl;
	std::cout << "long: " << span.longestSpan() << std::endl;

	std::cout << FAINT << "----------" << FWHITE << std::endl;

	ft_print_title("Init span2(20 000), add multiple 100 packs and display full span in try/catch scope");
	try
	{
		Span	span2(20000);

		span2.addPack(100, 10);
		span2.addPack(100, 20);
		span2.addPack(100, 30);
		span2.addPack(100, 40);
		span2.addPack(100, 50);
		span2.addPack(100, 60);
		span2.addPack(100, 70);
		span2.addPack(100, 80);
		span2.addPack(100, 90);
		std::cout << span2 << std::endl;
		std::cout << FAINT << "----------" << FWHITE << std::endl;

		ft_print_title("addpack 19 000 to span2 (total is 19 900) then addpack 142 that throws an exception");
		span2.addPack(19000, 42); //please do not display span2 past this line :D
		span2.addPack(142, 12); //throw NoSpaceLeftException woooo
	}
	catch (std::exception& e) {ft_print_err(e.what());}

	std::cout << FAINT << "----------" << FWHITE << std::endl;

	ft_print_title("Init span3, throw exceptions with empty span, only one number and addpack with value > max_size");
	Span	span3(4);

	try {std::cout << span3.shortestSpan() << std::endl;} //throw NoSpanPossibleException
	catch (std::exception& e) {ft_print_err(e.what());}
	std::cout << FAINT << "----------" << FWHITE << std::endl;

	try {std::cout << span3.longestSpan() << std::endl;} //throw NoSpanPossibleException
	catch (std::exception& e) {ft_print_err(e.what());}
	std::cout << FAINT << "----------" << FWHITE << std::endl;

	try {span3.addPack(5, 42);}
	catch (std::exception& e) {ft_print_err(e.what());} //throw NoSpaceLeftException
	std::cout << FAINT << "----------" << FWHITE << std::endl;

	span3.addNumber(-1);

	try {std::cout << span3.shortestSpan() << std::endl;} //throw NoSpanPossibleException
	catch (std::exception& e) {ft_print_err(e.what());}
	std::cout << FAINT << "----------" << FWHITE << std::endl;

	try {std::cout << span3.longestSpan() << std::endl;} //throw NoSpanPossibleException
	catch (std::exception& e) {ft_print_err(e.what());}
	return (0);
}