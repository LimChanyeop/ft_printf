/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_d_i.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clim <clim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/10 11:22:45 by clim              #+#    #+#             */
/*   Updated: 2021/02/13 15:17:38 by clim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			print_d(long long i, t_flag *flag)
{
	int		cnt;

	cnt = 0;
	if (!flag->dot || flag->prec < 0)
	{
		if (flag->zero || flag->minus)
		{
			cnt += handle_sign(flag);
			cnt += flag->minus ? ft_putnbr(i) : handle_width(flag, get_int_len(i, flag));
		}
		else
		{
			cnt += handle_width(flag, get_int_len(i, flag));
			cnt += handle_sign(flag);
		}
		cnt += flag->minus ? handle_width(flag, get_int_len(i, flag)) : ft_putnbr(i);
	}
	else if (flag->dot)
	{
		if (!flag->minus && flag->prec >= 0)
			cnt += handle_width(flag, get_int_len(i, flag));
		cnt += handle_sign(flag);
		cnt += handle_prec(flag, get_int_len(i, flag));
		i ? cnt += ft_putnbr(i) : 0;
		flag->minus ? (cnt += handle_width(flag, get_int_len(i, flag))) : 0;
	}
	return (cnt);
}

int			handle_d(va_list ap, t_flag *flag)
{
	long long	value_d;
	int		cnt;

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
	cnt += print_d(value_d, flag);
	return (cnt);
}
