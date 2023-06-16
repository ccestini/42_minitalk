/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printnbr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccestini <ccestini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 13:03:30 by ccestini          #+#    #+#             */
/*   Updated: 2022/05/10 12:29:53 by ccestini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_printnbr(int n)
{
	char	*nbr;
	int		len;

	len = 0;
	nbr = "0123456789";
	if (n == -2147483648)
	{
		write (1, "-2147483648", 11);
		return (11);
	}
	if (n < 0)
	{
		len = len + write (1, "-", 1);
		n = -n;
	}
	if (n >= 10)
		len = len + ft_printnbr(n / 10);
	len = len + write(1, &nbr[n % 10], 1);
	return (len);
}
/* 
essa funcao eh igual a putnbr e tbm tem o fd da funcao putchar_fd, 
mas essa tem um fd a mais, fd eh file descriptor, entao ao inves de 
aparecer o standard output, vc agora escolhe: 0 standard input, 
1 standard output, 2 error.
Na funcao putnbr os 3 passos foram:
1 If - Escrever o menor nro int negativo possivel, isso pq o positivo 
eh 2147483647, retorno da len eh 11.
2 If - Colocar o sinal correto, se caso negativo. Tbm transformar o 
retorno em positivo para continuar o terceiro if. Contar uma len para
o sinal.
3 If - Agora checamos se o nro eh maior q 9. Se for menor, somente 
transforma esse unico nro em caracter ascii, calcula o resto e coloca
na posicao da string. Caso seja maior que 9, alem de transformar 
em caracter tbm divide o nro por 10 e vai escrevendo ate que o nro 
seja menor q 10 (funcao recursive). Escreve a partir do digito da 
esquerda para direita 123.
*/
/*

int	main(void)
{
  int x = -2147483648;
  int y = ft_printnbr(x);
  printf("\n");
  int z = printf("%d", x);
  printf("\n");
  printf("%d", y);
  printf("\n");
  printf("%d", z);
  printf("\n");
}
*/
