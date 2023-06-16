/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccestini <ccestini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 17:40:22 by ccestini          #+#    #+#             */
/*   Updated: 2022/02/15 11:53:18 by ccestini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	while (s[len] != '\0')
		len++;
	return (len);
}
/*
Funcao conta o tamanho da string e armazena no retorno.
*/
/*
#include <stdio.h>
int	main(void)
{
	size_t	l = ft_strlen("contando");
	printf("%d", l);
}
Ou
int	main(int ac, char *av[])
{
	printf("%d\n", ft_strlen(av[1]));
}
*/