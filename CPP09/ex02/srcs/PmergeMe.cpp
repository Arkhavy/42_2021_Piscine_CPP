/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljohnson <ljohnson@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 11:31:00 by ljohnson          #+#    #+#             */
/*   Updated: 2023/04/05 12:56:41 by ljohnson         ###   ########lyon.fr   */
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