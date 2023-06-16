/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccestini <ccestini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 23:42:40 by ccestini          #+#    #+#             */
/*   Updated: 2022/01/27 20:02:36 by ccestini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		if (((unsigned char *)s1)[i] != ((unsigned char *)s2)[i])
			return (((unsigned char *)s1)[i] - ((unsigned char *)s2)[i]);
		i++;
	}
	return (0);
}
/*
Essa funcao compara 2 strings. Se elas forem identicas, retorna 0.
Se bytes diferentes, o retorno eh a diferenca de valor entre o primeiro
caracter diferente entre a primeira e a segunda string.
A funcao comeca com a posicao i em zero e enquanto i for menor que n, 
a comparacao eh feita. Se forem iguais somente incrementa i e retorno 0. 
Se s1 diferente de s2 dai o retorno eh a diferente nessa exata posicao i,
entre s2 e s1.
Parecida com a funcao strncmp, a memcmp compara bytes.
*/