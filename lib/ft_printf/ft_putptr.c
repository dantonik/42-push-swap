/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dantonik <dantonik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 16:04:20 by dantonik          #+#    #+#             */
/*   Updated: 2022/05/18 14:56:34 by dantonik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/ft_printf.h"

int	ft_putptr(unsigned long long p)
{
	int		i;
	int		j;
	char	s[16];

	ft_putstr("0x");
	if (p == 0)
		return (ft_putchar('0') + 2);
	i = 15;
	while (p)
	{
		if ((p % 16) >= 10)
			s[i] = (p % 16) + 87;
		else
			s[i] = (p % 16) + 48;
		p /= 16;
		i--;
	}
	j = 0;
	while (++i < 16)
		j += ft_putchar(s[i]);
	return (j + 2);
}
