/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yegipark <yegipark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 17:09:27 by yegpark           #+#    #+#             */
/*   Updated: 2023/06/29 01:04:48 by yegipark         ###   ########.fr       */
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
		if (format[i] == '%')
		{
			i++;
			if (format[i] == 'c')
				count += ft_putchar((char)va_arg(args, int));
			else if (format[i] == 's')
				count += ft_putstr(va_arg(args, char *));
			else if (format[i] == 'p')
			{
				ft_putstr("0x");
				count += 2;
				ptr = va_arg(args, void *);
				count += ft_num_pointer((unsigned long)ptr, "0123456789abcdef");
			}
			else if (format[i] == 'd' || format[i] == 'i')
				count += ft_num_base_int(va_arg(args, int), "0123456789");
			else if (format[i] == 'u')
				count += ft_num_base(va_arg(args, unsigned int), "0123456789");
			else if (format[i] == 'x')
				count += ft_num_base(va_arg(args, unsigned int), "0123456789abcdef");
			else if (format[i] == 'X')
				count += ft_num_base(va_arg(args, unsigned int), "0123456789ABCDEF");
			else if (format[i] == '%')
				count += ft_putchar('%');
			else if (format[i] == '\n')
				count += ft_putstr("\n");
		}
		else
			count += ft_putchar(format[i]);
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


	printf(", number of element_ft %d\n", ft_printf("%s", "hello"));
	printf(", number of element_org %d\n", printf("%s", "hello"));
	printf(", number of element %d\n", ft_printf("%d", -2147483648));
	printf(", number of element %d\n", printf("%ld", -2147483648));
	printf(", number of element %d\n", ft_printf("%d", 0));

}