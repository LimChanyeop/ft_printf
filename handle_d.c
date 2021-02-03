/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_d.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clim <clim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/29 12:02:18 by clim              #+#    #+#             */
/*   Updated: 2021/02/03 12:17:12 by clim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			print_d(int i, t_flag *flag)
{
	int		cnt;

	cnt = 0;
	if (!flag->dot)
	{
		if (flag->zero || flag->minus)
		{
			cnt += handle_sign(flag);
			flag->minus ? ft_putnbr(i) : (cnt += handle_width(flag, get_int_len(i)));
		}
		else
		{
			handle_width(flag, get_int_len(i));
			handle_sign(flag);
		}
		flag->minus ? (cnt += handle_width(flag, get_int_len(i))) : ft_putnbr(i);
	}
	else if (flag->dot)
	{
		(!flag->minus && flag->prec >= 0) ? (cnt += handle_width(flag, get_int_len(i))) : 0;
		handle_sign(flag);
		handle_prec(flag, get_int_len(i));
		i ? ft_putnbr(i) : 0;
		flag->minus ? (cnt += handle_width(flag, get_int_len(i))) : 0;
	}
	return (cnt);
}

int			handle_d(va_list ap, t_flag *flag)
{
	int		value_d;
	int		cnt;

	cnt = 0;
	if ((flag->zero && flag->minus) || flag->dot)
		flag->zero = 0;
	value_d = va_arg(ap, int);
	if (value_d < 0 && value_d  != -2147483638)
	{
		flag->sign_n = 1;
		value_d *= -1;
	}
	cnt += print_d(value_d, flag);
	return (cnt);
}
