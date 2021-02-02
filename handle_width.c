/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_width.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clim <clim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/29 19:12:36 by clim              #+#    #+#             */
/*   Updated: 2021/02/02 20:05:58 by clim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int				handle_prec(t_flag *flag, int len)
{
	int			cnt;
	int			i;

	cnt = 0;
	i = flag->prec;
	if (flag->dot)
	{
		while (i-- > len)
		{
			ft_putchar_fd('0', 1);
			cnt++;
		}
	}
	return (cnt);
}

int				handle_width(t_flag *flag, int len)
{
	int			cnt;
	int			l1;
	int			i;

	cnt = 0;
	l1 = len > flag->prec ? len : flag->prec;
	i = flag->width;
	while (i-- > l1)
	{
		flag->zero ? ft_putchar_fd('0', 1) : ft_putchar_fd(' ', 1);
		cnt++;
	}
	return (cnt);
}

int				handle_sign(t_flag *flag)
{
	if (flag->sign_n = 1)
	{
		ft_putchar_fd('-', 1); 
		return (1);
	}
	return (0);
}
