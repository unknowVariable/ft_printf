/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconstan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 23:12:27 by aconstan          #+#    #+#             */
/*   Updated: 2023/12/05 05:03:44 by aconstan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/ft_printf.h"

int	ft_print_format(char specifier, va_list ap)
{
	int	count;

	count = 0;
	if (specifier == '%')
		count += ft_print_percent();
	else if (specifier == 'c')
		count += ft_print_char(va_arg(ap, int));
	else if (specifier == 's')
		count += ft_print_str(va_arg(ap, char *));
	else if (specifier == 'd')
		count += ft_print_digit((unsigned long)va_arg(ap, int), 10);
	else if (specifier == 'i')
		count += ft_print_digit((unsigned long)va_arg(ap, int), 10);
	else if (specifier == 'x')
		count += ft_print_digit_hex((unsigned long)va_arg(ap, unsigned int), 16,
				"lowercase");
	else if (specifier == 'X')
		count += ft_print_digit_hex((unsigned long)va_arg(ap, unsigned int), 16,
				"uppercase");
	else if (specifier == 'u')
		count += ft_print_digit((unsigned long)va_arg(ap, unsigned int), 10);
	else if (specifier == 'p')
		count += ft_print_pointer(ap);
	return (count);
}

int	ft_printf(const char *str, ...)
{
	va_list	ap;
	int		count_char;
	int		i;

	i = 0;
	va_start(ap, str);
	count_char = 0;
	while (str[i])
	{
		if (str[i] == '%')
			count_char += ft_print_format(str[++i], ap);
		else
			count_char += write(1, &str[i], 1);
		i++;
	}
	va_end(ap);
	return (count_char);
}
