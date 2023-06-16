/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccestini <ccestini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 12:48:22 by ccestini          #+#    #+#             */
/*   Updated: 2022/02/15 11:53:31 by ccestini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	i;

	i = ft_strlen(s);
	c = (char)c;
	while (i > 0 && c != s[i])
	{	
		i--;
	}
	if (c == s[i])
		return ((char *)&s[i]);
	return (0);
}
/*
Funcao quase identica a funcao strchr, mas essa r localiza a ULTIMA aparicao
 do caracter / da letra 'c' encontrada e o retorno aponta para ela.
Obs: No retorno poderia ser:
return ((char *)s + len);
*/
/*
#include<stdio.h>
int	main()
{

	char teste[] = "abc def ghi jkel";
	printf("%s\n", ft_strrchr(teste, 'e'));
}
*/