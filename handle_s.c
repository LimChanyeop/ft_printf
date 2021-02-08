/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_s.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clim <clim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/04 11:01:33 by clim              #+#    #+#             */
/*   Updated: 2021/02/08 11:35:54 by clim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int					put_str(char *s, int len)
{
	int				cnt;

	cnt = 0;
	while(len--)
	{
		cnt += write(1, s++, 1); 
	}
	return (cnt);
}

int					print_s(char *s, t_flag *flag)
{
	int				cnt;

	cnt = 0;
	if (!flag->minus)
	{
		cnt += handle_width(flag, flag->len);
		cnt += put_str(s, flag->len);
	}
	else
	{
		cnt += put_str(s, flag->len);
		cnt += handle_width(flag, flag->len);
	}
	return (cnt);
}

int					handle_s(va_list ap, t_flag *flag)
{
	char			*value_s;
	int				cnt;

	cnt = 0;
	flag->zero = 0;
	value_s = va_arg(ap, char *);
	if (!value_s)
		value_s = "(null)";
	flag->len = ft_strlen(value_s);
	if (flag->dot && flag->prec >= 0)
		ft_strlen(value_s) > (size_t)flag->prec ? flag->len = flag->prec : 0;
	cnt += print_s(value_s, flag);
	return (cnt);
}