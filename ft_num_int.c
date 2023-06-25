/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_num_int.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yegipark <yegipark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 15:19:03 by yegpark           #+#    #+#             */
/*   Updated: 2023/06/25 03:57:04 by yegipark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	ft_num_int(int n)
{
	int	count;

	count = 0;
	if (n == -2147483648)
	{
		ft_putchar('-');
		ft_putchar('2');
		ft_num_int(147483648);
	}
	else if (n < 0)
	{
		ft_putchar('-');
		ft_num_int(-n);
	}
	else if (n > 9)
	{
		ft_num_int(n / 10);
		ft_num_int(n % 10);
	}
	else
	{
		ft_putchar(n + '0');
		count++;
	}
	return (count);
}
