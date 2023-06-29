/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yegpark <yegpark@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 17:09:27 by yegpark           #+#    #+#             */
/*   Updated: 2023/06/29 14:49:32 by yegpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	handling_null_str(va_list args)
{
	char	*str;
	int		count;

	count = 0;
	str = va_arg(args, char *);
	if (str == NULL)
		count += ft_putstr("(null)");
	else
		count += ft_putstr(str);
	return (count);
}

static int	handling_null_ptr(va_list args)
{
	void	*ptr;
	int		count;

	count = 0;
	ptr = va_arg(args, void *);
	if ((unsigned long)ptr == 0)
		count += ft_putstr("(nil)");
	else
	{
		ft_putstr("0x");
		count += 2;
		count += ft_num_pointer((unsigned long)ptr, HEXA_SMALL);
	}
	return (count);
}

static int	format_check(const char *format, int count, int i, va_list args)
{
	if (format[i] == 'c')
		count += ft_putchar((char)va_arg(args, int));
	else if (format[i] == 's')
		count += handling_null_str(args);
	else if (format[i] == 'p')
		count += handling_null_ptr(args);
	else if (format[i] == 'd' || format[i] == 'i')
		count += ft_num_base_int(va_arg(args, int), DIGIT);
	else if (format[i] == 'u')
		count += ft_num_base(va_arg(args, unsigned int), DIGIT);
	else if (format[i] == 'x')
		count += ft_num_base(va_arg(args, unsigned int), HEXA_SMALL);
	else if (format[i] == 'X')
		count += ft_num_base(va_arg(args, unsigned int), HEXA_BIG);
	else if (format[i] == '%')
		count += ft_putchar('%');
	else if (format[i] == '\n')
		count += ft_putstr("\n");
	return (count);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		i;
	int		count;

	va_start(args, format);
	i = 0;
	count = 0;
	while (format[i])
	{
		if (format[i] == '%')
		{
			i++;
			count = format_check(format, count, i, args);
		}
		else
			count += ft_putchar(format[i]);
		i++;
	}
	return (count);
}
