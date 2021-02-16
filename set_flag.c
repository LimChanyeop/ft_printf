/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_flag.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clim <clim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/13 20:24:34 by clim              #+#    #+#             */
/*   Updated: 2021/02/16 18:30:49 by clim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		init_flag(t_flag *flag)
{
	flag->minus = 0;
	flag->zero = 0;
	flag->dot = 0;
	flag->width = 0;
	flag->prec = 0;
	flag->len = 0;
	flag->sign_n = 0;
	flag->type = '\0';
}

static int		type_idx(char *format)
{
	int			i;

	i = 1;
	while (format[i])
	{
		if (is_specifier(format[i]))
			return (i);
		else
			i++;
	}
	return (-1);
}

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

int				set_option(va_list ap, t_flag *flag, char *format)
{
	int			i;
	int			t_idx;

	i = 1;
	init_flag(flag);
	t_idx = type_idx((char *)format);
	flag->type = format[t_idx];
	while ((format[i] == '0' || format[i] == '-'))
	{
		if (format[i++] == '0')
			flag->zero = 1;
		else
			flag->minus = 1;
	}
	set_width_prec(ap, flag, format, i);
	return (t_idx);
}
