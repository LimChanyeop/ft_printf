/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_d.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clim <clim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/29 12:02:18 by clim              #+#    #+#             */
/*   Updated: 2021/01/29 15:14:03 by clim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			get_int_len(int i)
{
	int len = 0;

	if (i == 0 || i == -2147483648)
		return (i == 0 ? 1 : 11);//들어온 값이 0이면 길이가 0
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

void		print_d(int i, int width, int len, char blank)
{
	while (width > len)
	{
		ft_putchar(&blank);
		width--;
	}
	ft_putnbr(i);
}

void		handle_d(va_list ap, t_flag *flag)
{
	int		value_d;
	char	blank;

	blank = (flag->zero && !flag->minus) ? '0' : ' ';
	if (flag->aster_width)
		flag->width = va_arg(ap, int);
	if (flag->aster_prec)
		flag->prec = va_arg(ap, int);
	value_d = va_arg(ap, int);
	flag->len = get_int_len(value_d);
	print_d(value_d,flag->width,flag->len,blank);
}