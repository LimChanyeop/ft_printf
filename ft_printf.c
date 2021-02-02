/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clim <clim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/27 11:42:06 by clim              #+#    #+#             */
/*   Updated: 2021/02/02 10:56:52 by clim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

void		init_flag(t_flag *flag) // flag 초기화
{
	flag->minus = 0;
	flag->zero = 0;
	flag->dot = 0;
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

char		set_flag(va_list ap, t_flag *flag, char *format, int idx) // flag 처리
{
	int		i;

	flag->type = format[idx];
	i = 1;
	while ((format[i] == '0' || format[i] == '-') && i < idx)
	{
		if (format[i] == '0')
			flag->zero = 1;
		else
			flag->minus = 1;
		i++;
	}
	if (format[i] == '*' && i < idx)
	{
		flag->width = va_arg(ap, int);
		i++;
	}	
	else if (ft_isdigit(format[i]) && i < idx)
	{
		flag->width = ft_atoi(&format[i]);
		while(ft_isdigit(format[i]))
			i++;
	}
	if (format[i++] == '.' && i < idx)
	{
		flag->dot = 1;
		if(format[i] == '*')
			flag->prec = va_arg(ap, int);		
		else
			flag->prec = ft_atoi(&format[i]);
	}
	return (flag->type);
}

int		handle(va_list ap, t_flag *flag, char type) //type 별로 print 호출
{
	if (type == 'd')
		handle_d(ap, flag);
	return (0);;
}

void print_flag(t_flag *flag)
{
	printf("flag->minus = %d || flag->zero = %d	|| flag->dot = %d || flag->width = %d || flag->len = %d || flag-> prec = %d || flag->type = %c\n", \
			 flag->minus, flag->zero, flag->dot, flag->width, flag->len, flag->prec, flag->type);
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
			handle(ap, &flag, set_flag(ap, &flag, (char *)(format), type_idx((char *)format)));
			print_flag(&flag);
			format += type_idx((char *)format);
		}
		else
			ft_putchar_fd((char)*format, 1);
		format++;
	}
	return (ret_cnt);
}