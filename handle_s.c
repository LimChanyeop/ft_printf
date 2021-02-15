/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_s.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clim <clim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/04 11:01:33 by clim              #+#    #+#             */
/*   Updated: 2021/02/15 12:17:16 by clim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int					put_str(char *s, int len)
{
	int				cnt;

	cnt = 0;
	while (len--)
		cnt += write(1, s++, 1);
	return (cnt);
}

static void			print_s(char *s, t_flag *flag, int *cnt)
{

	if (!flag->minus)
	{
		*cnt += handle_width(flag, flag->len);
		*cnt += put_str(s, flag->len);
	}
	else
	{
		*cnt += put_str(s, flag->len);
		*cnt += handle_width(flag, flag->len);
	}
}

int					handle_s(va_list ap, t_flag *flag)
{
	char			*value_s;
	int				cnt;

	cnt = 0;
	flag->zero = 0;
	value_s = va_arg(ap, char *);
	if (!value_s)
		value_s = ft_strdup("(null)");
	flag->len = ft_strlen(value_s);
	if (flag->dot && flag->prec >= 0)
		ft_strlen(value_s) > (size_t)flag->prec ? flag->len = flag->prec : 0;
	print_s(value_s, flag, &cnt);
	return (cnt);
}
