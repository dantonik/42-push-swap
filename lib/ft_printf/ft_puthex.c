/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dantonik <dantonik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 16:40:49 by dantonik          #+#    #+#             */
/*   Updated: 2022/05/18 18:30:59 by dantonik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/ft_printf.h"

static int	ft_lower_or_upper(int c)
{
	if (c == 'x')
		return (87);
	return (55);
}

int	ft_puthex(long n, int c)
{
	int				i;
	int				j;
	char			s[16];

	if (n == 0)
		return (ft_putchar('0'));
	j = ft_lower_or_upper(c);
	i = 15;
	while (n)
	{
		if ((n % 16) >= 10)
			s[i] = (n % 16) + j;
		else
			s[i] = (n % 16) + '0';
		n /= 16;
		i--;
	}
	j = 0;
	while (++i < 16)
		j += ft_putchar(s[i]);
	return (j);
}
