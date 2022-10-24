/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dantonik <dantonik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 05:06:43 by dantonik          #+#    #+#             */
/*   Updated: 2022/10/24 23:38:13 by dantonik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../inc/push_swap.h"

t_bool	norm(t_ll **a, char **str, int *j)
{
	if (is_number(str[*j]) == 1 || int_min_max_checker(str[*j]) == 1)
	{
		free(str[(*j)]);
		free(str);
		write(2, "Error\n", 6);
		return (FALSE);
	}
	insert_at_tail(a, ft_atoi(str[*j]));
	free(str[(*j)++]);
	return (TRUE);
}

int	parse_input(t_ll **a, int ac, char **av)
{
	char	**str;
	int		i;
	int		j;
	char	*s;

	i = 0;
	while (++i < ac)
	{
		s = strip_multi_space(av[i]);
		if (*s == '\0')
		{
			free (s);
			write(2, "Error\n", 6);
			return (0);
		}
		str = ft_split(s, ' ');
		free(s);
		j = 0;
		while (str[j])
			if (!norm(a, str, &j))
				return (0);
		if (str)
			free(str);
	}
	return (1);
}

int	bits_set(int length)
{
	unsigned int	l;
	int				bit;

	l = length;
	bit = 0;
	while (l)
	{
		l /= 2;
		bit++;
	}
	return (bit);
}

void	radix_sort(t_ll **a, t_ll **b, int bits)
{
	int	length;
	int	i;

	i = 0;
	length = (*a)->length;
	while (i < bits)
	{
		length = (*a)->length;
		while (length)
		{
			if ((*a)->head->pos & (1 << i))
				rotate(a);
			else
				push(a, b, 'b');
			length--;
		}
		while ((*b)->head)
			push(b, a, 'a');
		i++;
	}
}

int	main(int ac, char **av)
{
	t_ll	*a;
	t_ll	*b;

	init_ll(&a, &b);
	if (ac >= 2 && parse_input(&a, ac, av) && \
		check_dup(a) && check_sorted(a))
	{
		give_pos(a->head);
		if (a->length == 2)
			swap(&a, 'a');
		else if (a->length == 3)
			three_numbers(&a);
		else if (a->length <= 5)
			five_numbers(&a, &b);
		else
			radix_sort(&a, &b, bits_set(a->length));
	}
	free_ll(a, b);
	return (0);
}
