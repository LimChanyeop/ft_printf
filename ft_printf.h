
#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include <stdbool.h>

typedef struct s_flag{
	bool		minus;
	bool		zero;
	bool		aster_width;
	bool		aster_prec;
	int			width;
	int			len;
	int			prec;
	char		type;
}				t_flag;

int				ft_printf(const char *format, ...);
void			init_flag(t_flag *flag);
int				ft_atoi(const char *str);
int				ft_isdigit(int c);
void			ft_putchar(char *c);
size_t			ft_strlen(const char *str);
void			ft_putnbr(int n);
void			handle_d(va_list ap, t_flag *flag);
void			print_d(int i, int width, int len, char blank);
int				get_int_len(int i);

#endif
