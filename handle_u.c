/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_u.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clim <clim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/13 20:06:58 by clim              #+#    #+#             */
/*   Updated: 2021/02/13 20:14:41 by clim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int					print_u(unsigned int i, t_flag *flag)
{
	int				cnt;
	int				len;

	cnt = 0;
	len = get_int_len(i, flag);
	if (!flag->dot || flag->prec < 0)
	{
		if (flag->zero || flag->minus)
			cnt += flag->minus ? ft_putnbr(i) : handle_width(flag, len);
		else
			cnt += handle_width(flag, len);
		cnt += flag->minus ? handle_width(flag, len) : ft_putnbr(i);
	}
	else if (flag->dot)
	{
		if (!flag->minus && flag->prec >= 0)
			cnt += handle_width(flag, len);
		cnt += handle_prec(flag, len);
		cnt += i ? ft_putnbr(i) : 0;
		cnt += flag->minus ? handle_width(flag, len) : 0;
	}
	return (cnt);
}

int					handle_u(va_list ap, t_flag *flag)
{
	unsigned int	value_u;
	int				cnt;

	cnt = 0;
	if ((flag->zero && flag->minus) || (flag->dot && flag->prec >= 0))
		flag->zero = 0;
	value_u = va_arg(ap, unsigned int);
	cnt += print_u(value_u, flag);
	return (cnt);
}
