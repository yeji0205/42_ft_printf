/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yegpark <yegpark@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 17:10:29 by yegpark           #+#    #+#             */
/*   Updated: 2023/06/23 16:40:31 by yegpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
#define HEADER_H

#include <unistd.h>
#include <stdarg.h>

int	ft_printf(const char *format, ...);
void	ft_putchar(char c);
int	ft_putstr(char *s);
void	ft_putnbr(int n);
size_t	ft_strlen(const char *s);

#endif