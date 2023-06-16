/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccestini <ccestini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 23:47:00 by ccestini          #+#    #+#             */
/*   Updated: 2022/02/15 12:01:57 by ccestini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		((unsigned char *)s)[i] = '\0';
		i++;
	}
}
/* essa funcao serve para apagar a memoria anterior, assim como memset, 
mas no caso do bzero vc nao escolhe o q colocar no lugar, vc simplesmente
coloca zeros.
Entao a funcao chama a memset e no caracter sera sempre zero.

Poderia ser escrita apenas assim:
void	ft_bzero(void *s, size_t n)
{
	ft_memset(s, '\0', n);
}
*/
/*para testar, na funcao principal tem q alterar
- void *s para char *s
- size_t n para int n

int main(void)
{
  char s[] = "Vamos";
  ft_bzero(s, 3);
  printf("%s\n", s);
}
*/