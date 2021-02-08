/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clim <clim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/04 11:01:04 by clim              #+#    #+#             */
/*   Updated: 2021/02/08 12:54:48 by clim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include <stdbool.h>
# include "libft/libft.h"

typedef struct s_flag{
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
int				handle_d(va_list ap, t_flag *flag);
int				handle_c(va_list ap, t_flag *flag);
int				handle_u(va_list ap, t_flag *flag);
int				handle_s(va_list ap, t_flag *flag);
int				handle_x(va_list ap, t_flag *flag);
int				handle_p(va_list ap, t_flag *flag);
int				handle_pct();
int				handle_width(t_flag *flag, int len);
int				handle_sign(t_flag *flag);
int				handle_prec(t_flag *flag, int len);

int				print_c(char c, t_flag *flag);
int				print_d(long long i, t_flag *flag);
int				print_u(unsigned int i, t_flag *flag);
int				print_s(char *s, t_flag *flag);
int				print_x(char *x, t_flag *flag);
int				print_p(char *p, t_flag *flag);
void			print_pct();

int				get_int_len(long long i);


#endif
