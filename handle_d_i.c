/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_d_i.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clim <clim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/10 11:22:45 by clim              #+#    #+#             */
/*   Updated: 2021/02/15 12:19:38 by clim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		print_d(long long i, t_flag *flag, int *cnt)
{
	int			len;

	len = get_int_len(i, flag);
	if (!flag->dot || flag->prec < 0)
	{
		if (flag->zero || flag->minus)
		{
			*cnt += handle_sign(flag);
			*cnt += flag->minus ? ft_putnbr(i) : handle_width(flag, len);
		}
		else
		{
			*cnt += handle_width(flag, len);
			*cnt += handle_sign(flag);
		}
		*cnt += flag->minus ? handle_width(flag, len) : ft_putnbr(i);
	}
	else if (flag->dot)
	{
		*cnt += !flag->minus && flag->prec >= 0 ? handle_width(flag, len) : 0;
		*cnt += handle_sign(flag);
		*cnt += handle_prec(flag, len);
		i ? *cnt += ft_putnbr(i) : 0;
		*cnt += flag->minus ? handle_width(flag, len) : 0;
	}
}

int				handle_d(va_list ap, t_flag *flag)
{
	long long	value_d;
	int			cnt;

	cnt = 0;
	if ((flag->zero && flag->minus) || (flag->dot && flag->prec >= 0))
		flag->zero = 0;
	value_d = va_arg(ap, int);
	if (value_d < 0)
	{
		flag->sign_n = 1;
		value_d *= -1;
		flag->width--;
	}
	print_d(value_d, flag, &cnt);
	return (cnt);
}
