# Project ft_printf

## Description

The ft_printf project involves creating a custom `printf` function in C, named `ft_printf`. This function replicates the behavior of the standard C library's `printf` function, but includes additional features and a custom implementation. The aim is to deeply understand how `printf` works, to learn how to handle variable arguments in C, and to enhance programming skills.

## Features

- Support for format specifier conversions:
  - `%c`: Displays a character
  - `%s`: Displays a string of characters
  - `%d`, `%i`: Displays a signed integer in base 10
  - `%x`, `%X`: Displays an unsigned integer in hexadecimal (lowercase or uppercase)
  - `%u`: Displays an unsigned integer in base 10
  - `%p`: Displays a pointer in hexadecimal

## Usage

To use the `ft_printf` function in your program, you need to include the corresponding header file and call the function as you would with `printf`. Here is a minimal example of usage:

```c
#include "ft_printf.h"

int main()
{
    ft_printf("Hello, %s!\n", "world");
    ft_printf("The answer is %d\n", 42);
    return (0);
}
