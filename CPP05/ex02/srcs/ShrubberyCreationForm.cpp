/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljohnson <ljohnson@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 11:54:13 by ljohnson          #+#    #+#             */
/*   Updated: 2023/02/15 16:57:44 by ljohnson         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <ShrubberyCreationForm.hpp>
#include <fstream>

/* ************************************************************************** */
/* Constructors & Destructors */
/* ************************************************************************** */
ShrubberyCreationForm::ShrubberyCreationForm() :
	AForm("ShrubberyCreationForm", 145, 137), target("Default")
{
	std::cout << FAINT;
	std::cout << "Default ShrubberyCreationForm constructor called.";
	std::cout << FWHITE << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string const target) :
	AForm("ShrubberyCreationForm", 145, 137), target(target)
{
	std::cout << FAINT;
	std::cout << "ShrubberyCreationForm with target [" << this->target << "] constructor called.";
	std::cout << FWHITE << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const& src) :
	AForm(src)
{
	*this = src; //Need potential change later to check Shallow and Deep Copy
	std::cout << FAINT;
	std::cout << "Copy ShrubberyCreationForm with target [" << this->target << "] constructor called.";
	std::cout << FWHITE << std::endl;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	std::cout << FAINT;
	std::cout << "Default ShrubberyCreationForm with target ["<< this->target << "] destructor called.";
	std::cout << FWHITE << std::endl;
}

/* ************************************************************************** */
/* Operator Overloads */
/* ************************************************************************** */
ShrubberyCreationForm&	ShrubberyCreationForm::operator=(ShrubberyCreationForm const& rhs)
{
	this->~ShrubberyCreationForm();
	new(this) ShrubberyCreationForm(rhs.target);
	return (*this);
}

/* ************************************************************************** */
/* Exceptions */
/* ************************************************************************** */
char const*	ShrubberyCreationForm::FileNotGoodException::what() const throw() {return ("File does not exist or can't be written in !");}

