/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccestini <ccestini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 15:25:32 by ccestini          #+#    #+#             */
/*   Updated: 2022/02/15 11:52:41 by ccestini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	char	c;

	if (n == -2147483648)
	{
		write (fd, "-2147483648", 11);
		return ;
	}
	if (n < 0)
	{
		write (fd, "-", 1);
		n = -n;
	}
	c = n % 10 + '0';
	if (n > 9)
	{
		n = n / 10;
		ft_putnbr_fd(n, fd);
	}
	write (fd, &c, 1);
}
/* 
essa funcao eh igual a putnbr e tbm tem o fd da funcao putchar_fd, 
mas essa tem um fd a mais, fd eh file descriptor, entao ao inves de 
aparecer o standard output, vc agora escolhe: 0 standard input, 
1 standard output, 2 error.
Na funcao putnbr os 3 passos foram:
1 If - Escrever o menor nro int negativo possivel, isso pq o positivo 
eh 2147483647.
2 If - Colocar o sinal correto, se caso negativo. Tbm transformar o 
retorno em positivo para continuar o terceiro if.
3 If - Agora checamos se o nro eh maior q 9. Se for menor, somente 
transforma esse unico nro em caracter ascii. Caso seja maior, alem de 
transformar em caracter tbm divide o nro por 10 e escreve o primeiro nro
depois chama a sua funcao novamente e vai escrevendo ate que o nro 
seja menor q 10 (funcao recursive).
*/
/*
int	main(void)
{
	ft_putnbr_fd(-5442, 1);
}
*/