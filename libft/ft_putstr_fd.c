/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccestini <ccestini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 12:04:34 by ccestini          #+#    #+#             */
/*   Updated: 2022/02/09 13:10:53 by ccestini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstr_fd(char *s, int fd)
{
	size_t	len;

	if (!s || !fd)
		return ;
	len = 0;
	while (s[len] != '\0')
		len++;
	write(fd, s, len);
}
/* para testar:
 
int	main(void)
{
	ft_putstr_fd("mostra toda a string\n", 1);
}

essa funcao eh igual a ft_putstr, mas com fd file descriptor 
(que pode ser: 0 input, 1 output, 2 error).
Qdo na chamada jah aparece o pointer de s, 
na funcao de writer podemos colocar somente s (sem &) e 
ele vai mostrar toda a string e depois na qtde de caracteres, 
como nao sabemos, podemos colocar a strlen.

Entao qdo colocamos a string e a fd 1, eh mostrada 
a string toda na tela como parametro.
*/
