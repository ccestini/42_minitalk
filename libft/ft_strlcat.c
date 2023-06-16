/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccestini <ccestini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 12:05:43 by ccestini          #+#    #+#             */
/*   Updated: 2022/02/15 11:53:13 by ccestini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	c;
	size_t	d;

	if (dstsize <= ft_strlen(dst))
		return (dstsize + ft_strlen(src));
	c = ft_strlen(dst);
	d = 0;
	while (src[d] != '\0' && c + 1 < dstsize)
	{
		dst[c] = src[d];
		c++;
		d++;
	}
	dst[c] = '\0';
	return (ft_strlen(dst) + ft_strlen(&src[d]));
}
/*
Funcao copia e concatena duas strings.
a string SRC eh copiada para o final da string DST.
*/
/*
#include<stdio.h>
#include<unistd.h>
#include<string.h>
#include<strings.h>
int main()
{
	char dst[] = "por cima";
	char src[] = "a ser copiado";
	printf("o que esta no destino: %s\n", dst);
	printf("o que esta na fonte: %s\n", src);
	ft_strlcat(dst, src, 50);
	printf("como ficou o destino apos a funcao: %s\n", dst);
	printf("retorno da funcao, size = %zu\n", ft_strlcat(dst, src, 50));
}
*/