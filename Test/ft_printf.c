#include "ft_printf.h"

int  ft_printf(const char *format, ...)
{
	int i;
	int count;
	t_list options = {0};
	va_list ap;

	if (write(1, 0, 0) == -1)
        return (-1);
	va_start(ap, format);
	options = ft_init(options);
	count = 0;
	i = 0;
	while (format[i])
	{
		if (format[i] == '%')
		{
			i++;
			ft_get_flags(format, &options, i);
			count += ft_print_format(format[ft_skip(format, &i)], ap, options);
            i++;
		}
		else
			count += write(1, &format[i++], 1);
	}
	va_end(ap);
	return (count);	
}


int ft_print_format(char format_specifier, va_list ap, t_list options)
{
	int count;
	count = 0;
	if (format_specifier == 'c')
		count += ft_printchar(va_arg(ap, int), options);
    else if (format_specifier == 's')
		count += ft_printstr(va_arg(ap, char *), options); 
    else if (format_specifier == 'i' || format_specifier == 'd')
		count += ft_printdigit(va_arg(ap, int), options);
    else if (format_specifier == 'p')
	{
		unsigned long ptr = (unsigned long)(va_arg(ap, void *));
		count += ft_printaddress(ptr, options);
	}
    else if (format_specifier == 'u')
		count += ft_printunsigned(va_arg(ap, unsigned int), options);
    else if (format_specifier == '%')
        count += ft_putchar('%');
	return (count);
}

int ft_skip(const char *format, int *i)
{
    if (format[*i] == '%')
        return (*i);
	while (format[*i] == '%' || format[*i] == '-' || format[*i] == '+'
		|| format[*i] == ' ' || format[*i] == '0'|| format[*i] == '#')
	{
		(*i)++;
	}
	while(format[*i] >= '0' && format[*i] <= '9')
		(*i)++;
	if (format[*i] == '.')
	{
		(*i)++;
		while(format[*i] >= '0' && format[*i] <= '9')
		(*i)++;
	}
	return (*i);
}
void	ft_get_flags(const char *format, t_list *flag, int i)
{
	while ((format[i] &&  format[i] == '-' )
	|| format[i] == '+' || format[i] == ' ' 
	||  format[i] == '0' || format[i] == '#')
	{
		if (format[i] == '-')
		{
			flag->minus_flag = true;
			flag->zero_flag = false;
		}
		else if (format[i] == '+')
		{
			flag->plus_flag = true;
			flag->space_flag = false;
		}
		else if (format[i] == ' ' && flag->plus_flag == false)
			flag->space_flag = true;
		else if (format[i] == '0' && flag->minus_flag == false)
			flag->zero_flag = true;
		else if (format[i] == '#')
			flag->hash_flag = true;
		i++;
	}
	flag->width = ft_count_width(format, i);
	flag->precision = ft_count_precision(format, i);
}

