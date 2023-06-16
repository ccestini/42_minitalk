/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccestini <ccestini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 13:37:55 by ccestini          #+#    #+#             */
/*   Updated: 2022/02/09 12:41:55 by ccestini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	first;
	size_t	last;

	if (!s1 || !set)
		return (0);
	first = 0;
	last = ft_strlen(s1);
	while (s1[first] && ft_strchr(set, s1[first]))
		first++;
	while (last > first && ft_strchr(set, s1[last]))
		last--;
	return (ft_substr(s1, first, last - first + 1));
}
/*
Funcao aloca memoria e retorna uma copia da string s1, mas sem nenhum
caracter designado na string set (no comeco e no final da string).
*/
/*
#include <stdlib.h>
#include <stdio.h>
int    main(void)
{
    char *s1 = "**oi**";
    char *set = "*";
    printf("%s\n", ft_strtrim(s1, set));
    return (0);
}
*/