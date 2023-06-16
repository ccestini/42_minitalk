/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccestini <ccestini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 23:36:15 by ccestini          #+#    #+#             */
/*   Updated: 2022/02/15 11:52:18 by ccestini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t	i;

	if (!dst && !src)
		return (0);
	i = 0;
	while (i < n)
	{
		((unsigned char *)dst)[i] = ((unsigned char *)src)[i];
		i++;
	}
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
/*
int main(void)
{
  char fonte[] = "Eu vou fazer o cabelo";
  char destino[] = "Tambem as unhas";
  ft_memcpy(destino, fonte, 15);
}
*/