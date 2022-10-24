/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dantonik <dantonik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 20:01:19 by dantonik          #+#    #+#             */
/*   Updated: 2022/05/18 14:56:54 by dantonik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/ft_printf.h"

int	ft_putstr(char *str)
{
	int	x;

	x = 0;
	if (str == NULL)
	{
		ft_putstr("(null)");
		return (6);
	}
	while (str[x] != '\0')
	{
		ft_putchar(str[x]);
		x++;
	}
	return (x);
}
