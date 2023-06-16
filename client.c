/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccestini <ccestini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 14:10:19 by ccestini          #+#    #+#             */
/*   Updated: 2022/06/15 11:12:34 by ccestini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<signal.h>
#include"libft/libft.h"

void	ft_sending_str_bysignals(int pid, char *message);

int	main(int ac, char *av[])
{
	int	pid;

	if (ac != 3)
	{
		write(1, "Wrong number of arguments!\n", 27);
		return (-1);
	}
	if (ft_isalldigits(av[1]) == 0)
	{
		write(1, "PID not valid!\n", 15);
		return (-1);
	}
	pid = ft_atoi(av[1]);
	if (pid <= 0)
	{
		write(1, "PID not valid! \n", 16);
		return (-1);
	}
	ft_sending_str_bysignals(pid, av[2]);
	return (0);
}

void	ft_sending_str_bysignals(int pid, char *message)
{	
	int	bitshift;
	int	i;

	bitshift = 0;
	i = 0;
	while (message[i] != '\0')
	{
		while (bitshift < 8)
		{
			if (message[i] & (128 >> bitshift))
				kill(pid, SIGUSR1);
			else
				kill(pid, SIGUSR2);
			usleep(500);
			bitshift++;
		}
		i++;
		bitshift = 0;
	}
}

/* Bitwise: a opercao eh feita da seguinte forma, qdo colocamos algum sinal
bitwise, exemplo '&' ('and' eh qdo os dois sao 1 o resultado eh 1,
senao eh 0), ou '|' ('or' eh qdo um dos dois eh 1, resultado eh 1),
ou '>>' '<<' (shift right e shift left, coloca depois a qtde de shift).
Qdo 128 >> 0, eh igual a 128. Qdo 128 >> 1, agora bit vale 64 e etc...
*/
/*
Sem usar o bitwise, ficou assim:
void    ft_sending_str_bysignals(int pid, char *message)
{
    int x = 128;
    int bits = 8;
    int i = 0;

    while (message[i] != '\0')
    {
        ft_send_one_chr_bitabit(pid, message[i]);
        i++;
    }
}

void    ft_send_one_chr_bitabit(int pid, char c)
{
    int x = 128;
    int bits = 8;
    while (bits > 0)
    {
        if (c < x)
        {
            kill(pid, SIGUSR2);
        }
        else if (c >= x)
        {
            c = c - x;
            kill(pid, SIGUSR1);
        }
        usleep(50);
        x = x/2;
        bits--;
    }
}*/
