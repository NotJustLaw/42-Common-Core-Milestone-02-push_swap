/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skuhlcke <skuhlcke@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 13:31:50 by skuhlcke          #+#    #+#             */
/*   Updated: 2025/04/29 13:31:52 by skuhlcke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	format_checker(char c, va_list args)
{
	int		count;
	void	*ptr;

	count = 0;
	if (c == 'c')
		count = ft_putchar(va_arg(args, int));
	else if (c == 's')
		count = ft_putstr(va_arg(args, char *));
	else if (c == 'p')
	{
		ptr = va_arg(args, void *);
		if (ptr == NULL)
			return (ft_putstr("(nil)"));
		count = ft_putstr("0x");
		count += ft_puthex((unsigned long)ptr, 'x');
	}
	else if (c == 'd' || c == 'i')
		count = ft_putnbr(va_arg(args, int));
	else if (c == 'u')
		count = ft_putunbr(va_arg(args, unsigned int));
	else if (c == 'x' || c == 'X')
		count = ft_puthex(va_arg(args, unsigned int), c);
	else if (c == '%')
		count = ft_putchar('%');
	return (count);
}

int	ft_printf(const char *format, ...)
{
	int		i;
	int		count;
	va_list	args;

	i = 0;
	count = 0;
	if (!format)
		return (-1);
	va_start(args, format);
	while (format[i])
	{
		if (format[i] == '%')
		{
			i++;
			count += format_checker(format[i], args);
		}
		else
			count += ft_putchar(format[i]);
		i++;
	}
	va_end(args);
	return (count);
}
