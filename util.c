/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clim <clim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/04 13:08:51 by clim              #+#    #+#             */
/*   Updated: 2021/02/03 16:01:16 by clim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int				ft_putnbr(int n)
{
	int			cnt;
	int			n_arr[11];
	int			i;

	cnt = 0;
	if (n == -2147483648)
		cnt += write(1, "-2147483648", 11);
	else if (n == 0)
		cnt += write(1, "0", 1);
	else if (n < 0 && n != -2147483648)
	{
		cnt += write(1, "-", 1);
		n *= -1;
	}
	i = 0;
	while (n > 0 && n != -2147483648)
	{
		n_arr[i++] = (n % 10) + '0';
		n /= 10;
	}
	while (--i >= 0)
		cnt += write(1, &n_arr[i], 1);
	return (cnt);
}

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
