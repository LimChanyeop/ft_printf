
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
void			init_flag(t_flag *flag);
int				ft_putnbr(int n);
int				handle_d(va_list ap, t_flag *flag);
int				handle_c(va_list ap, t_flag *flag);
int				print_c(char c, t_flag *flag);
int				print_d(int i, t_flag *flag);
int				get_int_len(int i);
int				handle_width(t_flag *flag, int len);
int				handle_sign(t_flag *flag);
int				handle_prec(t_flag *flag, int len);

#endif
