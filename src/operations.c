/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dantonik <dantonik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 06:13:29 by dantonik          #+#    #+#             */
/*   Updated: 2022/10/21 22:57:59 by dantonik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../inc/push_swap.h"

void	insert_at_tail(t_ll **a, int value)
{
	t_node	*new;
	t_node	*current;

	new = (t_node *)malloc(sizeof(t_node));
	new->pos = 1;
	(*a)->length++;
	new->value = value;
	new->next = NULL;
	current = (*a)->head;
	if ((*a)->head == NULL)
	{
		(*a)->head = new;
		return ;
	}
	while (current->next != NULL)
		current = current->next;
	current->next = new;
}

void	push(t_ll **a, t_ll **b, char c)
{
	t_node	*temp;

	if ((*a)->head == NULL)
		return ;
	ft_printf("p%c\n", c);
	temp = (*a)->head;
	if ((*a)->head->next == NULL)
	{
		(*a)->head = NULL;
		temp->next = (*b)->head;
		(*b)->head = temp;
		(*a)->length--;
		(*b)->length++;
		return ;
	}
	(*a)->head = (*a)->head->next;
	temp->next = (*b)->head;
	(*b)->head = temp;
	(*a)->length--;
	(*b)->length++;
}

void	rotate(t_ll **a)
{
	t_node	*temp;
	t_node	*iter;

	iter = (*a)->head;
	temp = (*a)->head;
	(*a)->head = (*a)->head->next;
	while (iter->next != NULL)
		iter = iter->next;
	iter->next = temp;
	temp->next = NULL;
	ft_printf("ra\n");
}

void	rrotate(t_ll **a)
{
	t_node	*temp;
	t_node	*iter;

	temp = (*a)->head;
	iter = (*a)->head;
	while (iter->next->next != NULL)
		iter = iter->next;
	(*a)->head = iter->next;
	iter->next->next = temp;
	iter->next = NULL;
	ft_printf("rra\n");
}

void	swap(t_ll **a, char c)
{
	t_node	*temp;
	t_node	*temp2;

	temp = (*a)->head;
	temp2 = (*a)->head->next;
	temp->next = temp->next->next;
	temp2->next = temp;
	(*a)->head = temp2;
	ft_printf("s%c\n", c);
}
