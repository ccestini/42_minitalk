/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printhexa_lower.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccestini <ccestini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 12:25:17 by ccestini          #+#    #+#             */
/*   Updated: 2022/05/10 12:30:08 by ccestini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_printhexa_lower(unsigned int n)
{
	char	*hexa;
	int		len;

	len = 0;
	hexa = "0123456789abcdef";
	if (n >= 16)
		len = len + ft_printhexa_lower(n / 16);
	len = len + write(1, &hexa[n % 16], 1);
	return (len);
}
/*Funcao para transformar o nro decimal em hexadecimal.
Foi usada uma string com todas as posicoes desde o zero ate o 15 para todos
os caracteres usados em hexa.
Qdo o nro eh maior ou igual a 16 chamamos a funcao novamente (recursiva),
ate que o nro seja menor que 16. Qdo o nro finalmente for menor que 16,
a funcao comeca a escrever os caracteres, digito por digito 
da direita para esquerda.
Para negativos o nro eh transformado assim: n = 4294967295 + nb + 1;
sendo o 4294967295 o ultimo nro do unsigned entao subtrai o nb (nro
digitado negativo) e ainda somamos 1 para pular o zero caracter.

int main(void)
{
  ft_printhexa_lower(438);
}
*/
