/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljohnson <ljohnson@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 10:19:38 by ljohnson          #+#    #+#             */
/*   Updated: 2023/02/28 13:28:16 by ljohnson         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <Span.hpp>

void	ft_print_err(char const* what)
{
	std::cerr << RED << BOLD;
	std::cerr << what;
	std::cerr << FWHITE << std::endl;
}

//TEST DEEP COPY
int	main(void)
{
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
	try{span.addNumber(199);} //throw exception lol
	catch (std::exception& e) {ft_print_err(e.what());}

	std::cout << FAINT << "\n----------\n" << FWHITE << std::endl;

	std::cout << "span: " << span << std::endl;
	std::cout << "short: " << span.shortestSpan() << std::endl;
	std::cout << "long: " << span.longestSpan() << std::endl;

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

		span2.addPack(19100, 42); //please do not display span2 past this line :D
		span2.addNumber(42); //throw exception woooo
	}
	catch (std::exception& e) {ft_print_err(e.what());}
	return (0);
}