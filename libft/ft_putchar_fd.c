/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccestini <ccestini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 11:12:35 by ccestini          #+#    #+#             */
/*   Updated: 2022/02/15 11:52:33 by ccestini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h" 

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}
/*
Funcao igual a funcao putchar, mas essa tem um fd a mais, 
fd eh file descriptor, entao ao inves de aparecer o standard output,
vc agora escolhe: 0 standard input, 1 standard output, 2 error.
Usamos o 1 para apenas um caracter.
*/
/*
int	main(void)
{
	ft_putchar_fd('a', 1);
}
*/