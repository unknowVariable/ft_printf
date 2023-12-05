/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_digits_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconstan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 03:35:50 by aconstan          #+#    #+#             */
/*   Updated: 2023/12/05 06:33:24 by aconstan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/ft_printf.h"

int	ft_print_digit(long n, int base)
{
	int		count;
	char	*symbols;

	symbols = "0123456789abcdef";
	count = 0;
	if (n < 0)
	{
		write(1, "-", 1);
		return (ft_print_digit(-n, base) + 1);
	}
	else if (n < base)
	{
		return (count + ft_print_char(symbols[n]));
	}
	else
	{
		count = ft_print_digit(n / base, base);
		return (count + ft_print_digit(n % base, base));
	}
}

int	ft_print_digit_hex(unsigned long n, int base, char *letter_case)
{
	int		count;
	char	*symbols;

	count = 0;
	if (ft_strcmp(letter_case, "lowercase") == 0)
		symbols = "0123456789abcdef";
	else
		symbols = "0123456789ABCDEF";
	if (n < 0)
	{
		write(1, "-", 1);
		return (ft_print_digit_hex(-n, base, letter_case) + 1);
	}
	else if (n < (unsigned long)base)
	{
		return (ft_print_char(symbols[n]));
	}
	else
	{
		count = ft_print_digit_hex(n / base, base, letter_case);
		return (count + ft_print_digit_hex(n % base, base, letter_case));
	}
}

int	ft_print_pointer(va_list ap)
{
	int		count;
	void	*ptr;

	count = 0;
	ptr = va_arg(ap, void *);
	if (!ptr)
	{
		return (write(1, "(nil)", 5));
	}
	count += write(1, "0x", 2);
	count += ft_print_digit_hex((unsigned long)ptr, 16, "lowercase");
	return (count);
}
