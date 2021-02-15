/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_p.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clim <clim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/04 16:27:35 by clim              #+#    #+#             */
/*   Updated: 2021/02/15 12:14:58 by clim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char			*allocate(char *arr, char *a, int idx)
{
	int			i;

	i = 0;
	while (idx >= 0)
		a[i++] = arr[idx--];
	a[i] = 0;
	return (a);
}

static char			*ft_itop(long long n)
{
	char		*p;
	char		arr[17];
	int			idx;
	char		*hex;

	hex = "0123456789abcdef";
	ft_bzero(arr, 17);
	if (n == 0)
		return (ft_strdup("0x0"));
	idx = 0;
	while (n > 0)
	{
		arr[idx++] = hex[n % 16];
		n = n / 16;
	}
	arr[idx++] = 'x';
	arr[idx] = '0';
	if (!(p = (char *)malloc(sizeof(char) * (ft_strlen((char *)arr) + 1))))
		return (0);
	p = allocate((char *)arr, p, idx);
	return (p);
}

static void			print_p(char *p, t_flag *flag, int *cnt)
{
	int				len;

	len = ft_strlen(p);
	if (!flag->dot)
	{
		if (flag->zero || flag->minus)
			*cnt += flag->minus ? put_str(p, len) : handle_width(flag, len);
		else
			*cnt += handle_width(flag, len);
		*cnt += flag->minus ? handle_width(flag, len) : put_str(p, len);
	}
	else if (flag->dot)
	{
		if (!flag->minus && flag->prec >= 0)
			*cnt += handle_width(flag, len);
		*cnt += handle_prec(flag, len);
		*cnt += put_str(p, len);
		flag->minus ? (*cnt += handle_width(flag, len)) : 0;
	}
}

int					handle_p(va_list ap, t_flag *flag)
{
	long long		value_p;
	int				cnt;
	char			*p;

	cnt = 0;
	value_p = va_arg(ap, long long);
	if (!value_p && flag->dot && !flag->prec)
		p = ft_strdup("0x");
	else
		p = ft_itop(value_p);
	print_p(p, flag, &cnt);
	free(p);
	return (cnt);
}
