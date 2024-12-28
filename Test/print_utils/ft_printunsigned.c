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
int ft_printunsigned(unsigned int n, t_list flag)
{
	int count;
	int len;
	int effective_len;
	count = 0;

	len = ft_countlen_number(n);
	effective_len = len;
	if (flag.precision >= 0 && flag.precision < len)
		effective_len = flag.precision;
	if (flag.width > effective_len && !flag.minus_flag && !flag.zero_flag)
		count += ft_putnchar(' ', flag.width - effective_len);
	if (flag.width > effective_len && !flag.minus_flag && flag.zero_flag && flag.precision < 0)
		count += ft_putnchar('0', flag.width - effective_len);
	if (flag.precision > len)
		count += ft_putnchar('0', flag.precision - len);
	count += ft_putdigit(n, 10, "0123456789");
	if (flag.width > effective_len && flag.minus_flag)
		count += ft_putnchar(' ', flag.width - effective_len);
	return (count);
}