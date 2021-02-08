/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_u.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clim <clim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/03 16:03:01 by clim              #+#    #+#             */
/*   Updated: 2021/02/08 14:42:20 by clim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int					print_u(unsigned int i, t_flag *flag)
{
	int				cnt;

	cnt = 0;
	if (!flag->dot)
	{
		if (flag->zero || flag->minus)
			flag->minus ? cnt += ft_putnbr(i) : (cnt += handle_width(flag, get_int_len(i)));
		else
			cnt += handle_width(flag, get_int_len(i));
		flag->minus ? (cnt += handle_width(flag, get_int_len(i))) : (cnt += ft_putnbr(i));
	}
	else if (flag->dot)
	{
		(!flag->minus && flag->prec >= 0) ? (cnt += handle_width(flag, get_int_len(i))) : 0;
		cnt += handle_prec(flag, get_int_len(i));
		i ? cnt += ft_putnbr(i) : 0;
		flag->minus ? (cnt += handle_width(flag, get_int_len(i))) : 0;
	}
	return (cnt);
}

int					handle_u(va_list ap, t_flag *flag)
{
	unsigned int	value_u;
	int				cnt;

	cnt = 0;
	if ((flag->zero && flag->minus) || flag->dot)
		flag->zero = 0;
	value_u = va_arg(ap, unsigned int);
	cnt += print_u(value_u, flag);
	return (cnt);
}