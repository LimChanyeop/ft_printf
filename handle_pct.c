/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_pct.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clim <clim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/04 14:31:12 by clim              #+#    #+#             */
/*   Updated: 2021/02/15 12:23:01 by clim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void			print_pct(int *cnt)
{
	write(1, "%%", 1);
	*cnt += 1;
}

int					handle_pct(t_flag *flag)
{
	int				cnt;

	cnt = 0;
	if ((flag->zero && flag->minus))
		flag->zero = 0;
	if (flag->minus)
	{
		print_pct(&cnt);
		cnt += handle_width(flag, 1);
	}
	else
	{
		cnt += handle_width(flag, 1);
		print_pct(&cnt);
	}
	return (cnt);
}
