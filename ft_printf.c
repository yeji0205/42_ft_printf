/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yegipark <yegipark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 17:09:27 by yegpark           #+#    #+#             */
/*   Updated: 2023/06/25 04:01:51 by yegipark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int	i;
	int	count;
	void	*ptr;

	va_start(args, format);

	i = 0;
	count = 0;
	while(format[i])
	{
		count++;
		if (format[i] == '%')
		{
			i++;
			if (format[i] == 'c')
				ft_putchar((char)va_arg(args, int));
			else if (format[i] == 's')
				count += ft_putstr(va_arg(args, char *));
			else if (format[i] == 'p')
			{
				ft_putstr("0x");
				count += 14;
				ptr = va_arg(args, void *);
				count += ft_num_pointer((unsigned long)ptr, "0123456789abcdef");
			}
			else if (format[i] == 'd' || format[i] == 'i')
				count += ft_num_int(va_arg(args, int));
			else if (format[i] == 'u')
				count += ft_num_base(va_arg(args, unsigned int), "0123456789");
			else if (format[i] == 'x')
				count += ft_num_base(va_arg(args, unsigned int), "0123456789abcdef");
			else if (format[i] == 'X')
				count += ft_num_base(va_arg(args, unsigned int), "0123456789ABCDEF");
			else if (format[i] == '%')
				ft_putchar('%');
			else if (format[i] == '\n')
				write(1, "\n", 1);
		}
		else
			ft_putchar(format[i]);
		i++;
	}
	return (count);
}


#include <stdio.h>

int main()
{
	char *s = "test";
	char c = 'A';
	int num = 30;
	unsigned int un_num= 4294967295;
	int *p_num = &num;

	int from_original = printf("compare: %s, %c, %p, %d, %u, %x, %X, %% \n", s, c, p_num, num, un_num, num, num);
	int from_ft_printf = ft_printf("compare: %s, %c, %p, %d, %u, %x, %X, %% \n", s, c, p_num, num, un_num, num, num);

	printf("number of element %d\n", from_original);
	printf("number of element %d\n", from_ft_printf);

}