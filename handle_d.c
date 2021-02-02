/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_d.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clim <clim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/29 12:02:18 by clim              #+#    #+#             */
/*   Updated: 2021/02/02 20:17:41 by clim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			get_int_len(int i)
{
	int len = 0;

	if (i == 0 || i == -2147483648)
		return (i == 0 ? 1 : 11);
	if (i < 0)
	{
		i *= -1;	
		len++;
	}
	while(i > 0)
	{
		i /= 10;
		len++;
	}
	return (len);
}

void		print_d(int i, t_flag *flag)
{
	int		cnt;

	
}

void		handle_d(va_list ap, t_flag *flag)
{
	int		value_d;

	if ((flag->zero && flag->minus) || flag->dot)
		flag->zero = 0;
	value_d = va_arg(ap, int);
	print_d(value_d, flag);
}
