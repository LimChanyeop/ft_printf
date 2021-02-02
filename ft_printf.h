
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
	bool		dot;
	int			width;
	int			len;
	int			prec;
	char		type;
}				t_flag;

int				ft_printf(const char *format, ...);
void			init_flag(t_flag *flag);
void			ft_putnbr(int n);
void			handle_d(va_list ap, t_flag *flag);
void			print_d(int i, t_flag *flag);
int				get_int_len(int i);
int				handle_width(char c, int cnt);

#endif
