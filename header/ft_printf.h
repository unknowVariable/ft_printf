/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconstan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 06:39:37 by aconstan          #+#    #+#             */
/*   Updated: 2023/12/05 06:42:08 by aconstan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

int	ft_printf(const char *str, ...);
int	ft_print_char(int c);
int	ft_print_percent(void);
int	ft_strcmp(const char *str1, const char *str2);
int	ft_print_str(char *str);
int	ft_print_digit(long n, int base);
int	ft_print_digit_hex(unsigned long n, int base, char *letter_case);
int	ft_print_pointer(va_list ap);

#endif
