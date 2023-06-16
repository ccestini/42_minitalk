/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccestini <ccestini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/09 23:58:17 by ccestini          #+#    #+#             */
/*   Updated: 2022/02/15 11:52:23 by ccestini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t n)
{
	unsigned char	*d;
	unsigned char	*s;

	d = (unsigned char *)dst;
	s = (unsigned char *)src;
	if (dst == src)
		return (dst);
	if (s < d)
	{
		while (n--)
			*(d + n) = *(s + n);
		return (dst);
	}
	while (n--)
		*d++ = *s++;
	return (dst);
}
/*essa funcao eh parecida com a memmove.
Funcao memmove usa uma array temporaria, enquanto a memcpy nao.
ambas tem uma fonte src, um destino dst e o tamanho em bytes para 
colocar no lugar na memoria.
Usamos o primeiro if e '!dst' quer dizer a mesma coisa que dst[i]!=\0, 
mas soh que no todo e nao apenas em uma posicao, pois nao estamos 
usando um loop while (se fosse while o uso seria o dst[i]!=\0.
Depois enquanto a posicao for menor que n, ficamos copiando o que 
esta em src para dst e vamos incrementando (andando de posicao).
O retorno sera a string dst.

exemplos do funcionamento (outputs das duas funcoes):
Original: I am going from Delhi to Gorakhpur
Src/source: going from Delhi to Gorakhpur
Dst/destination: from Delhi to Gorakhpur
Resultado output do  memmove: I am going going from Delhi to Gorakhpur
Resultado output do memcpy: I am going going fring frhig frhirafrhir
*/
/*outro maneira de escrever o codigo mais simples:
{	char	*tmp;
	tmp = (char *)malloc(sizeof(char) * len);
	if (tmp == NULL)
		return (NULL);
	ft_memcpy(tmp, src, len);
	ft_memcpy(dst, tmp, len);
	free(tmp);
	return (dst);
}*/
/*
int main(void)
{
  char fonte[] = "Abcdefg";
  char destino[] = "Hijklmn";
  ft_memmove(destino, fonte, 15);
}
*/