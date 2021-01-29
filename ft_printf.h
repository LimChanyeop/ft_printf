/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanyeop <chanyeop@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/28 12:19:29 by clim              #+#    #+#             */
/*   Updated: 2021/01/28 17:42:49 by chanyeop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

typedef struct s_flag{
	int			minus;
	int			zero;
	int			aster_width;
	int			aster_prec;
	int			dot;
	int			width;
	int			len;
	int			prec;
	char		type;
}				t_flag;

int				ft_printf(const char *format, ...);
void			init_flag(t_flag *flag);
int				ft_atoi(const char *str);
int				ft_isdigit(int c);
int				ft_tolower(int c);
int				ft_toupper(int c);
void			ft_putchar(char *c);
size_t			ft_strlen(const char *str);
char			*ft_strdup(const char *s1);
void			ft_putnbr(int n);

#endif
