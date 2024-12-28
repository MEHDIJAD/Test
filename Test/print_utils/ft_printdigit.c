#include "ft_printf.h"

static int ft_countlen_number(int nbr)
{
	int len;

	len = 0;
	if (nbr == 0)
		return (1);
	else if (nbr < 0)
	{
		nbr = -nbr;
	}
	while (nbr > 0)
	{
		len++;
		nbr /= 10;
	}
	return (len);
}

int ft_printdigit(int nbr, t_list flag)
{
    int  count;
    int len;
    
    len = ft_countlen_number(nbr);
    count = 0;
    if (nbr < 0)
    {
        count += write(1, "-", 1);
        len++;
    }
    if (flag.plus_flag && nbr > 0)
        count += write(1, "+", 1);
    if (flag.space_flag)
        count += write(1, " ", 1);
    if (flag.precision > len && !flag.width)
        count += ft_putnchar('0', flag.precision - len);
    if (flag.width > len && !flag.minus_flag && flag.zero_flag)
    if (flag.width > len && !flag.minus_flag && flag.space_flag)
        count += ft_putnchar(' ', flag.width - len);
        count += ft_putnchar('0', flag.width - len);
    count += ft_putdigit(nbr, 10, "0123456789");
    if (flag.width > len && flag.minus_flag)
        count += ft_putnchar(' ', flag.width - len);
    return (count);
}

