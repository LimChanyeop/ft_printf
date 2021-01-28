/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clim <clim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/27 11:42:06 by clim              #+#    #+#             */
/*   Updated: 2021/01/28 15:36:59 by clim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

void		init_flag(t_flag *flag)
{
	flag->minus = 0;
	flag->zero = 0;
	flag->aster_width = 0;
	flag->aster_prec = 0;
	flag->dot = 0;
	flag->width = 0;
	flag->len = 0;
	flag->type = '\0';
}

int			type_idx(char *format)
{
	int		i;

	i = 0;
	while (format[i])
	{
		if (format[i] == 'c' || format[i] == 's' || format[i] == 'p' \
				|| format[i] == 'd' || format[i] == 'i' || format[i] == 'u' \
				|| format[i] == 'x' || format[i] == 'X')
			return (i);
		else
			i++;
	}
	if (!format[i])
		return(-1);
}

char		set_flag(t_flag *flag, char *format, int idx)
{
	int		i;

	i = 0;
	return (format[idx]);
}

int			ft_printf(const char *format, ...)
{
	int		ret_cnt;
	int		idx;
	t_flag *flag;

	ret_cnt = 0;
	ap = va_start(ap, format);
	while (*format)
	{
		if (*format == '%')
		{
			init_flag(flag);
			handle(set_flag(flag, format, type_idx(format)));
		}
		else
			ft_putchar(format);
	}
	return (0);
}

int			main()
{
	ft_printf("%d and %d and %d%%", 10, 100, 99);
}
