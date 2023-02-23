/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljohnson <ljohnson@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 08:19:04 by ljohnson          #+#    #+#             */
/*   Updated: 2023/02/23 08:49:28 by ljohnson         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <Data.hpp>

/* ************************************************************************** */
/* Constructors & Destructors */
/* ************************************************************************** */
Data::Data() : name("ouaf"), age(0)
{
	std::cout << FAINT;
	std::cout << "Default Data constructor called.";
	std::cout << FWHITE << std::endl;
}

Data::Data(Data const& src)
{
	*this = src;
	std::cout << FAINT;
	std::cout << "Copy Data constructor called.";
	std::cout << FWHITE << std::endl;
}

Data::~Data()
{
	std::cout << FAINT;
	std::cout << "Default Data destructor called.";
	std::cout << FWHITE << std::endl;
}

/* ************************************************************************** */
/* Operator Overloads */
/* ************************************************************************** */
Data&	Data::operator=(Data const& rhs)
{
	this->~Data();
	new(this) Data(rhs);
	this->name = rhs.name;
	this->age = rhs.age;
	return (*this);
}

/* ************************************************************************** */
/* Member Functions */
/* ************************************************************************** */
std::string	Data::get_name() const {return (this->name);}
int	Data::get_age() const {return (this->age);}

void	Data::set_name(std::string const name) {this->name = name;}
void	Data::set_age(int const age) {this->age = age;}