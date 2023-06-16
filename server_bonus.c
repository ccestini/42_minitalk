/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccestini <ccestini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 11:21:25 by ccestini          #+#    #+#             */
/*   Updated: 2022/06/16 11:31:27 by ccestini         ###   ########.fr       */
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
