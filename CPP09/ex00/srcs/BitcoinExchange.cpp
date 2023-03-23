/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljohnson <ljohnson@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 13:17:50 by ljohnson          #+#    #+#             */
/*   Updated: 2023/03/23 14:42:30 by ljohnson         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <BitcoinExchange.hpp>

/* ************************************************************************** */
/* Constructors & Destructors */
/* ************************************************************************** */
BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(BitcoinExchange const& src)
{
	*this = src;
}

BitcoinExchange::~BitcoinExchange()
{
	this->data.clear();
}
/* ************************************************************************** */
/* Operator Overloads */
/* ************************************************************************** */
BitcoinExchange&	BitcoinExchange::operator=(BitcoinExchange const& rhs)
{
	this->map = rhs.map;
	return (*this);
}

/* ************************************************************************** */
/* Exceptions */
/* ************************************************************************** */

/* ************************************************************************** */
/* Member Functions */
/* ************************************************************************** */
float const&	BitcoinExchange::get_data_by_key(std::string const& key) const {return (this->data[key]);}