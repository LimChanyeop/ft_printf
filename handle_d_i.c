/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_d_i.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clim <clim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/29 12:02:18 by clim              #+#    #+#             */
/*   Updated: 2021/02/08 11:17:36 by clim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>
int			print_d(int i, t_flag *flag)
{
	int		cnt;

	cnt = 0;
	if (!flag->dot)
	{
		if (flag->zero || flag->minus)
		{
			printf("\ncnt = %d",cnt);
			cnt += handle_sign(flag);
			printf("\ncnt = %d",cnt);
			flag->minus ? cnt += ft_putnbr(i) : (cnt += handle_width(flag, get_int_len(i)));
			printf("\ncnt = %d",cnt);
		}
		else
		{
			cnt += handle_width(flag, get_int_len(i));
			printf("\ncnt = %d",cnt);
			cnt += handle_sign(flag);
			printf("\ncnt = %d",cnt);
		}
		flag->minus ? (cnt += handle_width(flag, get_int_len(i))) : (cnt += ft_putnbr(i));
		printf("\ncnt = %d",cnt);
	}
	else if (flag->dot)
	{
		printf("\ncnt = %d",cnt);
		(!flag->minus && flag->prec >= 0) ? (cnt += handle_width(flag, get_int_len(i))) : 0;
		printf("\ncnt = %d",cnt);
		cnt += handle_sign(flag);
		printf("\ncnt = %d",cnt);
		cnt += handle_prec(flag, get_int_len(i));
		printf("\ncnt = %d",cnt);
		i ? cnt += ft_putnbr(i) : 0;
		printf("\ncnt = %d",cnt);
		flag->minus ? (cnt += handle_width(flag, get_int_len(i))) : 0;
	}
	printf("\ncnt = %d",cnt);
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
		flag->width--;
	}
	cnt += print_d(value_d, flag);
	return (cnt);
}
