/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljohnson <ljohnson@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 00:35:08 by ljohnson          #+#    #+#             */
/*   Updated: 2022/12/09 00:37:56 by ljohnson         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <DiamondTrap.hpp>

/* ************************************************************************** */
/* Constructors & Destructors */
/* ************************************************************************** */
DiamondTrap::DiamondTrap()
{
	std::cout << FAINT;
	this->name = "Diamondb*tch";
	std::cout << "DiamondTrap " << this->name << " default constructor called";
	std::cout << FWHITE << std::endl;
	return ;
}

DiamondTrap::DiamondTrap(std::string name)
{
	std::cout << FAINT;
	this->name = name;
	std::cout << "DiamondTrap " << this->name << " constructor called";
	std::cout << FWHITE << std::endl;
	return ;
}

DiamondTrap::DiamondTrap(DiamondTrap const& src)
{
	*this = src;
	std::cout << FAINT;
	std::cout << "DiamondTrap " << this->name << " copy constructor called";
	std::cout << FWHITE << std::endl;
	return ;
}

DiamondTrap::~DiamondTrap()
{
	std::cout << FAINT;
	std::cout << "DiamondTrap " << this->name << " destructor called";
	std::cout << FWHITE << std::endl;
	return ;
}

/* ************************************************************************** */
/* Public member functions */
/* ************************************************************************** */

/* ************************************************************************** */
/* Arithmetic Operator Overloads */
/* ************************************************************************** */
DiamondTrap&	DiamondTrap::operator=(DiamondTrap const& rhs)
{
	this->name = rhs.name;
	this->hit_points = rhs.hit_points;
	this->energy_points = rhs.energy_points;
	this->attack_damage = rhs.attack_damage;
	this->max_hit_points = rhs.max_hit_points;
	this->max_energy_points = rhs.max_energy_points;
	return (*this);
}
