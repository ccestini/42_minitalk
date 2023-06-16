/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccestini <ccestini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 13:09:30 by ccestini          #+#    #+#             */
/*   Updated: 2022/05/10 12:41:39 by ccestini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_printf(const char *str, ...)
{
	int		i;
	va_list	args;
	int		len;

	i = 0;
	len = 0;
	va_start(args, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			len = len + ft_print_format(args, str[i + 1]);
			i++;
		}
		else
		{
			len = len + ft_printchar(str[i]);
		}
		i++;
	}
	va_end(args);
	return (len);
}
/*
#include<stdio.h>
int main(void)
{
    char a = 'a';
    char b = 'b';
    char *c = "testando a funcao";
    char d = '%';
    int n1 = 55;
    int n2 = -21;
    int n3 = -42949;

    int x = ft_printf("pointer adress M: %p\n", c);
    int x1  = printf("pointer adress R: %p\n", c);

    int y = ft_printf("char str M: %c\n %c\n %s\n", a, b, c);
    int y1 = printf("char str R: %c\n %c\n %s\n", a, b, c);

    int z = ft_printf("M percentual%%: %c\n", d);
    int z1 = printf("R percentual%%: %c\n", d);

    int w = ft_printf("Hexa M: %x\n %X\n %x\n", n1, n2, n3);
    int w1 = printf("Hexa R: %x\n %X\n %x\n", n1, n2, n3);

    int j = ft_printf("M nros d e i: %d\n %i\n %d\n", n1, n2, n3);
    int j1 = printf("R nros d e i: %d\n %i\n %d\n", n1, n2, n3);

    int k = ft_printf("Minha u: %u\n %u\n %u\n", n1, n2, n3);
    int k1 = printf("Real  u: %u\n %u\n %u\n", n1, n2, n3);

    printf("retorno M: %d %d %d %d %d %d\n", x, y, z, w, j, k);
    printf("retorno R: %d %d %d %d %d %d\n", x1, y1, z1, w1, j1, k1);

    ft_printf("formato specifier nao definido:\n %r", a);
}
*/
/*
A funcao tem duas partes assim: printf(["texto e formato"], args)

Primeiro ele vai andando pela primeira parte, a string, ele para
qdo achar um caracter '%', se nao achar, a funcao vai copiando
caracter por caracter no 'else'. Se achar o '%' ele vai chamar
a funcao ft_format que vai dizer qual a funcao deve ser executada
de acordo com o caracter apos o %.
*/
