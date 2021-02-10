/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_p.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clim <clim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/04 16:27:35 by clim              #+#    #+#             */
/*   Updated: 2021/02/10 14:29:59 by clim             ###   ########.fr       */
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

int					print_p(char *p, t_flag *flag)
{
	int				cnt;
	int				len;

	cnt = 0;
	len = ft_strlen(p);
	if (!flag->dot)
	{
		if (flag->zero || flag->minus)
			flag->minus ? (cnt += put_str(p, len)) : (cnt += handle_width(flag, len));
		else
			cnt += handle_width(flag, len);
		flag->minus ? (cnt += handle_width(flag, len)) : (cnt += put_str(p, len));
	}
	else if (flag->dot)
	{
		(!flag->minus && flag->prec >= 0) ? (cnt += handle_width(flag, len)) : 0;
		cnt += handle_prec(flag, len);
		cnt += put_str(p, len);
		flag->minus ? (cnt += handle_width(flag, len)) : 0;
	}
	return (cnt);
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
	cnt += print_p(p, flag);	
	free(p);
	return (cnt);
}
