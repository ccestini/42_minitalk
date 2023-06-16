/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccestini <ccestini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 13:48:09 by ccestini          #+#    #+#             */
/*   Updated: 2022/02/15 11:53:27 by ccestini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (*needle == '\0')
		return ((char *)haystack);
	while (haystack[i] != '\0' && i < len)
	{
		j = 0;
		while (haystack[i + j] == needle[j] && needle[j] != '\0'
			&& (i + j < len))
			j++;
		if (needle[j] == '\0')
			return ((char *)haystack + i);
		i++;
	}
	return (0);
}
/*
Funcao procura uma palavra no texto todo e retorna o ponteiro na
primeira letra da palavra. Procura ate 'len'.
*/
/*
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
	if (argc > 0)
		printf("%s\n", ft_strnstr(argv[1], argv[2], atoi(argv[3])));
}
*/