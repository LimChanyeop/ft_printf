/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clim <clim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/04 13:08:51 by clim              #+#    #+#             */
/*   Updated: 2021/02/08 11:02:16 by clim             ###   ########.fr       */
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

int			get_int_len(long long i)
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
