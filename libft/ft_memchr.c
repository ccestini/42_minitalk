/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccestini <ccestini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 00:07:16 by ccestini          #+#    #+#             */
/*   Updated: 2022/02/15 11:52:12 by ccestini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;

	i = 0;
	while (i < n)
	{
		if (((unsigned char *)s)[i] == (unsigned char)c)
			return ((unsigned char *)(s + i));
		i++;
	}
	return (0);
}
/* essa funcao localiza o caracter c, onde o caracter aparece a primeira vez
dentro da string s. O retorno eh um pointer naquele ponto onde o caracter foi
encontrado. Parecido com a funcao strchr.
A funcao strchr busca o caracter ate chegar no final em '\0', mas a memchr 
vai procurar somente ate o parametro n.
O retorno das strchr e da memchr eh o ponteiro da posicao onde o caracter foi
encontrado. Ex. "agora o menino vai embora", c = 'o', o retorno seria o
ponteiro na posicao 3, que eh o nro da posicao onde esta o primeiro 
caracter 'o' encontrado.
*/
/* teste para ver onde esta o ponteiro (sem output)
int main(void)
{
  char *r;
  char s[] = "Vamos";
  r = ft_memchr(s, 'o', 5);
  printf("%s\n", *r);
}
teste para ver onde foi o ponteiro na string
int main(void)
{
  char s[] = "Vamos";
  printf("%s\n", ft_memchr(s, 'a', 5));
}
*/
