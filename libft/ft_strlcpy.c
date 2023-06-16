/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccestini <ccestini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 11:58:59 by ccestini          #+#    #+#             */
/*   Updated: 2022/02/02 13:17:34 by ccestini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;

	if (!dstsize)
		return (ft_strlen(src));
	i = 0;
	while (src[i] && i < (dstsize - 1))
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (ft_strlen(src));
}
/*
Funcao copia a string SRC na DST.
A string SRC eh copiada para a primeira posicao da string DST.
O retorno da funcao eh o tamanho len da fonte.
*/
/*para testar
#include<stdio.h>
#include<unistd.h>
#include<string.h>
#include<strings.h>
int	ft_strlcpy(char *dst, const char *src, int dstsize)
{
	int	srcsize;
	int	i;
	if (!dst || !src)
		return (0);
	int	len;
	len = 0;
	while (src[len] != '\0')
		len++;
	srcsize = len;
	i = 0;
	if (dstsize != 0)
	{
		while (src[i] != '\0' && i < (dstsize - 1))
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	return (srcsize);
}
int main()
{
	char dst[] = "por cima";
	char src[] = "a ser copiado";
	printf("o que esta no destino: %s\n", dst);
	printf("o que esta na fonte: %s\n", src);
	ft_strlcpy(dst, src, 50);
	printf("como ficou o destino apos a funcao: %s\n", dst);
	printf("retorno da funcao, size = %d\n", ft_strlcpy(dst, src, 50));
}
*/
