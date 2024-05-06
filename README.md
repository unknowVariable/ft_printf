# Projet ft_printf

## Description

Le projet ft_printf consiste en la création d'une fonction `printf` personnalisée en langage C, nommée `ft_printf`. Cette fonction reproduit le comportement de la fonction `printf` standard de la bibliothèque C, mais avec des fonctionnalités supplémentaires et une implémentation personnalisée. L'objectif est de comprendre en profondeur le fonctionnement de `printf`, d'apprendre à manipuler les arguments variables en C, et de développer ses compétences en programmation.

## Fonctionnalités

- Prise en charge des conversions de spécificateurs de format :
  - `%c` : Affiche un caractère
  - `%s` : Affiche une chaîne de caractères
  - `%d`, `%i` : Affiche un entier signé en base 10
  - `%x`, `%X` : Affiche un entier non signé en base 16 (en minuscules ou majuscules)
  - `%u` : Affiche un entier non signé en base 10
  - `%p` : Affiche un pointeur en hexadecimal

## Utilisation

Pour utiliser la fonction `ft_printf` dans votre programme, vous devez inclure le fichier header correspondant et appeler la fonction comme vous le feriez avec `printf`. Voici un exemple minimal d'utilisation :

```c
#include "ft_printf.h"

int main()
{
    ft_printf("Hello, %s!\n", "world");
    ft_printf("The answer is %d\n", 42);
    return (0);
}
