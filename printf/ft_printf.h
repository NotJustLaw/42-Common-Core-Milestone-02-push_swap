/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skuhlcke <skuhlcke@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 13:31:40 by skuhlcke          #+#    #+#             */
/*   Updated: 2025/04/29 14:03:29 by skuhlcke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>

int		ft_printf(const char *format, ...);
int		format_checker(char c, va_list args);
int		ft_putchar(char c);
int		ft_putstr(char *s);
int		ft_putnbr(int n);
int		ft_puthex(unsigned long n, char format);
int		ft_putunbr(unsigned int n);

#endif