/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljohnson <ljohnson@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 12:16:58 by ljohnson          #+#    #+#             */
/*   Updated: 2022/12/07 18:31:46 by ljohnson         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <ScavTrap.hpp>

#define YELLOW "\033[33m"
#define CYAN "\033[36m"
#define PURPLE "\033[35m"
#define BOLD "\033[1m"
#define FAINT "\033[2m"
#define FWHITE "\033[0m"

/* ************************************************************************** */
/* Constructors & Destructors */
/* ************************************************************************** */
ScavTrap::ScavTrap()
{
	std::cout << FAINT;
	this->name = "SC4V-TP";
	this->hit_points = 100;
	this->energy_points = 50;
	this->attack_damage = 20;
	this->max_hit_points = this->hit_points;
	this->max_energy_points = this->energy_points;
	std::cout << "ScavTrap " << this->name << " default constructor called";
	std::cout << FWHITE << std::endl;
	return ;
}

ScavTrap::ScavTrap(std::string name)
{
	std::cout << FAINT;
	this->name = name;
	this->hit_points = 100;
	this->energy_points = 50;
	this->attack_damage = 20;
	this->max_hit_points = this->hit_points;
	this->max_energy_points = this->energy_points;
	std::cout << "ScavTrap " << this->name << " constructor called";
	std::cout << FWHITE << std::endl;
	return ;
}

ScavTrap::ScavTrap(ScavTrap const& src) : ClapTrap(src)
{
	*this = src;
	std::cout << FAINT;
	std::cout << "ScavTrap " << this->name << " copy constructor called";
	std::cout << FWHITE << std::endl;
	return ;
}

ScavTrap::~ScavTrap()
{
	std::cout << FAINT;
	std::cout << "ScavTrap " << this->name << " destructor called";
	std::cout << FWHITE << std::endl;
	return ;
}

/* ************************************************************************** */
/* Public member functions */
/* ************************************************************************** */
void	ScavTrap::attack(const std::string& target)
{
	if (this->hit_points == 0)
	{
		std::cout << YELLOW << BOLD;
		std::cout << "A dead " << this->name << " cannot attack " << target;
		std::cout << FWHITE << std::endl;
		return ;
	}
	if (this->energy_points == 0)
	{
		std::cout << YELLOW << BOLD;
		std::cout << "An exhausted " << this->name << " cannot attack " << target;
		std::cout << FWHITE << std::endl;
		return ;
	}
	this->energy_points--;
	std::cout << "ScavTrap ";
	std::cout << CYAN << BOLD;
	std::cout << this->name << FWHITE;
	std::cout << " attacks ";
	std::cout << CYAN << BOLD;
	std::cout << target << FWHITE;
	std::cout << ", dealing ";
	std::cout << YELLOW << BOLD;
	std::cout << this->attack_damage << FWHITE;
	std::cout << " damages !" << std::endl;
	return ;
}

void	ScavTrap::guardGate()
{
	std::cout << PURPLE;
	std::cout << "ScavTrap " << this->name << " entered Gate Keeper mode ! ";
	std::cout << FWHITE << FAINT;
	std::cout << "Wtf is happening ...";
	std::cout << FWHITE << std::endl;
}

/* ************************************************************************** */
/* Arithmetic Operator Overloads */
/* ************************************************************************** */
ScavTrap&	ScavTrap::operator=(ScavTrap const& rhs)
{
	this->name = rhs.name;
	this->hit_points = rhs.hit_points;
	this->energy_points = rhs.energy_points;
	this->attack_damage = rhs.attack_damage;
	this->max_hit_points = rhs.max_hit_points;
	this->max_energy_points = rhs.max_energy_points;
	return (*this);
}
