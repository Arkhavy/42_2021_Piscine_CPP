# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ljohnson <ljohnson@student.42lyon.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/10 16:58:45 by ljohnson          #+#    #+#              #
#    Updated: 2023/01/16 13:35:18 by ljohnson         ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

.PHONY: all clean fclean re
# .SILENT:

NAME	:=	PhoneBook

#//////////////////////////////////////////////////////////////////////////////
#		ALL FILES
#//////////////////////////////////////////////////////////////////////////////

# Files
LST_INCS	:=	Contact.hpp	PhoneBook.hpp
LST_SRCS	:=	Contact.cpp	PhoneBook.cpp	\
				main.cpp
LST_DEPS	:=	$(LST_SRCS:.cpp=.d)
LST_OBJS	:=	$(LST_SRCS:.cpp=.o)

# Directories
P_INCS		:=	incs/
P_SRCS		:=	srcs/
P_DEPS		:=	.deps/
P_OBJS		:=	.objs/

# Shortcuts
INCS		:=	$(addprefix $(P_INCS),$(LST_INCS))
SRCS		:=	$(addprefix $(P_SRCS),$(LST_SRCS))
DEPS		:=	$(addprefix $(P_DEPS),$(LST_DEPS))
OBJS		:=	$(addprefix $(P_OBJS),$(LST_OBJS))

#//////////////////////////////////////////////////////////////////////////////
#		COMMAND SHORTCUTS
#//////////////////////////////////////////////////////////////////////////////

# Commands
CC	:=	c++
CF	:=	-Wall -Werror -Wextra -std=c++98
CI	:=	-I $(P_INCS)
CS	:=	-g3 -fsanitize=address
CT	:=	-g3 -fsanitize=threads
RM	:=	rm -rf

# Colors
BLACK=\033[30m
RED=\033[31m
GREEN=\033[32m
YELLOW=\033[33m
BLUE=\033[34m
PURPLE=\033[35m
CYAN=\033[36m
WHITE=\033[37m

# Text
ERASE=\033[2K\r
RESET=\033[0m
BOLD=\033[1m
FAINT=\033[2m
ITALIC=\033[3m
UNDERLINE=\033[4m

#//////////////////////////////////////////////////////////////////////////////
#		RULES
#//////////////////////////////////////////////////////////////////////////////

all:	$(NAME)

# Binary creation
$(NAME):	$(OBJS)
	$(CC) $(CF) $(CI) $(OBJS) -o $@

$(P_DEPS)%.d:	$(P_SRCS)%.cpp Makefile | $(P_DEPS)
	$(CC) $(CF) $(CI) -MM -MF $@ -MT "$(P_OBJS)$*.o $@" $<

-include $(DEPS)

$(P_OBJS)%.o:	$(P_SRCS)%.cpp $(P_DEPS)%.d Makefile | $(P_OBJS)
	$(CC) $(CF) $(CI) -I $(P_DEPS)%.d -c $< -o $@

# Directories creation
$(P_DEPS):
	mkdir $(P_DEPS)

$(P_OBJS):
	mkdir $(P_OBJS)

# Mandatory Rules
clean:
	$(RM) $(P_OBJS)
	$(RM) $(P_DEPS)

fclean:
	$(MAKE) clean
	$(RM) $(NAME)

re:
	$(MAKE) fclean
	$(MAKE) all