/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fuer_norm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dantonik <dantonik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 23:37:26 by dantonik          #+#    #+#             */
/*   Updated: 2022/10/24 23:38:19 by dantonik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	give_pos(t_node *a)
{
	t_node			*start;
	t_node			*temp;

	start = a;
	temp = a;
	while (temp)
	{
		a = start;
		while (a)
		{
			if (temp->value > a->value)
				temp->pos++;
			a = a->next;
		}
		temp = temp->next;
	}
}
