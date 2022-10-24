# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dantonik <dantonik@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/07 16:29:54 by dantonik          #+#    #+#              #
#    Updated: 2022/07/07 16:29:54 by dantonik         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = push_swap
AUTHOR = dantonik
DATE = $$(date +%Y/%m/%d)

SRC = push_swap.c operations.c misc.c misc_ll.c fuer_norm.c
CFLAGS = -Wall -Wextra -Werror
CC = cc
LIBFT = ./lib/libft
GNL = ./lib/get_next_line/gnl.a
HEADERS = -I ./include -I $(LIBMLX)/include -I $(LIBFT)
OBJDIR = obj
LIBSDIR	= lib

VPATH = src

COM_COLOR	= \033[0;34m
OBJ_COLOR	= \033[0;36m
OK_COLOR	= \033[0;32m
ERROR_COLOR	= \033[0;31m
WARN_COLOR	= \033[0;33m
NO_COLOR	= \033[m
COM_STRING	= "compiling"

RED			=	\033[0;31m
LBLUE		=	\033[1;34m
LCYAN		=	\033[1;36m
PURPLE		=	\033[0;35m

GREEN		=	\e[38;5;118m
YELLOW		=	\e[38;5;226m
BRed		=	\033[1;31m
RESET		=	\e[0m
_TEST		=	[$(BRed)TEST$(RESET)]
_SUCCESS	=	[$(GREEN)SUCCESS$(RESET)]
_CLEAN		=	[$(YELLOW)CLEAN$(RESET)]
_FCLEAN		=	[$(YELLOW)FCLEAN$(RESET)]

all: header $(NAME)
	@printf "\n"

header:
	@printf "%b" "$(OK_COLOR)"
	@echo " "
	@echo ".#####....####...##..##..######...####...##..##..######..##..##."
	@echo ".##..##..##..##..###.##....##....##..##..###.##....##....##.##.."
	@echo ".##..##..######..##.###....##....##..##..##.###....##....####..."
	@echo ".##..##..##..##..##..##....##....##..##..##..##....##....##.##.."
	@echo ".#####...##..##..##..##....##.....####...##..##..######..##..##."
	@echo "................................................................"
	@echo " "
	@printf "$(RESET)"
	@printf "%b" "$(OBJ_COLOR)\t\tName:	$(WARN_COLOR)$(NAME)\n"
	@printf "%b" "$(OBJ_COLOR)\t\tAuthor:	$(WARN_COLOR)$(AUTHOR)\n"
	@printf "%b" "$(OBJ_COLOR)\t\tDate:	$(WARN_COLOR)$(DATE)\n\n"

OBJS = $(addprefix $(OBJDIR)/, $(SRC:.c=.o))

$(OBJDIR)/%.o: %.c | $(OBJDIR)
	@$(CC) $(CFLAGS) -c $^ -o $@

$(NAME): $(OBJS) inc/push_swap.h | ./lib/libft/libft.a ./lib/ft_printf/printf.a
	@printf "$(YELLOW)\n\t      -> Building $(NAME) ...$(RESET)\n"
	@gcc $(CFLAGS) $(OBJS) lib/libft/libft.a lib/ft_printf/printf.a -o $(NAME)

$(OBJDIR):
	@mkdir -p $(OBJDIR)

./lib/libft/libft.a:
	@make -C ./lib/libft/

./lib/ft_printf/printf.a:
	@make -C ./lib/ft_printf/

clean: header
	@if [ -d "obj" ]; then \
		rm -rf $(OBJDIR); \
		printf "%-53b%b" "$(PURPLE)obj folder deleted:" "$(OK_COLOR)[✓]$(NO_COLOR)\n"; \
	fi
	@make clean -C ./lib/libft/
	@make clean -C ./lib/ft_printf/
	@printf "%-53b%b" "$(LBLUE)libft clean:" "$(OK_COLOR)[✓]$(NO_COLOR)\n"
	@printf "%-53b%b" "$(LBLUE)printf clean:" "$(OK_COLOR)[✓]$(NO_COLOR)\n"
	@printf "%-53b%b" "$(LBLUE)gnl clean:" "$(OK_COLOR)[✓]$(NO_COLOR)\n"
	@printf "\n"

fclean: clean
	@make fclean -C ./lib/libft/
	@make fclean -C ./lib/ft_printf/
	@if [ -f "push_swap" ]; then \
		rm -rf $(NAME); \
		printf "%-53b%b" "$(PURPLE)push_swap executable deleted :" "$(OK_COLOR)[✓]$(NO_COLOR)\n"; \
	fi
	@printf "%-53b%b" "$(LCYAN)libft fclean:" "$(OK_COLOR)[✓]$(NO_COLOR)\n"
	@printf "%-53b%b" "$(LCYAN)printf fclean:" "$(OK_COLOR)[✓]$(NO_COLOR)\n"
	@printf "\n"

re: fclean all

.PHONY: bonus clean fclean re all