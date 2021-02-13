/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_x.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clim <clim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/04 14:24:36 by clim              #+#    #+#             */
/*   Updated: 2021/02/13 20:06:24 by clim             ###   ########.fr       */
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

static char			*ft_itox(unsigned int n, int is_upper)
{
	char		*x;
	char		arr[9];
	int			idx;
	char		*hex;

	if (is_upper)
		hex = "0123456789ABCDEF";
	else
		hex = "0123456789abcdef";
	ft_bzero(arr, 9);
	if (n == 0)
		return (ft_strdup("0"));
	idx = 0;
	while (n > 0)
	{
		arr[idx++] = hex[n % 16];
		n = n / 16;
	}
	if (!(x = (char *)malloc(sizeof(char) * (ft_strlen((char *)arr) + 1))))
		return (0);
	x = allocate((char *)arr, x, idx - 1);
	return (x);
}

int					print_x(char *x, t_flag *flag)
{
	int				cnt;
	int				len;

	cnt = 0;
	len = ft_strlen(x);
	if (!flag->dot || flag->prec < 0)
	{
		if (flag->zero || flag->minus)
			cnt += flag->minus ? put_str(x, len) : handle_width(flag, len);
		else
			cnt += handle_width(flag, len);
		cnt += flag->minus ? handle_width(flag, len) : put_str(x, len);
	}
	else if (flag->dot)
	{
		(!flag->minus && flag->prec >= 0) ? cnt += handle_width(flag, len) : 0;
		cnt += handle_prec(flag, len);
		cnt += put_str(x, len);
		flag->minus ? (cnt += handle_width(flag, len)) : 0;
	}
	return (cnt);
}

int					handle_x(va_list ap, t_flag *flag)
{
	unsigned int	value_x;
	int				cnt;
	char			*x;

	cnt = 0;
	value_x = va_arg(ap, unsigned int);
	if ((flag->zero && flag->minus) || (flag->dot && flag->prec >= 0))
		flag->zero = 0;
	if (value_x == 0 && (flag->dot == 1 && flag->prec == 0))
		x = ft_strdup("");
	else
		x = ft_itox(value_x, (flag->type == 'X'));
	cnt += print_x(x, flag);
	free(x);
	return (cnt);
}
