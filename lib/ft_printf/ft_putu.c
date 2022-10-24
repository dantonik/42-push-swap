/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putu.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dantonik <dantonik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 13:14:39 by dantonik          #+#    #+#             */
/*   Updated: 2022/05/18 15:01:49 by dantonik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/ft_printf.h"

int	ft_putu(int num)
{
	if (num < 0)
		return (ft_putnbr(UINT_MAX + 1 + num, 1));
	else
		return (ft_putnbr(num, 1));
}
