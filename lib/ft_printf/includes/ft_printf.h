/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dantonik <dantonik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 14:38:47 by dantonik          #+#    #+#             */
/*   Updated: 2022/05/18 15:20:16 by dantonik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdint.h>
# include <limits.h>

int		ft_printf(const char *format, ...);
int		ft_putnbr(long num, int len);
int		ft_putchar(char c);
int		ft_putstr(char *str);
int		ft_puthex(long n, int c);
int		ft_putptr(unsigned long long p);
int		ft_putu(int num);

#endif