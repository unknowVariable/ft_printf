/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconstan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 23:12:27 by aconstan          #+#    #+#             */
/*   Updated: 2023/12/08 05:34:38 by aconstan         ###   ########.fr       */
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

/*
int	main(void)
{
	char str[4] = "alix";
	char str2[17] = " le magnifique !";
	int	i = 42;
	int j = 420;
	char letter = 'a';

	// Testing no arguments
	ft_printf("\nTesting without Args : \n\n");
	ft_printf("test_1 = Hello 42 ! \n");
	ft_printf("test_2 = Hello 42 dqwfewgrhtjrytkuyfjyhtgrfeqdwfergtehrdyjhgrfedwqfewrgehgfqdwqefrghtydj! \n");
	ft_printf("Test_3 = percent no args : %%%%\n");

	// Testing %c
	ft_printf("\nTesting with %%c : \n\n");
	ft_printf("test_1 = %c\n", letter); 
	ft_printf("test_2 = %c\n", 'a');
	ft_printf("test_3 = %c%c\n",'a', 'b');
	ft_printf("test_4 = %c%c%c%c%c%c%c\n", 'a', 'b', 'c', 'd', 'e', 'f');
	ft_printf("test_5 = %c\n", 97);

	// Testing %s
	ft_printf("\nTesting with %%s : \n\n");
	ft_printf("test_1 = %s\n", str);
	ft_printf("test_2 = Hello %s\n", "alix");
	ft_printf("test_3 = %s\n", "wdqfewgrehtjyhtgrewrhtjyyyyytsrtrytyjrtwaretyjrhterawrthjyhtrgerwrghthgewrgrehtrjy");
	ft_printf("test_4 = %s%s%s%s%s%s\n", "les ", "petits ", "chats ", "c'est", " trop ", "mignons");
	ft_printf("test_5 = %s%s\n", str, str2);

	// Testing %d
	ft_printf("\nTesting with %%d : \n\n");
	ft_printf("test_1 = %d\n", i);
	ft_printf("test_2 = Hello %d\n", 42);
	ft_printf("test_3 = %d\n", 2147483647);
	ft_printf("test_4 = %d:%d:%d:%d:%d:%d\n", 42, 43, 44, 45, 46, 47);
	ft_printf("test_5 = %d:%d\n", i, j);

	// Testing %d
	ft_printf("\nTesting with %%i : \n\n");
	ft_printf("test_1 = %i\n", i);
	ft_printf("test_2 = Hello %i\n", 42);
	ft_printf("test_3 = %i\n", 2147483647);
	ft_printf("test_4 = %i:%i:%i:%i:%i:%i\n", 42, 43, 44, 45, 46, 47);
	ft_printf("test_5 = %i:%i\n", i, j);

	// Testing %x and %X
	ft_printf("\nTesting with %%x & %%X : \n\n");
	ft_printf("test_1 = Hexa: %x\n", 15);               // Attendu: "Hexa: f"
    ft_printf("test_2 = Hexa: %x\n", 0);                // Attendu: "Hexa: 0"
    ft_printf("test_3 = Hexa: %x\n", 123456789);        // Attendu: "Hexa: 75bcd15"
    ft_printf("test_4 = Hexa: %x\n", -42);              // Attendu: Affichage en hexa du complément à 2 de -42
    ft_printf("test_5 = Dec: %d, Hexa: %x\n", 42, 42);  // Attendu: "Dec: 42, Hexa: 2a"

    // Saut de ligne entre les groupes de tests
    ft_printf("\n");

    // Tests pour %X (hexadécimal en majuscules)
    ft_printf("test_1 = Hexa: %X\n", 15);               // Attendu: "Hexa: F"
    ft_printf("test_2 = Hexa: %X\n", 0);                // Attendu: "Hexa: 0"
    ft_printf("test_3 = Hexa: %X\n", 123456789);        // Attendu: "Hexa: 75BCD15"
    ft_printf("test_4 = Hexa: %X\n", -42);              // Attendu: Affichage en hexa du complément à 2 de -42
    ft_printf("test_5 = min: %x, MAJ: %X\n", 255, 255); // Attendu: "min: ff, MAJ: FF"

	// Testing %u
	ft_printf("\nTesting with %%u : \n\n");
	ft_printf("test_1 = Unsigned: %u\n", 15);                 // Attendu: "Unsigned: 15"
	ft_printf("test_2 = Unsigned: %u\n", 0);                  // Attendu: "Unsigned: 0"
	ft_printf("test_3 = Unsigned: %u\n", 123456789);          // Attendu: "Unsigned: 123456789"
	ft_printf("test_4 = Unsigned: %u\n", -42);                // Attendu: Affichage en décimal du complément à 2 de -42 (dépend de la taille de l'int)
	ft_printf("test_5 = Dec: %d, Unsigned: %u\n", 42, 42);    // Attendu: "Dec: 42, Unsigned: 42"

	return (0);
}
*/
