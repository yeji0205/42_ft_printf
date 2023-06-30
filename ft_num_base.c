/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_num_base.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yegpark <yegpark@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/24 22:39:57 by yegipark          #+#    #+#             */
/*   Updated: 2023/06/29 16:04:49 by yegpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_num_base_int(int nbr, char *base)
{
	int	base_len;
	int	count;

	base_len = ft_strlen(base);
	count = 0;
	if (nbr == -2147483648)
	{
		count += ft_putchar('-');
		count += ft_putchar('2');
		nbr = 147483648;
	}
	else if (nbr < 0)
	{
		ft_putchar('-');
		nbr = -nbr;
		count++;
	}
	if (nbr >= base_len)
		count += ft_num_base_int((nbr / base_len), base);
	count += ft_putchar(base[nbr % base_len]);
	return (count);
}

int	ft_num_base(unsigned int nbr, char *base)
{
	unsigned int	base_len;
	int				count;

	base_len = ft_strlen(base);
	count = 0;
	if (nbr >= base_len)
		count += ft_num_base((nbr / base_len), base);
	count += ft_putchar(base[nbr % base_len]);
	return (count);
}

int	ft_num_pointer(unsigned long long nbr, char *base)
{
	unsigned long long	base_len;
	int					count;

	base_len = ft_strlen(base);
	count = 0;
	if (nbr >= base_len)
		count += ft_num_pointer((nbr / base_len), base);
	count += ft_putchar(base[nbr % base_len]);
	return (count);
}
