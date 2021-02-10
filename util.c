/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangjwoohpa <sangjwoohpa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/04 13:08:51 by clim              #+#    #+#             */
/*   Updated: 2021/02/10 11:03:11 by sangjwoohpa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int				ft_putnbr(long long n)
{
	int			cnt;
	int			n_arr[11];
	int			i;

	cnt = 0;
	if (n == 0)
		cnt += write(1, "0", 1);
	i = 0;
	while (n > 0)
	{
		n_arr[i++] = (n % 10) + '0';
		n /= 10;
	}
	while (--i >= 0)
		cnt += write(1, &n_arr[i], 1);
	return (cnt);
}

int			get_int_len(long long i, t_flag *flag)
{
	int len = 0;

	if (i == 0 && (!flag->dot || flag->prec < 0))
		return (1);
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
