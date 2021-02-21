/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clim <clim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/27 11:42:06 by clim              #+#    #+#             */
/*   Updated: 2021/02/17 10:54:28 by clim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int		sanity_check(const char *format)
{
	while (*format)
	{
		if (*format++ == '%')
		{
			while (*format == '0' || *format == '-')
				format++;
			if (*format == '*')
				format++;
			else
				while (ft_isdigit(*format))
					format++;
			if (*format == '.')
				format++;
			if (*format == '*')
				format++;
			else
				while (ft_isdigit(*format))
					format++;
			if (!is_specifier(*format))
				return (-1);
		}
	}
	return (0);
}

static int		handle(va_list ap, t_flag *flag, char type)
{
	int			cnt;

	if (type == 'd' || type == 'i')
		cnt = handle_d_i(ap, flag);
	if (type == 'c')
		cnt = handle_c(ap, flag);
	if (type == 'u')
		cnt = handle_u(ap, flag);
	if (type == 's')
		cnt = handle_s(ap, flag);
	if (type == 'x' || type == 'X')
		cnt = handle_x(ap, flag);
	if (type == 'p')
		cnt = handle_p(ap, flag);
	if (type == '%')
		cnt = handle_pct(flag);
	return (cnt);
}

int				ft_printf(const char *format, ...)
{
	va_list		ap;
	t_flag		flag;
	int			ret_cnt;
	int			ret_val;

	ret_cnt = 0;
	va_start(ap, format);
	if (sanity_check(format) == -1)
		return (-1);
	while (*format)
	{
		if (*format == '%')
		{
			format += set_option(ap, &flag, (char *)format);
			if ((ret_val = handle(ap, &flag, flag.type)) == -1)
				return (-1);
			ret_cnt += ret_val;
		}
		else
			ret_cnt += write(1, (char *)format, 1);
		format++;
	}
	return (ret_cnt);
}