/* ************************************************************************** */
/* Public Member Functions */
/* ************************************************************************** */
static void	tree_writer(std::ofstream& ofs)
{
	ofs << "                                                               @@                                                               " << std::endl;
	ofs << "                                                             @@ @@                                                              " << std::endl;
	ofs << "                                                           @@@@ @@@  $$@@                                                       " << std::endl;
	ofs << "                                                        @ .@@ .  @@@@$$@@                                                       " << std::endl;
	ofs << "                                                       @@..@@@@@   $$@.  .                                                      " << std::endl;
	ofs << "                                                       ...@@@@@@ @@$$$@@.$$                                                     " << std::endl;
	ofs << "                                                     @@ @@@@@@@..@@@$$$@.$$@@@O                                                 " << std::endl;
	ofs << "                                                     @@@@@@@@@@.@@$$$$$@$$@@@@O.                                                " << std::endl;
	ofs << "                                                     .@@@@@@@@@.@@$$@@$$$$@@@@.                                                 " << std::endl;
	ofs << "                                                    .@@@@@@@@@@@@$$$$$$$@@@@@@@. .                                              " << std::endl;
	ofs << "                                                    @@@  @@@@$$$$$$$$$$@@@@@@@@@@..OO                                           " << std::endl;
	ofs << "                                                 @@@@@@@@@@@@$$$$$$@@$$@@@@@@@@@@. OO                                           " << std::endl;
	ofs << "                                                 @@@@@$$@@@@@@@@@$$$$$$@@@@@@@O@@  @@                                           " << std::endl;
	ofs << "                                                  @@@@$$$@$$@$$$@$$$$$$$$@@@..@@@  @@                                           " << std::endl;
	ofs << "                                          O       @@O@@$$$$@@$$@@$$@@@@$$@@@..@@O  @@O                                          " << std::endl;
	ofs << "                                 OO      OO OOOO  @@O@$$$$$@@$$@$$$@@@@@.@@@@.@@O  O@@     @    @                               " << std::endl;
	ofs << "                               OOOOOO    @O@OOOO@@ O@@$$$$$$@@$$$$@@@@@@@@@@@O@@O. O@@    OO@O  @                               " << std::endl;
	ofs << "                               OO  OOOOOOO@OOOO@@@O$$@@$$$$$@$$$$$@@@@@@@@@O@@@@O@@.OOOOOOOOOOO @@                              " << std::endl;
	ofs << "                              @@OOO@@@@OOO OOOOO@@O$$$$$$$$$$$$$$$@@@@@@@@@@@@@@@@@OOOOOOOOO @@O@@O                             " << std::endl;
	ofs << "                            O@@@@@O@@@@OO@OOO OO@@@$..$$$$$$$$$$@@@@@@@@@@@@@@@O@@.OO @@@@O@@@@@@@O                             " << std::endl;
	ofs << "                            O@@@@@@@OOOO@OO@O@O O@@$..@$$$$$$$$@@@@@@@@@@@@@OOOOO.O@O@O$$@@@@OO@@OOO                            " << std::endl;
	ofs << "                          @@ @@@@@@@@OOOO@@@@OOOO@OO..@$$$$$$$@@@@@@@@@@@@@@@@@@$$OOO@O$$OOOOOOOO O@@O                          " << std::endl;
	ofs << "                          @@@@O@@@@@@O@ OO@@@OOOOOO.$..$$@@$$O@@@@@@@@@OO@@@@@@$$$$$$$@$$@@@@@OO@@@@@OO                         " << std::endl;
	ofs << "                       @@  @@@ @@@@OOO@OOOOO@@@OOOOOO..OO@@$$O@OO@@@O@OOO@@@@@$$$$$$$$@$$$$@@@OO@@@OOO                          " << std::endl;
	ofs << "                       @@OO$$$@@@@OO@@@@@OOO@OO@OOO@...OO@$$$@@OO@OOO@OO@@@@@@$$$$$$$$$$@$$@@OO@@@O O O O@@                     " << std::endl;
	ofs << "                         O@$$$$$$@@@$$@@@@@@@OO@O.....$@@@$$OOO@@@OOO@@@@@.@@@@$$O$$$$$$O$$@@OO@O@@OOOOOO@@                     " << std::endl;
	ofs << "                      @$$@@$$$$$$@@$$$O@O@@@@O@@O.....@@@OO@@OO@@@@OO@@@@@@@@$OO$$$$$$$@$$$$@@@OO@@@@ OOOOO                     " << std::endl;
	ofs << "                     O@$$@$$$$$$O@@$$$OO@@@@@@@@@O....@O@..O..@@@@@@O@@@@OOOO$OO$$$$$$$O$$$$OOOOOO@@@O@@OOOO                    " << std::endl;
	ofs << "                    @$$@$$$$$$$$$$$$$$O@@@@@@@@OOOOO..OOO.......OO@.@OOOOOOOO$$$$$$$$$@@@@@@OOOO@@OOOO@@O O                     " << std::endl;
	ofs << "                   @@$$O$$$$$$$$$$@@$$O@@@@O@@@OOOO.......$$....OOOOOOOOOO$$$$$$$$$$$$$$$@@@@OO@@@@@@OOOO                       " << std::endl;
	ofs << "                   @@@@$$$$$$$$$$@@@@$@@@@@@@@@OOO@...o...$$..@OOOOO.OOOOO@OO$$$$$$$$$$$$$$@@O@@@@@@@@OO                        " << std::endl;
	ofs << "                    @@@$$$$$$$$$$$$@@@@$@@@@@O@@@OO@@@o.@..OOO@OOOOOOOO.OO@OO$$$@$$$$@@@@$$@@@@@OOO.@@@@O .                     " << std::endl;
	ofs << "                    @@@OO@$$$$$$$@@$@@@$@@@@@@OO@@@O@@O@@@@OOOO@@OOOOOOOOO$$@$$$$@$$$@OO@@@@@@@OOOOOOO@@....                    " << std::endl;
	ofs << "                    O@@OO$$$$$$$$@@$@@@@@OO@@@OOO@@.o.O@@O@OO.O@@OOO@OOO..$$@$$$$OOO$$O@@@@@OO@@OOOOOOOO...                     " << std::endl;
	ofs << "                  OOO@@$$$$$$$$$$$$$@@$@@@@@OO..O@@o..O@@O@OO.@@OO@@@OOO...O.$$OOO$$$@@@@@@@@@@@OO@@OOO.O...                    " << std::endl;
	ofs << "                 OOOO O$$$$$$$$@@$$$O$$@@@@@OO..O@@@..O@@OO@@.@@@@@@@@OOOOOO....O@$$@@@OOOO@@@@@@O@@.....O...                   " << std::endl;
	ofs << "                OOOO O$$$$$$$$@@@$$$$@@@@@@@@@@@..@@..@@@OO$$.@$$O$$$$$$$OOOOO..@@@@@@O@@OO@@O@@@@@@@...O....                   " << std::endl;
	ofs << "                 OO OO$$@@@$$$$O$$$$$@@@@@@@@@@...Oo..O@O@@$$$$$$$$$$$$$$@@O@@OOO@@@@OO@@OOOO@@@@@@@@........OO                 " << std::endl;
	ofs << "                 OOOO@@@@@$$O$$@$$@@@@@@@@@@@@@....o..OOO@@$$$$$$$$$@@$$$$@@@O@OO@...O@@OOOOOO.@@.@@OO..O....OO                 " << std::endl;
	ofs << "                 OOOO@@@@@$$@@O@@@@@@@@@@@@@OOO@...o..@@O@OO$$$$$$$$$$@$$$@@@@@OOO...@@.OOOOOO@OOO..O.OO.......O                " << std::endl;
	ofs << "                 O  @@@@@@@@@@O@@OO@OO@@@O@@OOOO...o..OOO@@$$$$$$$@@$$$$$O@@@@@OOOO..@@.O.OO.@@OOO...OO...@@..OOO               " << std::endl;
	ofs << "                   O@@@@@@@@@@@@@OOOOO@@@@@@@OOO...o.O@OO@$$$$$$$@@$$$$$@@@@OO@@O@@.oOO.....OO.OOOO.....OO@@.OOO                " << std::endl;
	ofs << "                    O..OO@@@@@@@@OOOOO@@@@@@@OOOo.OoOO$$OO$$$$$$$@$$$@$$@@@@@@@@@@@.oOO..O..OO...OO.....OO...OOOO O             " << std::endl;
	ofs << "                    ...OOOO@@OOO@@OOOOOO@@OO@OOOo..o.@$$O$$$$$$$@@$@@@$$@@@@@.@.O@..oOO..@@...........@@..O..OOOOOOO            " << std::endl;
	ofs << "                  O... O O..OOOOOO@@OOOOOOOO@@@@oo.o.@$$@$$$$$$@@@@@@@@@@@@@@@@@@@@.@@...@@........ooo@@o....O.....O  O..       " << std::endl;
	ofs << "                   @@..@@O@OO@@OOO@@OOOOO@@@OOOOOo.o..@@O$$$$$@@@@@$@@@@@@@@@@@..@@@@@.@@...OO.oooo...@@....OO.....O O...       " << std::endl;
	ofs << "                  O@@.OO@@OOO@OOOOOOOO@OOO@@..OO.o.o..@@@$$$$$$@@@@@@@@@@@@@@.@.@.@@@@.@@....oooO@@...@@.O......OOO ....        " << std::endl;
	ofs << "                  OO..OO@@O..OOOOOOOOO@OOO@@@....ooo....@OO$$@$$O@@@@@O@@@@O.@.@@@@@.@.@@@@.o$$OO@$$..............OO.......     " << std::endl;
	ofs << "                    @@..@@@..OOOO@OOO@@oooo@@@@o@@ooo.@@....$$@@@@@@@@@OO@.@...@@@oO@@.@$@@$$$$@OO$$O@.............O.......     " << std::endl;
	ofs << "                  ..@@..@..@OO@OO.OOO@OOooooo@@o@@@oo.@@.@@.$$@@@@@@O@@$$...@@@@@@oO@@.@$$$$$$$$O@$$$$$.......O.....O ....      " << std::endl;
	ofs << "                  ..@.......O.@OO.OO@@OO..$$$..$$@@@@@@..@@.O@@@@@@@@O@$$..$$.....o....@$@@$@$$$$$$$$$$$.$$O..O.. .......       " << std::endl;
	ofs << "                    ........O.OOO.OO@@....$$$OOOOO@@@@@O...@@O@@@@O@@.O@...$$@@...o....@$@@$$$$$$$$$OO$$$$$..OOO..O......       " << std::endl;
	ofs << "                     O.......@OOO.OO@.....$$$@@@@OO$@@@o...@@O@@@X@@@@@O@...@@O@.oo....O$$$$$OO$$$@$$O..$$@..@OO..O.....        " << std::endl;
	ofs << "                       ........o......O.$$$$$$$@@@@$@@oo.O@@.OO..@@@@@@O@.@@.OO..oo.$$.$@$$$@O$$$$$$$$....@@@@@OOOO.....O       " << std::endl;
	ofs << "                      O.O.O.........O...O$$$$$$$$@@$@@oooO@@OOO..@@..OO@@.OO....oo..$$.$$$$$$$$$$$$$@$$O$$@@O@@OO....O ..       " << std::endl;
	ofs << "                       ....O.......OO.$$OOO$$$$$$$$$@@$@oooO..O..@@@@OOO@.O..OOoo.$$@$.@$$$$$$@@$$@O@@OO$$OOOOOOO........       " << std::endl;
	ofs << "                        .OOO........@$$$O@$$$$$$$$$$@@$@@@@o..OOOO@@OOOO@.OO..Oo..$$$$.@@$$$$$@@@@$$@@O@@@O@@OO........OO       " << std::endl;
	ofs << "                        .   .  ....@@$$O$$$$$$$$$$$$@@$$$$@oo..O....OOO...O...oo.O@$$O.@@@$$$@$$$@$$OO@@@@@@@O@....OO..OOO      " << std::endl;
	ofs << "                        .  @.@@....@O@O$$$$$$$@@@$$$$@$$$$@OOooO..@@@O....OO.oo.XO@@@$.@$$$$@O$$$O$$@@@OO@@@@O@@.......OO       " << std::endl;
	ofs << "                        .  @.@@...@@@O$$$$$$$$$@@@$$$$$@$$@$$@OOO@@@@.....O..oOOOO@@@$.$$$@@@$$@@@@@@@O@@@@@O@@@@......O        " << std::endl;
	ofs << "                        .     ...@@@@$$$$$$$$$$$@@$$$$$$@@@$$@OOO@@@@@.@@..oo..OOO@@@@OO..@@@$$@@@@@@@@@@@@@O@@@@O..OOO         " << std::endl;
	ofs << "                        .    .....@..$$$$@$$@@@@@@@@@$@@@@@@O@@@o.@@@@.@@ooXXX.XXXO@@@OO.@@@@@O@@@@@@@@@@OO@..O@@O.. OOO        " << std::endl;
	ofs << "                            ......O..O$$$@@@@@@@@@@@@@@@@@@@@@@@ooOO@@..ooXXOO.XXOO@@@@.@@O@@@O@@@@@@@@@@@@@....OO.OOOO         " << std::endl;
	ofs << "                            .....@.OOO$$$@@@@$$$$$$@@@@@@@@@@@O@@o.XX...@@XXOO.XXO@@@@OO@@O@@@OO@@@@@@@@@@@@@...OO.O O          " << std::endl;
	ofs << "                             .......OOO@@@@@@$$$$@@@@@@@@@@@@@O@@ooooX.o@@XXXX.oo@@@@@OO@@@@OO@@@@O@@@O@@@OO@@OOOO.OO           " << std::endl;
	ofs << "                            O. .....@@@@@@@@@@@@@@@@@O@@..@@@@O...@@ooooO.XX+X.O@@@@@@OO@@@@OOO@@@O@@@O@@@@......O.OOO          " << std::endl;
	ofs << "                           O......@OO@@@@@@O@@@@@O@@@O@@@@@@@O....@@oooO..OOoo.O@@.OO...O..@@OO@@@@@OO@@@@@......O. O           " << std::endl;
	ofs << "                            .. ...OOO@@@@@@O@@@@@@@@@@@@@@@@O..OXO..OooO.+OOoO.O..@@O...@@O@@@@OO@@@@O@@O @....OOO..            " << std::endl;
	ofs << "                            ......O.@O@@@@@@OO@@@@@@@@@@@@.O..OOOXOOooXO.XXooO....@@...@@@O@@@@O@@@@@@@@@@O..OOOOO .            " << std::endl;
	ofs << "                            .  ....OOOO@@O@@@@@@@@@@@@@@..OOO.OOOOX+XoOO.XoX...........@@O@@OOOO@@@OO@@..... O...  .            " << std::endl;
	ofs << "                              O.....O.OO.OO@@@@@@@@@@@Oo .@@O. OOOOXooXO.oX........@@..@@O.@@@@@O@..OO......@ ...  .            " << std::endl;
	ofs << "                             O.....@@..O..O@@@@.@@@@@@Ooo.@@@  XXOoooXXX...........@@......@@@@@@@...O....@@..     .            " << std::endl;
	ofs << "                              .............@.@@.@@.....ooo@@ooooXoX+ooX.X.................@@.@@..@@.. .....@..     .            " << std::endl;
	ofs << "                              ..............OOO.@@@@...o.ooooo Xooo++#X................O@@@@.@@..@@..@@....                     " << std::endl;
	ofs << "                              ........O .....O..@@@@.. .. O   XXo###+oX................O@@  ..@@ ....@@                         " << std::endl;
	ofs << "                               .........O. ......@@......    XXo##+++Xo......................@@@@.....@                         " << std::endl;
	ofs << "                              O.O OO....OO..O......... .    XXX+##++XoX. ................. ..@@.......                          " << std::endl;
	ofs << "                               .   O... O .OOO . .. .      XXooo++oXoXX.  .......... .....  .......                             " << std::endl;
	ofs << "                               .         ...O ...         XXooo++oooXX . ........................                               " << std::endl;
	ofs << "                               .          .    .          XXo+++ooooX  .... .... .......... .....                               " << std::endl;
	ofs << "                               .               .          +++#++oooXX  . . .... . . .. ..........                               " << std::endl;
	ofs << "                               .               .        X++##+++oooXX  .    ......    ......... .                               " << std::endl;
	ofs << "                               .               .       X+###++++ooXX   .     .....     .... .. ..                               " << std::endl;
	ofs << "                               .               .       X##+++ooooXXX   .      . .     ...       .                               " << std::endl;
	ofs << "                                               .       ###+++ooooXXX   .      .        .        .                               " << std::endl;
	ofs << "                                               .       #+++++ooooXX    .                        .                               " << std::endl;
	ofs << "                                               .       #o++ooooooXX                             .                               " << std::endl;
	ofs << "                                               .       ##oooooooXX                              .                               " << std::endl;
	ofs << "                                               .       #+ooooooXXX                               .                              " << std::endl;
	ofs << "                                               .      ##+ooooooXX                                .                              " << std::endl;
	ofs << "                                               .      ##+++ooooX                                 .                              " << std::endl;
	ofs << "                                               .      ###+++ooXX                                 .                              " << std::endl;
	ofs << "                                               .      ###+++ooXX                                 .                              " << std::endl;
	ofs << "                                                      X++++++oXX                                 .                              " << std::endl;
	ofs << "                                                      XXXXoo+ooXX                                                               " << std::endl;
	ofs << "                                                       XXXoooooXX                                                               " << std::endl;
	ofs << "                                                        XXXXoooXXX                                                              " << std::endl;
	ofs << "                                                        XXXXooXXXX                                                              " << std::endl;
	ofs << "                                                         XoXooXXXX                                                              " << std::endl;
	ofs << "                                                         XoooooXXX                                                              " << std::endl;
	ofs << "                                                         XXooooXXX                                                              " << std::endl;
	ofs << "                                                         XXoXooXX                                                               " << std::endl;
	ofs << "                                                         XXooooXX                                                               " << std::endl;
	ofs << "                                                         XXoo++XX                                                               " << std::endl;
	ofs << "                                                         XoXX++XX                                                               " << std::endl;
	ofs << "                                                         XXoo++XX                                                               " << std::endl;
	ofs << "                                                        XXXo+++XXX                                                              " << std::endl;
	ofs << "                                                        XXoo+++XXX                                                              " << std::endl;
	ofs << "                                                        Xoo+++XXXX                                                              " << std::endl;
	ofs << "                                                       oooo++oXXX                                                               " << std::endl;
	ofs << "                                                       oooo++ooXX                                                               " << std::endl;
	ofs << "                                                      ++ooo++ooXX                                                               " << std::endl;
	ofs << "                                                     #++ooo++ooXX                                                               " << std::endl;
	ofs << "                                                     +++ooo+++oXX                                                               " << std::endl;
	ofs << "                                                    #+++ooo+++oXXX                                                              " << std::endl;
	ofs << "                                                  ###+++ooo+++oXXXX                                                             " << std::endl;
	ofs << "                                                  ###+oXooX++oXXXXX                                                             " << std::endl;
	ofs << "                                                 +##++ooooX+++XXXXX                                                             " << std::endl;
	ofs << "                                                ###+++ooooXX++oXXXXoX                                                           " << std::endl;
	ofs << "                                              ####+++ooooXXo++oXXoXXXX                                                          " << std::endl;
	ofs << "                                            o+++++ooooooXXXo++oXXXXXXXX                                                         " << std::endl;
	ofs << "                                           +++++ooooooooXXXoooooXXXXXXXXXX                                                      " << std::endl;
	ofs << "                                         o+++++ooooooooXXXX++++oXXoXXXXXXXX                                                     " << std::endl;
	ofs << "                                        oooooooooXooooXXXo++++++ooooooooooXX                                                    " << std::endl;
	ofs << "                                       oooooooXXXooooXXXo+++##+++ooXoooooooX                                                    " << std::endl;
	ofs << "                                    XoooooooXXXXXoooXXXXo++####++ooXXooooooX                                                    " << std::endl;
	ofs << "                                    XoooooXXXXXXXXXXXXXXXXX####++ooXXXXooooX                                                    " << std::endl;
	ofs << "                                                                                                                                ";
}

void	ShrubberyCreationForm::execute(Bureaucrat const& executor) const
{
	std::string	new_filename = this->target;
	new_filename.append("_shrubbery");
	char const*	last_filename = new_filename.c_str();

	if (!this->get_is_signed())
		throw NotSignedException();
	if (executor.getGrade() > this->get_exec_req())
		throw GradeTooLowException();

	std::ofstream	ofs;

	ofs.open(last_filename, std::ofstream::out);
	if (!ofs.good())
		throw FileNotGoodException();
	tree_writer(ofs);
	ofs.close();
}