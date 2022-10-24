/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dantonik <dantonik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/24 21:48:29 by dantonik          #+#    #+#             */
/*   Updated: 2022/07/05 17:17:18 by dantonik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/ft_printf.h"

static int	ft_format(va_list arg, const char format)
{
	if (format == 'c')
		return (ft_putchar(va_arg(arg, int)));
	else if (format == 's')
		return (ft_putstr(va_arg(arg, char *)));
	else if (format == 'd' || format == 'i')
		return (ft_putnbr(va_arg(arg, int), 1));
	else if (format == 'p')
		return (ft_putptr(va_arg(arg, unsigned long long)));
	else if (format == 'u')
		return (ft_putu(va_arg(arg, unsigned int)));
	else if (format == 'x' || format == 'X')
		return (ft_puthex(va_arg(arg, unsigned int), format));
	else if (format == '%')
		return (ft_putchar('%'));
	else
		return (0);
}

int	ft_printf(const char *format, ...)
{
	va_list		arg;
	int			i;
	int			done;

	done = 0;
	i = 0;
	va_start(arg, format);
	if (format == NULL)
		return (0);
	while (format[i] != '\0')
	{
		if (format[i] != '%')
			done += ft_putchar(format[i]);
		else
		{
			done += ft_format(arg, format[i +1]);
			i++;
		}
		i++;
	}
	va_end(arg);
	return (done);
}
