/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clim <clim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/27 11:42:06 by clim              #+#    #+#             */
/*   Updated: 2021/02/13 20:28:49 by clim             ###   ########.fr       */
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
		if (format[i] == 'c' || format[i] == 's' || format[i] == 'p' \
				|| format[i] == 'd' || format[i] == 'i' || format[i] == 'u' \
				|| format[i] == 'x' || format[i] == 'X' || format[i] == '%')
			return (i);
		else
			i++;
	}
	return (-1);
}

static int		handle(va_list ap, t_flag *flag, char type)
{
	int			cnt;

	cnt = 0;
	if (type == 'd' || type == 'i')
		cnt += handle_d(ap, flag);
	if (type == 'c')
		cnt += handle_c(ap, flag);
	if (type == 'u')
		cnt += handle_u(ap, flag);
	if (type == 's')
		cnt += handle_s(ap, flag);
	if (type == 'x' || type == 'X')
		cnt += handle_x(ap, flag);
	if (type == 'p')
		cnt += handle_p(ap, flag);
	if (type == '%')
		cnt += handle_pct(flag);
	return (cnt);
}

int				ft_printf(const char *format, ...)
{
	va_list		ap;
	int			ret_cnt;
	char		t_idx;
	t_flag		flag;

	ret_cnt = 0;
	va_start(ap, format);
	while (*format)
	{
		if (*format == '%')
		{
			init_flag(&flag);
			t_idx = type_idx((char *)format);
			set_option(ap, &flag, (char *)format, t_idx);
			ret_cnt += handle(ap, &flag, flag.type);
			format += t_idx;
		}
		else
			ret_cnt += write(1, (char *)format, 1);
		format++;
	}
	return (ret_cnt);
}
