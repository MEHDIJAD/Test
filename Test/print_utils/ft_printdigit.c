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

static int ft_putsign(int nbr, t_list flag)
{
	int count;

	count = 0;
	if (flag.plus_flag && nbr > 0)
		count += ft_putchar('+');
	else if (nbr < 0)
		count += ft_putchar('-');
	return (count);
}

static int ft_put_precision_padding(int effective_len, t_list flag)
{
	int count;

	count = 0;
	if (flag.precision > effective_len)
		count += ft_putnchar('0', flag.precision - effective_len);
	return (count);
}

static int  ft_put_width_padding(int effective_len, t_list flag)
{
	int count;

	count = 0;
	if (flag.precision > 0)
	{
		count += ft_putnchar(' ', flag.width - effective_len);
	}
	else if ((flag.precision == 0) && flag.zero_flag)
	{
		count += ft_putnchar('0', flag.width - effective_len);		
	}
	else 
	{
		count += ft_putnchar(' ', flag.width - effective_len);	
	}
	return (count);
}

// static int ft_printdigit_with_sign(int nbr, int count, int effective_len, t_list flag)
// {
// 	if (flag.width && flag.precision)
// 	{
// 		count += ft_putsign(nbr, flag);
// 		count += ft_put_precision_padding(effective_len, flag);
// 		count += ft_putdigit(nbr, 10, "0123456789");
// 		count += ft_put_width_padding(effective_len, flag);
// 	}
// 	else if (flag.width && !flag.precision)
// 	{
// 		count += ft_putsign(nbr, flag);
// 		count += ft_putdigit(nbr, 10, "0123456789");
// 		count += ft_put_width_padding(effective_len, flag);
// 	}
// 	else if (flag.precision && !flag.width)
// 	{
// 		count += ft_putsign(nbr, flag);
// 		count += ft_put_precision_padding(effective_len, flag);
// 		count += ft_putdigit(nbr, 10, "0123456789");
// 	}
// 	else
// 	{
// 		count += ft_putsign(nbr, flag);
// 		count += ft_putdigit(nbr, 10, "0123456789");
// 	}	
// 	return (count);
// }
// static int ft_printdigit_without_sign(int nbr, int count, int effective_len, t_list flag)
// {
// 	if (flag.width && flag.precision )
// 	{
// 		count += ft_put_width_padding(effective_len, flag);
// 		count += ft_putsign(nbr, flag);
// 		count += ft_put_precision_padding(effective_len, flag);
// 		count += ft_putdigit(nbr, 10, "0123456789");
// 	}
// 	else if (flag.width  && !flag.precision)
// 	{
// 		count += ft_put_width_padding(effective_len, flag);
// 		count += ft_putsign(nbr, flag);
// 		count += ft_putdigit(nbr, 10, "0123456789");
// 	}
// 	else if (flag.precision && !flag.width)
// 	{
// 		count += ft_putsign(nbr, flag);
// 		count += ft_put_precision_padding(effective_len, flag);
// 		count += ft_putdigit(nbr, 10, "0123456789");
// 	}
// 	else
// 	{
// 		count += ft_putsign(nbr, flag);
// 		count += ft_putdigit(nbr, 10, "0123456789");
// 	}	
// 	return (count);
// }

int ft_printdigit(int nbr, t_list flag)
{
	int count;
	int len_arg;
	int effective_len;

	count = 0;
	len_arg = ft_countlen_number(nbr);
	if (flag.precision > len_arg)
		effective_len = flag.precision;
	else
		effective_len = len_arg;
	if (!flag.minus_flag) // Right-aligned padding
        count += ft_put_width_padding(effective_len, flag);
    
    count += ft_putsign(nbr, flag);
    count += ft_put_precision_padding(effective_len, flag);
    count += ft_putdigit(nbr, 10, "0123456789");

    if (flag.minus_flag) // Left-aligned padding
        count += ft_put_width_padding(effective_len, flag);
    
    return (count);
}

