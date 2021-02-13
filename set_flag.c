/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_flag.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clim <clim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/13 20:24:34 by clim              #+#    #+#             */
/*   Updated: 2021/02/13 20:30:20 by clim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void			set_width_prec(va_list ap, t_flag *flag, char *format, int i)
{
	if (format[i] == '*')
	{
		flag->width = va_arg(ap, int);
		flag->width < 0 ? flag->minus = 1 : 0;
		flag->width < 0 ? flag->width *= -1 : 0;
		i++;
	}
	else if (ft_isdigit(format[i]))
	{
		flag->width = ft_atoi(&format[i]);
		if (flag->width < 0)
		{
			flag->width < 0 ? flag->minus = 1 : 0;
			flag->width < 0 ? flag->width *= -1 : 0;
			i++;
		}
		while (ft_isdigit(format[i]))
			i++;
	}
	if (format[i++] == '.')
	{
		flag->dot = 1;
		flag->prec = format[i] == '*' ? va_arg(ap, int) : ft_atoi(&format[i]);
	}
}

void			set_option(va_list ap, t_flag *flag, char *format, int idx)
{
	int			i;

	i = 1;
	flag->type = format[idx];
	while ((format[i] == '0' || format[i] == '-'))
	{
		if (format[i++] == '0')
			flag->zero = 1;
		else
			flag->minus = 1;
	}
	set_width_prec(ap, flag, format, i);
}
