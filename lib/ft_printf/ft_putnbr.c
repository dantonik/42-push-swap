/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dantonik <dantonik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 14:56:06 by dantonik          #+#    #+#             */
/*   Updated: 2022/05/18 15:02:59 by dantonik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/ft_printf.h"

int	ft_putnbr(long num, int len)
{
	if (num < 0)
	{
		ft_putchar('-');
		num = -num;
		len++;
	}
	if (num > 9)
		len = ft_putnbr(num / 10, len + 1);
	ft_putchar((num % 10) + '0');
	return (len);
}
