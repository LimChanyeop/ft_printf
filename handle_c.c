/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_c.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clim <clim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/03 15:21:38 by clim              #+#    #+#             */
/*   Updated: 2021/02/03 15:58:17 by clim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int					handle_c(va_list ap, t_flag *flag)
{
	unsigned char	value_c;
	int				cnt;

	cnt = 0;
	value_c = va_arg(ap, int);
	cnt += print_c(value_c, flag);
	return (cnt);
}

int					print_c(char c, t_flag *flag)
{
	int				cnt;

	cnt = 0;
	if (flag->minus)
	{
		cnt += write(1, &c, 1);
		cnt += handle_width(flag, 1);
	}
	else
	{
		cnt += handle_width(flag, 1);
		cnt += write(1, &c, 1);
	}
	return (cnt);
}