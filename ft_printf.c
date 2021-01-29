/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanyeop <chanyeop@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/27 11:42:06 by clim              #+#    #+#             */
/*   Updated: 2021/01/29 10:40:06 by chanyeop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

void		init_flag(t_flag *flag) // flag 초기화
{
	flag->minus = 0;
	flag->zero = 0;
	flag->aster_width = 0;
	flag->aster_prec = 0;
	flag->width = 0;
	flag->prec = 0;
	flag->len = 0;
	flag->type = '\0';
}

int			type_idx(char *format) // type 위치반환
{
	int		i;

	i = 1;
	while (format[i])
	{
		if (format[i] == 'c' || format[i] == 's' || format[i] == 'p' \
				|| format[i] == 'd' || format[i] == 'i' || format[i] == 'u' \
				|| format[i] == 'x' || format[i] == 'X')
			return (i);
		else
			i++;
	}
	return (-1);
}

char		set_flag(t_flag *flag, char *format, int idx) // flag 처리
{
	int		i;

	i = 1;
	if (format[i] == '0')
	{
		flag->zero = true;
		i++;
	}
	if (format[i] == '-')
	{
		flag->minus = true;
		i++;
	}
	if (format[i] == '*')
		flag->aster_width = true;
	else if (ft_isdigit(format[i]))
	{
		flag->width = ft_atoi(&format[i]);
		while(ft_isdigit(format[i]))
			i++;
	}
	if (format[i++] == '.')
	{
		if(format[i] == '*')
		{
			flag->aster_prec = true;		
			i++;
		}
		flag->prec = ft_atoi(&format[i]);
	}
	return (format[idx]);
}

int		handle(char type, va_list ap) //type 별로 print 호출
{
	int		i;

	if (type == 'd')
		i = va_arg(ap, int);
	return (i);
}

void print_flag(t_flag *flag)
{
	printf("flag->minus = %d || flag->zero = %d	|| flag->aster_width = %d || flag->aster_prec = %d || flag->dot = %d || flag->width = %d || flag->len = %d || flag-> prec = %d || flag->type = %c\n", \
			 flag->minus, flag->zero, flag->aster_width, flag->aster_prec, flag->dot, flag->width, flag->len, flag->prec, flag->type);
}

int			ft_printf(const char *format, ...)
{
	va_list ap;
	int		ret_cnt;
	t_flag	flag;

	ret_cnt = 0;
	va_start(ap, format);
	while (*format)
	{
		if (*format == '%')
		{
			init_flag(&flag);
			handle(set_flag(&flag, (char *)(format), type_idx((char *)format)), ap);
			print_flag(&flag);
			format += type_idx((char *)format) + 1;
		}
		else
			ft_putchar((char *)format);
		format++;
	}
	return (ret_cnt);
}