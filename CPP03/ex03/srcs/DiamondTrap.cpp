/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljohnson <ljohnson@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 00:35:08 by ljohnson          #+#    #+#             */
/*   Updated: 2023/01/25 15:43:12 by ljohnson         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <DiamondTrap.hpp>

#define RED "\033[31m"
#define GREEN "\033[32m"
#define BOLD "\033[1m"
#define FAINT "\033[2m"
#define FWHITE "\033[0m"

/* ************************************************************************** */
/* Constructors & Destructors */
/* ************************************************************************** */
DiamondTrap::DiamondTrap() : name("D14M0ND-TP")
{
	std::cout << FAINT;
	std::cout << "DiamondTrap " << this->name << " default constructor called";
	std::cout << FWHITE << std::endl;
	return ;
}

DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name), ScavTrap(name), FragTrap(name), name(name)
{
	std::cout << FAINT;
	std::cout << "DiamondTrap " << this->name << " constructor called";
	std::cout << FWHITE << std::endl;
	return ;
}

DiamondTrap::DiamondTrap(DiamondTrap const& src) : ClapTrap(src), ScavTrap(src), FragTrap(src)
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
void	DiamondTrap::whoAmI()
{
	std::cout << "name = " << this->name << std::endl;
	std::cout << "Hit Points = " << this->hit_points << std::endl;
	std::cout << "Energy Points = " << this->energy_points << std::endl;
	std::cout << "Attack Damage = " << this->attack_damage << std::endl;
	std::cout << std::endl;
	std::cout << "Max Hit Points = " << this->max_hit_points << std::endl;
	std::cout << "Max Energy Points = " << this->max_energy_points << std::endl;
}


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
