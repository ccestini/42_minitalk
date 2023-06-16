/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccestini <ccestini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 14:08:46 by ccestini          #+#    #+#             */
/*   Updated: 2022/02/15 11:52:59 by ccestini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	c = (char)c;
	while (s[i] != '\0' && c != s[i])
		s++;
	if (c == s[i])
		return ((char *)s);
	return (0);
}
/* essa funcao localiza o caracter c, onde o caracter aparece a primeira vez
dentro da string s. O retorno eh um pointer naquele ponto onde o caracter foi
encontrado. Parecido com a funcao memchr.
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
  r = ft_strchr(s, 'o');
  printf("%s\n", r);
}
teste para ver onde foi o ponteiro na string
int main(void)
{
  char s[] = "Vamos";
  printf("%s\n", ft_strchr(s, 'o'));
}
*/