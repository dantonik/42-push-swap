# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dantonik <dantonik@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/05 17:23:42 by dantonik          #+#    #+#              #
#    Updated: 2022/07/27 15:44:08 by dantonik         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = printf.a
CC = cc
CFLAGS = -Wall -Wextra -Werror
AR = ar rcs
RM = rm -f

	# Colors #
GREEN		=	\e[38;5;118m
YELLOW		=	\e[38;5;226m
RESET		=	\e[0m
_SUCCESS	=	[$(GREEN)SUCCESS$(RESET)]
_INFO		=	[$(YELLOW)CLEAN$(RESET)]

SRC =	ft_printf.c \
		ft_putnbr.c \
		ft_putchar.c \
		ft_putstr.c \
		ft_puthex.c \
		ft_putptr.c \
		ft_putu.c

OBJS =	$(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJS) ./includes/ft_printf.h
	@$(AR) $(NAME) $^
	@printf "$(YELLOW)\n\t      -> Building $(NAME) ...$(RESET)\n"

%.o : %.c 
	@$(CC) -c $(CFLAGS) $< -o $@

clean:
	@$(RM) $(OBJS) $(BONUSOBJ)

fclean: clean
	@$(RM) $(NAME)

re: fclean all

.PHONY: bonus clean fclean re all