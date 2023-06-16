/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccestini <ccestini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 00:25:49 by ccestini          #+#    #+#             */
/*   Updated: 2022/02/15 11:53:22 by ccestini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	if (n == 0)
		return (0);
	while (i < n)
	{
		if ((unsigned char)s1[i] == (unsigned char)s2[i]
			&& (unsigned char)s1[i] != '\0' && (unsigned char)s2[i] != '\0')
			i++;
		else
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
	}
	return (0);
}
/*
Essa funcao compara 2 strings. Se elas forem identicas, retorna 0.
Se diferentes, o retorno eh a diferenca de valor entre o primeiro
caracter diferente entre a primeira e a segunda string.
A funcao comeca com a posicao i em zero e enquanto i for menor que n, 
a comparacao eh feita. Se forem iguais somente incrementa i e retorno 0. 
Se s1 diferente de s2 dai o retorno eh a diferente nessa exata posicao i,
entre s2 e s1.
Ex. s1 = Hello e s2 = HEllo, o retorno sera -32 (69-101) a 
dif entre 'E' e 'e' na ascii.
*/
/*
#include <stdio.h>
#include <stdlib.h>
int	main(int ac, char *av[])
{
	printf("%d\n", ft_strncmp(av[1], av[2], atoi(av[3])));
	return (0);
}
*/