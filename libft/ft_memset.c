/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccestini <ccestini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/09 23:53:29 by ccestini          #+#    #+#             */
/*   Updated: 2022/02/15 11:52:28 by ccestini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		((unsigned char *)s)[i] = c;
		i++;
	}
	return (s);
}
/*Essa funcao escreve por cima do que esta gravado na memoria,
algum valor que vc escohe como int c e apenas na qtde escolhida em n (nao
ate o final \0.
Usamos um cast, esse '(unsigned char *), para transformar a string void s.
Cast = converter uma variavel em outro tipo de variavel.
O loop while comeca em i eh zero e vai adicionando ate chegar em i igual a n.
O retorno eh a primeira posicao de s.
*/
/*para testar, na funcao principal tem q alterar
- void *s para char *s
- size_t n para int n

int main(void)
{
  char s[] = "Vamos";
  ft_memset(s, 'a', 3);
  printf("%s\n", s);
}
*/