/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clim <clim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/13 20:21:20 by clim              #+#    #+#             */
/*   Updated: 2021/02/15 18:04:43 by clim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include <stdbool.h>
# include "libft/libft.h"

typedef struct	s_flag{
	bool		minus;
	bool		zero;
	bool		sign_n;
	int			dot;
	int			width;
	int			len;
	int			prec;
	char		type;
}				t_flag;

int				ft_printf(const char *format, ...);
int				ft_putnbr(long long n);
int				put_str(char *s, int len);
int				digit_len(long long i, t_flag *flag);
int				is_specifier(char c);

int				handle_d_i(va_list ap, t_flag *flag);
int				handle_c(va_list ap, t_flag *flag);
int				handle_u(va_list ap, t_flag *flag);
int				handle_s(va_list ap, t_flag *flag);
int				handle_x(va_list ap, t_flag *flag);
int				handle_p(va_list ap, t_flag *flag);
int				handle_pct(t_flag *flag);
int				handle_width(t_flag *flag, int len);
int				handle_sign(t_flag *flag);
int				handle_prec(t_flag *flag, int len);

void			set_width_prec(va_list ap, t_flag *flag, char *format, int i);
int				set_option(va_list ap, t_flag *flag, char *format);

#endif
