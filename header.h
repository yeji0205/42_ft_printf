/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yegipark <yegipark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 17:10:29 by yegpark           #+#    #+#             */
/*   Updated: 2023/06/29 01:06:59 by yegipark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
#define HEADER_H

#include <unistd.h>
#include <stdarg.h>

int	ft_printf(const char *format, ...);
int	ft_putchar(char c);
int	ft_putstr(char *s);
int	ft_num_base_int(int nbr, char *base);
int	ft_strlen(char *s);
int	ft_num_base(unsigned int nbr, char *base);
int	ft_num_pointer(unsigned long nbr, char *base);


#endif