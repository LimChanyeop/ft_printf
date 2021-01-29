/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clim <clim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/27 11:42:06 by clim              #+#    #+#             */
/*   Updated: 2021/01/29 15:31:35 by clim             ###   ########.fr       */
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

	flag->type = format[idx];
	i = 1;
	while (format[i] == '0' || format[i] == '-')
	{
		if (format[i] == '0')
			flag->zero = 1;
		else
			flag->minus = 1;
		i++;
	}
	if (format[i] == '*')
	{
		flag->aster_width = 1;
		i++;
	}
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
			flag->aster_prec = 1;		
			i++;
		}
		flag->prec = ft_atoi(&format[i]);
	}
	return (flag->type);
}

int		handle(char type, va_list ap, t_flag *flag) //type 별로 print 호출
{
	int		i;

	if (type == 'd')
		handle_d(ap, flag);
	return (i);
}

void print_flag(t_flag *flag)
{
	printf("flag->minus = %d || flag->zero = %d	|| flag->aster_width = %d || flag->aster_prec = %d || flag->width = %d || flag->len = %d || flag-> prec = %d || flag->type = %c\n", \
			 flag->minus, flag->zero, flag->aster_width, flag->aster_prec, flag->width, flag->len, flag->prec, flag->type);
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
			handle(set_flag(&flag, (char *)(format), type_idx((char *)format)), ap, &flag);
			//print_flag(&flag);
			format += type_idx((char *)format);
		}
		else
			ft_putchar((char *)format);
		format++;
	}
	return (ret_cnt);
}