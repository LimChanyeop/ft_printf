/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clim <clim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/04 13:08:51 by clim              #+#    #+#             */
/*   Updated: 2021/01/28 14:41:19 by clim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void			ft_putnbr(int n)
{
	char		num;

	if (n == -2147483648)
	{
		write(1, "-2147483648", 11);
		return ;
	}
	if (n == 0)
	{
		write(1, "0", 1);
		return ;
	}
	if (n < 0 && n != -2147483648)
	{
		write(1, "-", 1);
		n *= -1;
	}
	if (n >= 10 && n != -2147483648)
		ft_putnbr(n / 10);
	num = (n % 10) + '0';
	write(1, &num, 1);
}
