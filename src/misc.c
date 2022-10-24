/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   misc.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dantonik <dantonik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 05:50:40 by dantonik          #+#    #+#             */
/*   Updated: 2022/10/21 23:04:10 by dantonik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../inc/push_swap.h"

void	swap_rotate(t_ll **a)
{
	swap(a, 'a');
	rotate(a);
}

void	three_numbers(t_ll	**a)
{
	if ((*a)->head->pos > (*a)->head->next->next->pos && \
		(*a)->head->next->pos < (*a)->head->next->next->pos)
	{
		if ((*a)->head->pos > (*a)->head->next->next->pos)
			rotate(a);
		else
			swap(a, 'a');
	}
	else if ((*a)->head->pos < (*a)->head->next->pos && \
		(*a)->head->next->pos > (*a)->head->next->next->pos)
	{
		if ((*a)->head->pos > (*a)->head->next->next->pos)
			rrotate(a);
		else
			swap_rotate(a);
	}
	else if ((*a)->head->pos < (*a)->head->next->next->pos && \
		(*a)->head->pos > (*a)->head->next->pos)
		swap(a, 'a');
	else
	{
		swap(a, 'a');
		rrotate(a);
	}
}

void	init_ll(t_ll **a, t_ll **b)
{
	(*a) = (t_ll *)malloc(sizeof(t_ll));
	(*b) = (t_ll *)malloc(sizeof(t_ll));
	(*a)->head = NULL;
	(*b)->head = NULL;
	(*a)->length = 0;
	(*b)->length = 0;
}

void	free_ll(t_ll *a, t_ll *b)
{
	t_node	*temp_a;
	t_node	*temp_b;

	temp_a = a->head;
	temp_b = b->head;
	while (temp_a != NULL)
	{
		a->head = a->head->next;
		free (temp_a);
		temp_a = a->head;
	}
	while (temp_b != NULL)
	{
		b->head = b->head->next;
		free (temp_b);
		temp_b = b->head;
	}
	free(a);
	free(b);
}

int	int_min_max_checker(char *ptr)
{
	long	num;

	num = ft_atoi(ptr);
	if (num > INT_MAX || num < INT_MIN)
		return (1);
	return (0);
}
