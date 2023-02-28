/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljohnson <ljohnson@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 09:41:20 by ljohnson          #+#    #+#             */
/*   Updated: 2023/02/28 13:21:54 by ljohnson         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <Span.hpp>

/* ************************************************************************** */
/* Constructors & Destructors */
/* ************************************************************************** */
Span::Span() : tab(), tab_max_size(0)
{
	std::cout << FAINT;
	std::cout << "Default Span constructor called.";
	std::cout << FWHITE << std::endl;
}

Span::Span(unsigned int const N) : tab(), tab_max_size(N)
{
	std::cout << FAINT;
	std::cout << "Span constructor called.";
	std::cout << FWHITE << std::endl;
}

Span::Span(Span const& src)
{
	if (this == &src)
		return ;
	*this = src;
	std::cout << FAINT;
	std::cout << "Copy Span constructor called.";
	std::cout << FWHITE << std::endl;
}

Span::~Span()
{
	std::cout << FAINT;
	std::cout << "Default destructor called.";
	std::cout << FWHITE << std::endl;
}

/* ************************************************************************** */
/* Operator Overloads */
/* ************************************************************************** */
Span&	Span::operator=(Span const& rhs)
{
	if (this == &rhs)
		return (*this);
	this->tab = rhs.tab;
	this->tab_max_size = rhs.tab_max_size;
	return (*this);
}

std::ostream&	operator<<(std::ostream& out, Span const& rhs)
{
	unsigned int	tab_size = rhs.get_size();
	for (unsigned int i = 0; i < tab_size; i++)
	{
		if ((i % 100) == 0)
			std::cout << std::endl;
		out << rhs.get_value_idx(i) << " ";
	}
	return (out);
}

/* ************************************************************************** */
/* Exceptions */
/* ************************************************************************** */
char const*	Span::NoSpanPossibleException::what() const throw() {return ("ERROR Exception: Not enough numbers to make a span !");}
char const*	Span::NoSpaceLeftException::what() const throw() {return ("ERROR Exception: Not enough space to add something !");}

/* ************************************************************************** */
/* Public Member Functions */
/* ************************************************************************** */
void	Span::addNumber(int const nb)
{
	if (this->tab.size() == this->tab_max_size)
		throw NoSpaceLeftException();

	this->tab.push_back(nb);
}

int	Span::shortestSpan() const
{
	if (this->tab.size() <= 1)
		throw NoSpanPossibleException();

	unsigned int	tab_size = this->tab.size();
	std::vector<int>	tmp = this->tab;
	int					ret1;
	int					ret2;
	int					short_span = -1;
	int					tmp_span = -1;

	std::sort(tmp.begin(), tmp.end());
	for (unsigned int i = 0; i < (tab_size - 1); i++)
	{
		ret1 = tmp[i];
		ret2 = tmp[i + 1];
		if (ret1 < ret2)
			tmp_span = ret2 - ret1;
		if (tmp_span < short_span || short_span == -1)
			short_span = tmp_span;
	}
	if (short_span == -1)
		return (0);
	return (short_span);
}

int	Span::longestSpan() const
{
	if (this->tab.size() <= 1)
		throw NoSpanPossibleException();

	int	ret_low = *std::min_element(this->tab.begin(), this->tab.end());
	int	ret_high = *std::max_element(this->tab.begin(), this->tab.end());
	return (ret_high - ret_low);
}

void	Span::addPack(unsigned int const N, int const value)
{
	if ((this->tab.size() + N) > this->tab_max_size)
		throw NoSpaceLeftException();
	this->tab.insert(this->tab.end(), N, value);
}

int	Span::get_value_idx(unsigned int const idx) const {return (this->tab[idx]);}
unsigned int	Span::get_size() const {return (this->tab.size());}