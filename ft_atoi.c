/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clim <clim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/22 13:43:31 by clim              #+#    #+#             */
/*   Updated: 2021/01/29 11:09:20 by clim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t		i;

	i = 0;
	if (n == 0)
		return (0);
	while ((unsigned char)s1[i] == (unsigned char)s2[i])
	{
		if (--n == 0 || (s1[i] == '\0' && s2[i] == '\0'))
			return (0);
		i++;
	}
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

static size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t		i;
	size_t		count;

	if (!dst || !src)
		return (0);
	i = 0;
	count = 0;
	while (src[i])
		i++;
	if (dstsize == 0)
		return (i);
	while ((count < i) && (count < dstsize - 1))
	{
		dst[count] = src[count];
		count++;
	}
	dst[count] = '\0';
	return (i);
}

static int		input_test(int sign, char *str)
{
	int			i;
	char		max[20];

	ft_strlcpy((char *)max, "9223372036854775808", 20);
	if (sign == 1)
		max[19] = '7';
	i = 0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		i++;
	}
	if ((i == 19 && ft_strncmp(max, str, 19) < 0) || i > 19)
	{
		if (sign == -1)
			return (0);
		if (sign == 1)
			return (-1);
	}
	return (1);
}

int				ft_atoi(const char *str)
{
	int			sign;
	int			ret_num;
	int			i;

	i = 0;
	ret_num = 0;
	sign = 1;
	while (*str == '\t' || *str == '\n' || *str == '\v' ||
						*str == '\r' || *str == '\f' || *str == ' ')
		str++;
	if (*str == '-')
		sign = -1;
	if (*str == '-' || *str == '+')
		str++;
	if (input_test(sign, (char *)str) != 1)
		return (input_test(sign, (char *)str));
	while (str[i] >= '0' && str[i] <= '9')
	{
		ret_num *= 10;
		ret_num += str[i++] - '0';
	}
	return (ret_num * sign);
}
