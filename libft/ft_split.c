/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccestini <ccestini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 12:21:52 by ccestini          #+#    #+#             */
/*   Updated: 2022/02/15 11:52:48 by ccestini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count_words(char const *s, char c);
static char	*ft_word_cpy(char const *s, int first, int last);
static void	ft_write_split(char const *s, char **split, char c);

char	**ft_split(char const *s, char c)
{
	char	**split;

	if (!s)
		return (0);
	split = (char **)malloc(sizeof(char *) * (ft_count_words(s, c) + 1));
	if (!split)
		return (0);
	ft_write_split(s, split, c);
	return (split);
}

static void	ft_write_split(char const *s, char **split, char c)
{
	size_t	i;
	size_t	j;
	int		index;

	i = 0;
	j = 0;
	index = -1;
	while (i <= ft_strlen(s))
	{
		if (s[i] != c && index < 0)
			index = i;
		else if ((s[i] == c || i == ft_strlen(s)) && index >= 0)
		{
			split[j++] = ft_word_cpy(s, index, i);
			index = -1;
		}
		i++;
	}
	split[j] = 0;
}

static int	ft_count_words(char const *s, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	if (!s)
		return (0);
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i] != '\0')
			count++;
		while (s[i] && s[i] != c)
			i++;
	}
	return (count);
}

static char	*ft_word_cpy(char const *s, int first, int last)
{
	char	*word;
	int		i;

	i = 0;
	if (!s)
		return (0);
	word = malloc((last - first + 1) * sizeof(char));
	if (!word)
		return (0);
	while (first < last)
		word[i++] = s[first++];
	word[i] = '\0';
	return (word);
}
/* 
Funcao que separa uma unica string em varias, separando a
cada char 'set' encontrado, pode ser um caracter ou espaco.
Passos: criar funcao para contar a qtde palavras
depois criar uma nova funcao para copiar cada palavra,
e por ultimo criar a funcao split.
*/
/*
#include <unistd.h>
#include <string.h>
#include <strings.h>
#include <stdio.h>
#include <stdlib.h>

int	main(void)
{
	int	i = 0;
	char	c = '*';
	char *inteira = "separa*tudo*1**2*3";
	char **r = ft_split(inteira, c);
	printf("qtde palavras: %d\n", ft_count_words(inteira, c));
	while (i < ft_count_words(inteira, c))
	{
		printf("string %d : %s\n", i, r[i]);
		i++;
	}
	free(r);
	return (0);
}
*/