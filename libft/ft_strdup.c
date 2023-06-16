/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccestini <ccestini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 00:01:46 by ccestini          #+#    #+#             */
/*   Updated: 2022/02/15 11:53:06 by ccestini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *src)
{
	int		i;
	char	*dest;

	i = 0;
	dest = malloc(sizeof(char) * (ft_strlen(src) + 1));
	if (dest == 0)
		return (0);
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
/*
Funcao aloca memoria para duplicar a string s, fazer uma copia.
Retorna o ponteiro para esse local na memoria alocada.
*/
/*
#include<stdio.h>
#include<stdlib.h>
int	main()
{
	char	*test;
	char	*copia;

	test = "Teste com a memoria malloc";
	
	copia = ft_strdup(test);

	printf("%s\n", copia);
	free(copia);
}
*/