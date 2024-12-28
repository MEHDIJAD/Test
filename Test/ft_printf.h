# ifndef FT_PRINTF_H
#define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include <stdbool.h>
# include <stdio.h>

typedef struct s_list
{
    bool plus_flag;
    bool minus_flag;
    bool space_flag;
    bool hash_flag;
    bool zero_flag;
	int width;
	int precision;
} t_list;

// ft_printf.c
int     ft_printf(const char *format, ...);
int ft_print_format(char format_specifier, va_list ap, t_list options);
void	ft_get_flags(const char *format, t_list *flag, int i);
int ft_skip(const char *format, int *i);

int ft_printchar(char c, t_list flag);
int ft_printstr(char *str, t_list flag);
int  ft_printdigit(int nbr, t_list flag);
int ft_printaddress(unsigned long ptr, t_list flag);
int ft_printunsigned(unsigned int n, t_list flag);

// utils.c
int     ft_putnchar(char c, int n);
t_list  ft_init(t_list flags);
int     ft_count_width(const char *format, int i);
int     ft_count_precision(const char *format, int i);
int     ft_putdigit(long number, int base, char *base_symbols);
int     ft_putchar(int c);


# endif
