/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljohnson <ljohnson@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 11:31:00 by ljohnson          #+#    #+#             */
/*   Updated: 2023/04/20 17:02:01 by ljohnson         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <PmergeMe.hpp>

/* ************************************************************************** */
/* Constructors & Destructors */
/* ************************************************************************** */
PmergeMe::PmergeMe() : time_lst(0), time_vct(0) {}

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
	this->time_lst = 0;
	this->time_vct = 0;
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

void	PmergeMe::launch()
{
	this->display_tab<std::list<unsigned int> >(this->lst, "Before: "); //list version
	// this->display_tab<std::vector<unsigned int> >(this->vct, "Before: "); //vector version

	this->time_lst = this->set_time();
	while (!check_sorting<std::list<unsigned int> >(this->lst))
		this->lst = merge_insert_sort<std::list<unsigned int> >(this->lst);
	this->time_lst = this->set_time() - this->time_lst;

	this->time_vct = this->set_time();
	while (!check_sorting<std::vector<unsigned int> >(this->vct))
		this->vct = merge_insert_sort<std::vector<unsigned int> >(this->vct);
	this->time_vct = this->set_time() - this->time_vct;

	this->display_tab<std::list<unsigned int> >(this->lst, "After: "); //list version
	// this->display_tab<std::vector<unsigned int> >(this->vct, "After: "); //vector version
}

u_int64_t	PmergeMe::set_time()
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return (time.tv_sec * 1000000 + time.tv_usec);
}

void	PmergeMe::display_process_time()
{
	std::cout << "Time to process a range of " << this->lst.size();
	std::cout << " elements with std::list : ";
	std::cout << YELLOW << BOLD << this->time_lst << RESET;
	std::cout << " us" << std::endl;

	std::cout << "Time to process a range of " << this->vct.size();
	std::cout << " elements with std::vector : ";
	std::cout << YELLOW << BOLD << this->time_vct << RESET;
	std::cout << " us" << std::endl;
}