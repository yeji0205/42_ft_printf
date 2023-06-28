/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_num_base.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yegipark <yegipark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/24 22:39:57 by yegipark          #+#    #+#             */
/*   Updated: 2023/06/29 01:04:26 by yegipark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

// static int	ft_is_valid(char *base)
// {
// 	int	i;
// 	int	j;

// 	i = 0;
// 	if (base[i] == '\0' || ft_strlen(base) == 1)
// 	{
// 		return (1);
// 	}
// 	while (base[i])
// 	{
// 		j = i + 1;
// 		while (j < ft_strlen(base))
// 		{
// 			if (base[i] == base[j] || base[i] == '-' || base[i] == '+')
// 			{
// 				return (1);
// 			}
// 			j++;
// 		}
// 		i++;
// 	}
// 	return (0);
// }

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
	ft_putchar(base[nbr % base_len]);
	count++;
	return (count);
}

int	ft_num_base(unsigned int nbr, char *base)
{
	unsigned int	base_len;
	int	count;

	base_len = ft_strlen(base);
	count = 0;
	if (nbr >= base_len)
		count += ft_num_base_int((nbr / base_len), base);
	ft_putchar(base[nbr % base_len]);
	count++;
	return (count);
}

int	ft_num_pointer(unsigned long nbr, char *base)
{
	unsigned long	base_len;
	int	count;

	base_len = ft_strlen(base);
	count = 0;
	if (nbr >= base_len)
		count += ft_num_pointer((nbr / base_len), base);
	ft_putchar(base[nbr % base_len]);
	count++;
	return (count);
}


// void	ft_putnbr_base(unsigned int nbr, char *base)
// {
// 	int	base_len;

// 	base_len = ft_strlen(base);
// 	if (ft_is_valid(base) == 1)
// 	{
// 		return ;
// 	}
// 	ft_putnbr_helper(nbr, base, base_len);
// }