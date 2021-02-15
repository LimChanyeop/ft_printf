/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_u.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clim <clim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/13 20:06:58 by clim              #+#    #+#             */
/*   Updated: 2021/02/15 14:16:19 by clim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void			print_u(unsigned int i, t_flag *flag, int *cnt)
{
	int				len;

	len = digit_len(i, flag);
	if (!flag->dot || flag->prec < 0)
	{
		if (flag->zero || flag->minus)
			*cnt += flag->minus ? ft_putnbr(i) : handle_width(flag, len);
		else
			*cnt += handle_width(flag, len);
		*cnt += flag->minus ? handle_width(flag, len) : ft_putnbr(i);
	}
	else if (flag->dot)
	{
		if (!flag->minus && flag->prec >= 0)
			*cnt += handle_width(flag, len);
		*cnt += handle_prec(flag, len);
		*cnt += i ? ft_putnbr(i) : 0;
		*cnt += flag->minus ? handle_width(flag, len) : 0;
	}
}

int					handle_u(va_list ap, t_flag *flag)
{
	unsigned int	value_u;
	int				cnt;

	cnt = 0;
	if ((flag->zero && flag->minus) || (flag->dot && flag->prec >= 0))
		flag->zero = 0;
	value_u = va_arg(ap, unsigned int);
	print_u(value_u, flag, &cnt);
	return (cnt);
}
