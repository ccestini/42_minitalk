/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccestini <ccestini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 11:41:28 by ccestini          #+#    #+#             */
/*   Updated: 2022/02/15 11:53:36 by ccestini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	j;
	char	*sub;

	if (!s)
		return (0);
	if (start > ft_strlen(s) || len <= 0)
		return (ft_strdup(""));
	if (len <= ft_strlen(s))
		sub = (char *)malloc((len + 1) * sizeof(char));
	else
		sub = (char *)malloc(sizeof(char) * (ft_strlen(s) + 1 - start));
	if (!sub)
		return (0);
	i = start;
	j = 0;
	while (j < len && i < ft_strlen(s))
		sub[j++] = s[i++];
	sub[j] = '\0';
	return (sub);
}
/*
Funcao aloca memoria e retorna uma copia de apenas uma parte da string s.
Cria uma substring do ponto start ate o len.
size_t i eh o counter.
*/
/*
#include<stdio.h>
int main()
{
  char *s = "toda a frase completa";
  int start = 5;
  int len = 21;
  char *nova = ft_substr(s, start, len);
  printf("%s\n", nova);
}
*/