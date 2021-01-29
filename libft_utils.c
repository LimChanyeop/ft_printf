/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clim <clim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/04 13:08:51 by clim              #+#    #+#             */
/*   Updated: 2021/01/29 15:24:15 by clim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void			ft_putnbr(int n)
{
	char		num;

	if (n == -2147483648)
	{
		write(1, "-2147483648", 11);
		//ret_cnt += 11;
		return ;
	}
	if (n == 0)
	{
		ft_putchar("0");
		return ;
	}
	if (n < 0 && n != -2147483648)
	{
		ft_putchar("-");
		n *= -1;
	}
	if (n >= 10 && n != -2147483648)
		ft_putnbr(n / 10);
	num = (n % 10) + '0';
	ft_putchar(&num);
}

int			ft_isdigit(int c)
{
	return ((c >= '0') && (c <= '9'));
}

void			ft_putchar(char *c)
{
	write(1, c, 1);
	//ret_cnt++;
}

size_t		ft_strlen(const char *str)
{
	int		count;

	count = 0;
	while (*str != '\0')
	{
		str++;
		count++;
	}
	return (count);
}