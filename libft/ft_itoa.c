/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccestini <ccestini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 12:39:58 by ccestini          #+#    #+#             */
/*   Updated: 2022/02/15 11:53:57 by ccestini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_countnbr(long n)
{
	int	i;

	i = 0;
	if (n < 0)
	{
		n = -n;
		i++;
	}
	if (n == 0)
		return (1);
	while (n > 0)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	char	*str;
	int		i;
	long	nb;

	nb = n;
	i = ft_countnbr(nb);
	str = (char *)malloc(sizeof(char) * (i + 1));
	if (!str)
		return (0);
	if (nb < 0)
	{
		str[0] = '-';
		nb = -nb;
	}
	str[i] = '\0';
	i = i - 1;
	while (nb > 0)
	{
		str[i] = nb % 10 + '0';
		i--;
		nb = nb / 10;
	}
	if (n == 0)
		str[0] = '0';
	return (str);
}
/*
Funcao oposta da atoi, a itoa transforma nros em uma string, alocando 
memoria para essa string com malloc.
Na primeira parte eu criei uma funcao para contar a qtde de digitos no nro,
assim eu teria a qtde de espacos de caracteres necessarios para string (size).
Depois foi criada uma variavel 'nb', apenas para tornar o int 'n' em long.
Depois colocamos o sinal negativo se o nro foi menor q zero.
No while fazemos a divisao e quociente para ter os caracteres dos nros 
de tras para frente.
Por ultimo a condicao se caso o nro for zero.
*/
/*
#include <stdio.h>
int	main()
{
	printf("%s\n", ft_itoa(23255));
}
*/