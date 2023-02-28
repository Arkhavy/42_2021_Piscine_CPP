/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.tpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljohnson <ljohnson@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 14:11:15 by ljohnson          #+#    #+#             */
/*   Updated: 2023/02/28 15:36:43 by ljohnson         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <MutantStack.hpp>

/* ************************************************************************** */
/* Constructors & Destructors */
/* ************************************************************************** */
template<typename T>
MutantStack<T>::MutantStack()
{
	std::cout << FAINT;
	std::cout << "Default MutantStack constructor called.";
	std::cout << FWHITE << std::endl;
}

template<typename T>
MutantStack<T>::MutantStack(MutantStack const& src)
{
	if (this == &src)
		return ;
	*this = src;
	std::cout << FAINT;
	std::cout << "Copy MutantStack constructor called.";
	std::cout << FWHITE << std::endl;
}

template<typename T>
MutantStack<T>::~MutantStack()
{
	std::cout << FAINT;
	std::cout << "Default MutantStack destructor called.";
	std::cout << FWHITE << std::endl;
}

/* ************************************************************************** */
/* Operator Overloads */
/* ************************************************************************** */
template<typename T>
MutantStack<T>&	MutantStack<T>::operator=(MutantStack const& rhs)
{
	return (*this);
}
/* ************************************************************************** */
/* Exceptions */
/* ************************************************************************** */

/* ************************************************************************** */
/* Public member functions */
/* ************************************************************************** */
template<typename T>
typename std::stack<T>::container_type::iterator	MutantStack<T>::begin() {return (this->c.begin());}

template<typename T>
typename std::stack<T>::container_type::iterator	MutantStack<T>::end() {return (this->c.end());}

template<typename T>
typename std::stack<T>::container_type::const_iterator	MutantStack<T>::cbegin() {return (this->c.cbegin());}

template<typename T>
typename std::stack<T>::container_type::const_iterator	MutantStack<T>::cend() {return (this->c.cend());}