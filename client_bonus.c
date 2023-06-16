/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccestini <ccestini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 11:32:09 by ccestini          #+#    #+#             */
/*   Updated: 2022/06/16 11:32:20 by ccestini         ###   ########.fr       */
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
