/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printunbr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccestini <ccestini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 13:04:00 by ccestini          #+#    #+#             */
/*   Updated: 2022/05/10 12:29:22 by ccestini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_printunbr(unsigned int n)
{
	char	*nbr;
	int		len;

	len = 1;
	nbr = "0123456789";
	if (n >= 10)
		len = len + ft_printunbr(n / 10);
	write(1, &nbr[n % 10], 1);
	return (len);
}
/*Funcao para transformar o print apenas positivos.
Depois de aprender essa funcao para hexa, adaptei essa mesma funcao para
os nros positivos.

Foi usada uma string com todas as posicoes desde o zero ate o 9.
Qdo o nro eh maior q 9 chamamos a funcao novamente (recursiva),
ate que o nro seja menor que 10. Qdo o nro finalmente for menor que 10,
a funcao comeca a escrever os caracteres, digito por digito 
da direita para esquerda.
Para negativos o nro eh transformado assim: n = 4294967295 + nb + 1;
sendo o 4294967295 o ultimo nro do unsigned entao subtrai o nb (nro
digitado negativo) e ainda somamos 1 para pular o zero caracter.

int main(void)
{
  ft_printunbr(4242);
}
*/
