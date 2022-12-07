/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljohnson <ljohnson@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 18:30:27 by ljohnson          #+#    #+#             */
/*   Updated: 2022/12/07 18:50:42 by ljohnson         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <FragTrap.hpp>

#define YELLOW "\033[33m"
#define CYAN "\033[36m"
#define PURPLE "\033[35m"
#define BOLD "\033[1m"
#define FAINT "\033[2m"
#define FWHITE "\033[0m"

/* ************************************************************************** */
/* Constructors & Destructors */
/* ************************************************************************** */
FragTrap::FragTrap()
{
	std::cout << FAINT;
	this->name = "FR4G-TP";
	this->hit_points = 100;
	this->energy_points = 100;
	this->attack_damage = 30;
	this->max_hit_points = this->hit_points;
	this->max_energy_points = this->max_energy_points;
	std::cout << "Fragtrap " << this->name << " default constructor called";
	std::cout << FWHITE << std::endl;
	return ;
}

FragTrap::FragTrap(std::string name)
{
	std::cout << FAINT;
	this->name = name;
	this->hit_points = 100;
	this->energy_points = 100;
	this->attack_damage = 30;
	this->max_hit_points = this->hit_points;
	this->max_energy_points = this->energy_points;
	std::cout << "Fragtrap " << this->name << " default constructor called";
	std::cout << FWHITE << std::endl;
	return ;
}

FragTrap::FragTrap(FragTrap const& src) : ClapTrap(src)
{
	*this = src;
	std::cout << FAINT;
	std::cout << "FragTrap " << this->name << " copy constructor called";
	std::cout << FWHITE << std::endl;
	return ;
}

FragTrap::~FragTrap()
{
	std::cout << FAINT;
	std::cout << "FragTrap " << this->name << " destructor called";
	std::cout << FWHITE << std::endl;
	return ;
}

/* ************************************************************************** */
/* Public member functions */
/* ************************************************************************** */
void	FragTrap::highFivesGuys(void)
{
	std::cout << PURPLE;
	std::cout << this->name << " IS ASKING FOR A HIGH FIVE !" << std::endl;
	std::cout << FWHITE << FAINT;
	std::cout << "Don't do too much, Claptraps don't deserve that much attention.";
	std::cout << FWHITE << std::endl;
	
}
/* ************************************************************************** */
/* Arithmetic Operator Overloads */
/* ************************************************************************** */
FragTrap&	FragTrap::operator=(FragTrap const& rhs)
{
	this->name = rhs.name;
	this->hit_points = rhs.hit_points;
	this->energy_points = rhs.energy_points;
	this->attack_damage = rhs.attack_damage;
	this->max_hit_points = rhs.max_hit_points;
	this->max_energy_points = rhs.max_energy_points;
	return (*this);
}
