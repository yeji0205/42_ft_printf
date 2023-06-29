/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yegpark <yegpark@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 17:10:29 by yegpark           #+#    #+#             */
/*   Updated: 2023/06/29 14:01:46 by yegpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# define DIGIT "0123456789"
# define HEXA_SMALL "0123456789abcdef"
# define HEXA_BIG "0123456789ABCDEF"

# include <unistd.h>
# include <stdarg.h>

int	ft_printf(const char *format, ...);
int	ft_strlen(char *s);
int	ft_putchar(char c);
int	ft_putstr(char *s);
int	ft_num_base_int(int nbr, char *base);
int	ft_num_base(unsigned int nbr, char *base);
int	ft_num_pointer(unsigned long nbr, char *base);

#endif