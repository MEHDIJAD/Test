#include "ft_printf.h"

int ft_printchar(char c, t_list flag)
{
	int count;

	count = 0;
	if (flag.width > 1 && !flag.minus_flag)
		count += ft_putnchar(' ', flag.width - 1);
	count += write(1, &c, 1);
	if (flag.width > 1 && flag.minus_flag)
		count += ft_putnchar(' ', flag.width - 1);
	return (count);	
}

int ft_putchar(int c)
{
    write(1, &c, 1);
    return(1);    
}
