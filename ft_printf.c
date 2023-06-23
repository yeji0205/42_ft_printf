/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yegpark <yegpark@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 17:09:27 by yegpark           #+#    #+#             */
/*   Updated: 2023/06/23 16:40:41 by yegpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int	i;
	int	count;

	va_start(args, format);

	i = 0;
	count = 0;
	while(format[i])
	{
		count++;
		if (format[i] == '%')
		{
			i++;
			if (format[i] == 's')
				count += ft_putstr(va_arg(args, char *));
			else if (format[i] == 'd')
				ft_putnbr(va_arg(args, int));
			else if (format[i] == '\n')
				write(1, "\n", 1);
		}
		else 
		{
			ft_putchar(format[i]);
		}
		i++;
	}

	return (count);
}


#include <stdio.h>

int main()
{
	char *s = "test";
	int	num = 12345678;

	int from_original = printf("compare: %s, %d\n", s, num);
	int from_ft_printf = ft_printf("compare: %s, %d\n", s, num);

	printf("number of element %d\n", from_original);	
	printf("number of element %d\n", from_ft_printf);
	

}