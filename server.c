/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccestini <ccestini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 14:10:29 by ccestini          #+#    #+#             */
/*   Updated: 2022/06/15 13:07:42 by ccestini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<signal.h>
#include"libft/libft.h"

void	ft_received(int signal);

int	main(void)
{
	pid_t	pid;

	pid = getpid();
	ft_printf("PID: %d\n", pid);
	signal(SIGUSR1, ft_received);
	signal(SIGUSR2, ft_received);
	while (1)
		pause();
	return (0);
}

void	ft_received(int signal)
{
	static int	bits;
	static char	c;

	if (signal == SIGUSR1)
		c = c | (128 >> bits);
	bits++;
	if (bits == 8)
	{
		write (1, &c, 1);
		bits = 0;
		c = 0;
	}
}

/*
Bitwise: a opercao eh feita da seguinte forma, qdo colocamos algum sinal
bitwise, exemplo '&' ('and' eh qdo os dois sao 1 o resultado eh 1,
senao eh 0), ou '|' ('or' eh qdo um dos dois eh 1, resultado eh 1),
ou '>>' '<<' (shift right e shift left, coloca depois a qtde de shift).
Funciona assim, qdo eh enviado sinal zero, nao soma nada. Qdo eh enviado
sinal 1, soma o valor do bit ao total do caracter.
*/
/* Assim eu fiz sem o bitwise:

void    ft_received(int signal)
{
    static int size;
	static int bits8[8];
	char	c;

	if (signal == SIGUSR2)
    {
       	bits8[size] = '0';
		size++;
	}
    else if (signal == SIGUSR1)
    {
        bits8[size] = '1';
		size++;
    }
	if (size == 8)
	{
		ft_8bits_into_one_char(bits8);
		size = 0;
	}
}

char	ft_8bits_into_one_char(int str8bits[])
{
	int		x;
	int		r;
	int		bits;
	char	c;

	x = 128;
	bits = 0;
	r = 0;
	while (bits < 8)
	{
	
		str8bits[bits] -= '0';
		if (str8bits[bits] == 1)
		{
			r = r + x;
		}
		x = x / 2;
		bits++;
	}
	c = (char)r;
	write(1, &c, 1);
	return (c);
}*/
