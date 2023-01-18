# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ljohnson <ljohnson@student.42lyon.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/16 15:00:32 by ljohnson          #+#    #+#              #
#    Updated: 2023/01/18 00:55:13 by ljohnson         ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

.PHONY: all clean fclean re

NAME	:=	replace

#//////////////////////////////////////////////////////////////////////////////
#		ALL FILES
#//////////////////////////////////////////////////////////////////////////////

# Files
LST_SRCS	:=	main.cpp
LST_OBJS	:=	$(LST_SRCS:.cpp=.o)

# Directories
P_SRCS		:=	srcs/
P_OBJS		:=	.objs/

# Shortcuts
SRCS		:=	$(addprefix $(P_SRCS),$(LST_SRCS))
OBJS		:=	$(addprefix $(P_OBJS),$(LST_OBJS))

#//////////////////////////////////////////////////////////////////////////////
#		COMMAND SHORTCUTS
#//////////////////////////////////////////////////////////////////////////////

# Commands
CC	:=	c++
CF	:=	-Wall -Werror -Wextra -std=c++98
CS	:=	-g3 -fsanitize=address
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
	$(CC) $(CF) $(OBJS) -o $@

$(P_OBJS)%.o:	$(P_SRCS)%.cpp Makefile | $(P_OBJS)
	$(CC) $(CF) -c $< -o $@

# Directories creation

$(P_OBJS):
	mkdir $(P_OBJS)

# Mandatory Rules
clean:
	$(RM) $(P_OBJS)

fclean:
	$(MAKE) clean
	$(RM) $(NAME)

re:
	$(MAKE) fclean
	$(MAKE) all