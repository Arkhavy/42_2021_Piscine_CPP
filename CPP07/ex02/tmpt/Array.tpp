/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljohnson <ljohnson@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 13:36:30 by ljohnson          #+#    #+#             */
/*   Updated: 2023/02/27 13:21:26 by ljohnson         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <Array.hpp>

/* ************************************************************************** */
/* Constructors & Destructors */
/* ************************************************************************** */
template<typename T>
Array<T>::Array() : array_size(0)
{
	std::cout << FAINT;
	std::cout << "Default Array constructor called.";
	std::cout << FWHITE << std::endl;
	this->array = new(std::nothrow) T[0];
	if (!this->array)
		this->~Array();
}

template<typename T>
Array<T>::Array(unsigned int n) : array_size(n)
{
	std::cout << FAINT;
	std::cout << "Array constructor called.";
	std::cout << FWHITE << std::endl;
	this->array = new(std::nothrow) T[n];
	if (!this->array)
		this->~Array();
}


template<typename T>
Array<T>::Array(Array const& src)
{
	std::cout << FAINT;
	std::cout << "Copy Array constructor called.";
	std::cout << FWHITE << std::endl;
	if (this == &src)
		return ;
	*this = src;
}

template<typename T>
Array<T>::~Array()
{
	std::cout << FAINT;
	std::cout << "Default Array destructor called.";
	std::cout << FWHITE << std::endl;
	delete [] this->array;
	this->array = NULL;
	return ;
}


/* ************************************************************************** */
/* Operator Overloads */
/* ************************************************************************** */
template<typename T>
Array<T>&	Array<T>::operator=(Array const& rhs)
{
	if (this == &rhs)
		return (*this);
	// delete [] this->array;
	// this->array = NULL;
	this->array = new(std::nothrow) T[rhs.size()];
	if (!this->array)
		return (*this);
	this->array_size = rhs.size();
	return (*this);
}

template<typename T>
T&	Array<T>::operator[](unsigned int const idx)
{
	if (idx >= this->size() || idx < 0)
		throw OutOfRangeException();
	return (this->array[idx]);
}

template<typename T>
T const&	Array<T>::operator[](unsigned int const idx) const
{
	if (idx >= this->size() || idx < 0)
		throw OutOfRangeException();
	return (const_cast<T const&>(this->array[idx]));
}

/* ************************************************************************** */
/* Public member functions */
/* ************************************************************************** */
template<typename T>
unsigned int	Array<T>::size() const {return (this->array_size);}

/* ************************************************************************** */
/* Exceptions */
/* ************************************************************************** */
template<typename T>
char const*	Array<T>::OutOfRangeException::what() const throw() {return ("ERROR Exception: Out Of Range idx given to Array.");}