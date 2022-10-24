/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dantonik <dantonik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 05:13:23 by dantonik          #+#    #+#             */
/*   Updated: 2022/10/24 23:38:37 by dantonik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include <limits.h>
# include "../lib/libft/libft.h"
# include "../lib/ft_printf/includes/ft_printf.h"

typedef enum e_bool
{
	TRUE = 1,
	FALSE = 0
}	t_bool;

typedef struct Node
{
	int				value;
	int				pos;
	struct Node		*next;
}				t_node;

typedef struct linkedList
{
	int				length;
	struct Node		*head;
}				t_ll;

int		is_number(char *s);

// libft
// long	ft_atoi(const char *str);
int		ft_isdigit(int c);

// misc
void	three_numbers(t_ll	**a);
void	init_ll(t_ll **a, t_ll **b);
void	free_ll(t_ll *a, t_ll *b);
int		int_min_max_checker(char *ptr);
int		is_number(char *s);

void	rrotate(t_ll **a);
void	swap(t_ll **a, char c);
void	five_numbers(t_ll	**a, t_ll **b);
char	*strip_multi_space(char *s);
void	give_pos(t_node *a);

//operations
int		check_dup(t_ll *a);
int		check_sorted(t_ll *head);
void	insert_at_tail(t_ll **a, int value);
void	push(t_ll **a, t_ll **b, char c);
void	rotate(t_ll **a);

void	printl(t_ll *head);

#endif