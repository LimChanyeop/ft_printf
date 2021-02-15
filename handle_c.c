/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_c.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clim <clim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/03 15:21:38 by clim              #+#    #+#             */
/*   Updated: 2021/02/15 12:25:15 by clim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void			print_c(char c, t_flag *flag, int *cnt)
{
	if ((flag->zero && flag->minus) || (flag->dot && flag->prec >= 0))
		flag->zero = 0;
	if (flag->minus)
	{
		*cnt += write(1, &c, 1);
		*cnt += handle_width(flag, 1);
	}
	else
	{
		*cnt += handle_width(flag, 1);
		*cnt += write(1, &c, 1);
	}
}

int					handle_c(va_list ap, t_flag *flag)
{
	unsigned char	value_c;
	int				cnt;

	cnt = 0;
	value_c = va_arg(ap, int);
	print_c(value_c, flag, &cnt);
	return (cnt);
}
