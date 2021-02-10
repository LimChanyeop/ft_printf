/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_pct.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clim <clim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/04 14:31:12 by clim              #+#    #+#             */
/*   Updated: 2021/02/10 14:44:02 by clim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int					print_pct()
{
	write(1, "%%", 1);
	return (1);
}

int						handle_pct(t_flag *flag)
{
	int cnt;

	cnt = 0;
	if ((flag->zero && flag->minus) || (flag->dot && flag->prec >= 0))
		flag->zero = 0;
	if (flag->minus)
	{
		cnt += print_pct();
		cnt += handle_width(flag, 1);
	}
	else
	{
		cnt += handle_width(flag, 1);
		cnt += print_pct();
	}
	return (cnt);
}