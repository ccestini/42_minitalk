/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccestini <ccestini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 14:22:45 by ccestini          #+#    #+#             */
/*   Updated: 2022/02/15 11:52:37 by ccestini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putendl_fd(char *s, int fd)
{
	size_t	len;

	if (!s || !fd)
		return ;
	len = 0;
	while (s[len] != '\0')
		len++;
	write(fd, s, len);
	write(fd, "\n", 1);
}
/*
Funcao igual a putstr_fd, mas essa pula uma linha nova.
*/
/* para testar:
 int	main(void)
{
	ft_putendl_fd("mostra toda a string\n", 1);
}
*/