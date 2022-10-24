/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   misc_ll.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dantonik <dantonik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 13:06:43 by dantonik          #+#    #+#             */
/*   Updated: 2022/10/24 23:36:22 by dantonik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../inc/push_swap.h"

void	five_numbers(t_ll	**a, t_ll **b)
{
	while ((*a)->length > 3)
	{
		if ((*a)->head->pos == 1 || (*a)->head->pos == 2)
			push(a, b, 'b');
		else
			rotate(a);
	}
	if (check_sorted(*a))
		three_numbers(a);
	if ((*b)->length == 2 && ((*b)->head->pos < (*b)->head->next->pos))
		swap(b, 'b');
	while ((*b)->length > 0)
	{
		push(b, a, 'a');
	}
	if (check_sorted(*a))
		swap(a, 'a');
}

int	check_dup(t_ll *a)
{
	t_node	*first;
	t_node	*second;

	first = a->head;
	while (first->next != NULL)
	{
		second = first->next;
		while (second != NULL)
		{
			if (first->value == second->value)
			{
				write(2, "Error\n", 6);
				return (0);
			}
			second = second->next;
		}
		first = first->next;
	}
	return (1);
}

int	check_sorted(t_ll *head)
{
	t_node	*current;

	current = head->head;
	while (current->next != NULL)
	{
		if (current->value > current->next->value)
			return (1);
		current = current->next;
	}
	return (0);
}

int	is_number(char *s)
{
	int	i;

	i = 0;
	if (s[0] == '-')
	{
		if (s[1] == '\0')
			return (1);
		i++;
	}
	while (s[i] != '\0' )
	{
		if (s[i] < '0' || s[i] > '9')
			return (1);
		i++;
	}
	return (0);
}

char	*strip_multi_space(char *s)
{
	int			ij[2];
	int			count;
	char		*new;

	ij[0] = -1;
	ij[1] = 0;
	count = 0;
	while (s[++ij[0]] != '\0')
	{
		if (s[ij[0]] == ' ' || s[ij[0]] == '\t')
			count++;
		if (s[ij[0]] != ' ' && s[ij[0]] != '\t')
		{
			if (count >= 1)
			{
				count = 0;
				s[ij[1]++] = ' ';
			}
			s[ij[1]++] = s[ij[0]];
		}
	}
	s[ij[1]] = '\0';
	new = ft_strdup(s);
	return (new);
}
