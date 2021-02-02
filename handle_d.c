/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_d.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clim <clim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/29 12:02:18 by clim              #+#    #+#             */
/*   Updated: 2021/02/02 11:05:37 by clim             ###   ########.fr       */
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

	cnt = 0;
	if (flag->len < flag->width && !flag->minus && !flag->zero) // 우측정렬공백
		handle_width(' ', flag->width - flag->len); //print ' ' size of (width - len)	
	if (i < 0 && i != -2147483648)
	{
		ft_putchar_fd('-', 1);
		cnt++;
	}
	if (flag->zero || flag->dot)
		handle_width('0', flag->dot ? flag->prec - get_int_len(i) : flag->width - get_int_len(i));// print '0' sizeof prec - get_int_len(i) OR width - get_int_len (prec option not applied ) 
	ft_putnbr_fd(i, 1);// print num
	if (flag->minus)
		handle_width(' ', flag->dot ? flag->prec - get_int_len(i) : flag->width - get_int_len(i));// print ' ' if flag->minus
}

void		handle_d(va_list ap, t_flag *flag)
{
	int		value_d;

	if ((flag->zero && flag->minus) || flag->dot)
		flag->zero = 0;
	value_d = va_arg(ap, int);
	flag->len = get_int_len(value_d) > flag->prec ? get_int_len(value_d) : flag->prec;
	print_d(value_d, flag);
}