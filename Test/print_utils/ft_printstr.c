#include "ft_printf.h"

int ft_printstr(char *str, t_list flag)
{
	int count;
	int len;

	if (!str)
		str = "(null)";
	count = 0;
	len = 0;
	while (str[len])
	{
		len++;
	}
	if (flag.precision && flag.precision >= 0 && flag.precision < len)
		len = flag.precision;
	if (flag.width > len && !flag.minus_flag && flag.zero_flag)
		count += ft_putnchar('0', flag.width - len);
	if (flag.width > len && !flag.minus_flag && !flag.zero_flag)
		count += ft_putnchar(' ', flag.width - len);
	count += write(1, str, len);
	if (flag.width > len && flag.minus_flag)
		count += ft_putnchar(' ', flag.width - len);
	return (count);
}