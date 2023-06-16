/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccestini <ccestini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 16:39:22 by ccestini          #+#    #+#             */
/*   Updated: 2022/02/15 11:53:46 by ccestini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h" 

int	ft_atoi(const char *str)
{
	unsigned long	c;
	unsigned long	r;
	long			s;

	c = 0;
	r = 0;
	s = 1;
	while ((str[c] == ' ') || (str[c] == '\t') || (str[c] == '\r')
		|| (str[c] == '\n') || (str[c] == '\v') || (str[c] == '\f'))
		c++;
	if ((str[c] == '-') || (str[c] == '+'))
	{
		if (str[c++] == '-')
			s *= -1;
	}
	while ((str[c] >= '0') && (str[c] <= '9'))
		r = (str[c++] - '0') + (r * 10);
	if (r > 2147483648 && s == -1)
		return (0);
	if (r > 2147483647 && s == 1)
		return (-1);
	return (r * s);
}
/*a funcao pega uma string de caracteres e converte a parte que contem 
caracteres nros em int nros.
Foram criadas 3 variaveis: 
c para ser a posicao dentro da string, 
s para ser o resultado do sinal, positivo ou negativo,
r para ser o resultado que sera usado no return.
Primeiro fazemos um  while e vamos passando por todos os white spaces.
Segundo, no if, fazemos o colocar o sinal negativo se tiver.
Terceiro, transformamos o caracter nro em nro de verdade e assim vai
pulando para o proximo nro, ate acabarem os nros sequenciais.
Por ultimo o retorno eh o resultado dos nros com o sinal negativo ou
sem sinal, no caso de positivo.
*/
/*
#include<stdio.h>
int main()
{
	int	s = ft_atoi(" -1234ab567");
	printf("%d\n", s);
}
*/
