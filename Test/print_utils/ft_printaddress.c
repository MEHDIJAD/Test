#include "ft_printf.h"

static int ft_countlen_adress(unsigned long number, int base)
{
    int len = 0;

    if (number == 0)
        return 1;  // "0" in hexadecimal is just 1 character

    while (number > 0)
    {
        len++;
        number /= base;
    }

    return len;
}
int ft_printaddress(unsigned long ptr, t_list flag)
{
	int count;
	int len;
	

	count = 0;
	count += write(1, "0x",2);
	len = ft_countlen_adress(ptr, 16) + 2;
	if (flag.width > len && !flag.minus_flag && flag.zero_flag)
		count +=  ft_putnchar('0', flag.width - len);
	count += ft_putdigit(ptr, 16, "0123456789abcdef");
	if (flag.width > len && flag.minus_flag)
		count +=  ft_putnchar('0', flag.width - len);
	return (count);	
}

