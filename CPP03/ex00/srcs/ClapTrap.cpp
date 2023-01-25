/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljohnson <ljohnson@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/24 16:07:07 by ljohnson          #+#    #+#             */
/*   Updated: 2023/01/25 13:57:17 by ljohnson         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <ClapTrap.hpp>

#define RED "\033[31m"
#define GREEN "\033[32m"
#define BOLD "\033[1m"
#define FAINT "\033[2m"
#define FWHITE "\033[0m"

/* ************************************************************************** */
/* Constructors & Destructors */
/* ************************************************************************** */
ClapTrap::ClapTrap() : name("CL4P-TP"), hit_points(10), energy_points(10), attack_damage(0)
{
	std::cout << FAINT;
	std::cout << "ClapTrap " << this->name << " default constructor called";
	std::cout << FWHITE << std::endl;
	return ;
}

ClapTrap::ClapTrap(std::string name) : name(name), hit_points(10), energy_points(10), attack_damage(0)
{
	std::cout << FAINT;
	std::cout << "ClapTrap " << this->name << " constructor called";
	std::cout << FWHITE << std::endl;
	return ;
}

ClapTrap::ClapTrap(ClapTrap const& src)
{
	*this = src;
	std::cout << FAINT;
	std::cout << "ClapTrap " << this->name << " copy constructor called";
	std::cout << FWHITE << std::endl;
	return ;
}

ClapTrap::~ClapTrap()
{
	std::cout << FAINT;
	std::cout << "ClapTrap " << this->name << " destructor called";
	std::cout << FWHITE << std::endl;
	return ;
}

/* ************************************************************************** */
/* Public member functions */
/* ************************************************************************** */
void	ClapTrap::attack(const std::string& target)
{
	if (this->hit_points == 0)
	{
		std::cout << RED << BOLD;
		std::cout << "A dead " << this->name << " cannot attack " << target;
		std::cout << FWHITE << std::endl;
		return ;
	}
	if (this->energy_points == 0)
	{
		std::cout << RED << BOLD;
		std::cout << "An exhausted " << this->name << " cannot attack " << target;
		std::cout << FWHITE << std::endl;
		return ;
	}
	this->energy_points--;
	std::cout << "ClapTrap ";
	std::cout << GREEN << BOLD;
	std::cout << this->name << FWHITE;
	std::cout << " attacks ";
	std::cout << GREEN << BOLD;
	std::cout << target << FWHITE;
	std::cout << ", causing ";
	std::cout << RED << BOLD;
	std::cout << this->attack_damage << FWHITE;
	std::cout << " damages !" << std::endl;
	return ;
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	if (this->hit_points == 0)
	{
		std::cout << RED << BOLD;
		std::cout << "A dead " << this->name << " cannot lose more HP, calm down !";
		std::cout << FWHITE << std::endl;
		return ;
	}
	std::cout << "ClapTrap ";
	std::cout << GREEN << BOLD;
	std::cout << this->name << FWHITE;
	std::cout << " just took ";
	std::cout << RED << BOLD;
	std::cout << amount << FWHITE;
	std::cout << " damages !" << std::endl;
	if ((int)(this->hit_points - amount) < 0)
	{
		std::cout << "That one might be a little overkill ... But deserved !" << std::endl; 
		this->hit_points = 0;
		return ;
	}
	this->hit_points -= amount;
	return ;
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (this->hit_points == 0)
	{
		std::cout << RED << BOLD;
		std::cout << "Fortunately, a dead " << this->name << " cannot repair itself !";
		std::cout << FWHITE << std::endl;
		return ;
	}
	if (this->hit_points == 10)
	{
		std::cout << RED << BOLD;
		std::cout << "Fortunately, a fully repaired " << this->name << " cannot repair itself even more !";
		std::cout << FWHITE << std::endl;
		return ;
	}
	if (this->energy_points == 0)
	{
		std::cout << RED << BOLD;
		std::cout << "An exhausted " << this->name << " cannot repair itself";
		std::cout << FWHITE << std::endl;
		return ;
	}
	std::cout << "ClapTrap ";
	std::cout << GREEN << BOLD;
	std::cout << this->name << FWHITE;
	std::cout << " is repairing itself ";
	std::cout << GREEN << BOLD;
	std::cout << amount << FWHITE;
	std::cout << " HP" << std::endl;
	this->energy_points--;
	if ((int)(this->hit_points + amount) > 10)
	{
		std::cout << FAINT;
		std::cout << "ClapTrap " << this->name;
		std::cout << " is a little bit sad to not be able to repair itself even more...";
		std::cout << FWHITE << std::endl;
		this->hit_points = 10;
		return ;
	}
	this->hit_points += amount;
	return ;
}

/* ************************************************************************** */
/* Arithmetic Operator Overloads */
/* ************************************************************************** */
ClapTrap&	ClapTrap::operator=(ClapTrap const& rhs)
{
	this->name = rhs.name;
	this->hit_points = rhs.hit_points;
	this->energy_points = rhs.energy_points;
	this->attack_damage = rhs.attack_damage;
	return (*this);
}
