/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljohnson <ljohnson@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 11:31:00 by ljohnson          #+#    #+#             */
/*   Updated: 2023/04/05 15:59:16 by ljohnson         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <PmergeMe.hpp>

/* ************************************************************************** */
/* Constructors & Destructors */
/* ************************************************************************** */
PmergeMe::PmergeMe() {}

PmergeMe::PmergeMe(PmergeMe const& src) {*this = src;}

PmergeMe::~PmergeMe() {}

/* ************************************************************************** */
/* Operator Overloads */
/* ************************************************************************** */
PmergeMe&	PmergeMe::operator=(PmergeMe const& rhs)
{
	for (std::list<unsigned int>::const_iterator it = rhs.lst.begin(); it != rhs.lst.end(); it++)
		this->lst.push_back(*it);
	for (size_t i = 0; i < rhs.vct.size(); i++)
		this->vct.push_back(rhs.vct[i]);
	return (*this);
}

/* ************************************************************************** */
/* Exceptions */
/* ************************************************************************** */
char const*	InvalidProgramNameException::what()		const throw() {return ("ERROR: Invalid program name");}
char const*	InvalidArgumentException::what()		const throw() {return ("ERROR: Invalid given argument found");}
char const*	OutOfRangeException::what()				const throw() {return ("ERROR: Out of range number in given arguments");}
char const*	DuplicateFoundException::what()			const throw() {return ("ERROR: Duplicate found in given arguments");}

/* ************************************************************************** */
/* Member Functions */
/* ************************************************************************** */
void	PmergeMe::set_lst_val(unsigned int nb) {this->lst.push_back(nb);}
void	PmergeMe::set_vct_val(unsigned int nb) {this->vct.push_back(nb);}

bool	PmergeMe::check_vct_duplicates() const
{
	size_t	vct_size = this->vct.size();

	for (size_t i = 0; i < vct_size; i++)
	{
		if (std::count(this->vct.begin(), this->vct.end(), this->vct[i]) > 1)
			return (true);
	}
	return (false);
}

void	PmergeMe::display_lst() const
{
	std::cout << "lst: ";
	for (std::list<unsigned int>::const_iterator it = this->lst.begin(); it != this->lst.end(); it++)
		std::cout << CYAN << *it << " ";
	std::cout << RESET << std::endl;
}

void	PmergeMe::display_vct() const
{
	size_t	vct_size = this->vct.size();
	std::cout << "vct: ";
	for (size_t i = 0; i < vct_size; i++)
		std::cout << CYAN << this->vct[i] << " ";
	std::cout << RESET << std::endl;
}

void	PmergeMe::launch(int id)
{
	if (id == 0)
		this->lst = ft_sorting<std::list<unsigned int> >(this->lst);
	else
		this->vct = ft_sorting<std::vector<unsigned int> >(this->vct);
}

bool	PmergeMe::check_sorting() const
{
	std::list<unsigned int>::const_iterator	itl1 = this->lst.begin();
	std::list<unsigned int>::const_iterator	itl2 = this->lst.begin();
	itl2++;
	std::vector<unsigned int>::const_iterator	itv1 = this->vct.begin();
	std::vector<unsigned int>::const_iterator	itv2 = this->vct.begin();
	itv2++;

	while (itl2 != this->lst.end())
	{
		if (*itl1 > *itl2)
			return (false);
		itl1++;
		itl2++;
	}
	while (itv2 != this->vct.end())
	{
		if (*itv1 > *itv2)
			return (false);
		itv1++;
		itv2++;
	}
	return (true);
}