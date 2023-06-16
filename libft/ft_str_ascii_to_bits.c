/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_ascii_to_bits.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccestini <ccestini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 13:46:27 by ccestini          #+#    #+#             */
/*   Updated: 2022/05/30 14:51:09 by ccestini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_str_ascii_to_bits(char *message);
void	ft_convert_char_to_bit(char c);

/*int main(void)
{
    char *str = "Testando conversao";
    ft_str_ascii_to_bits(str);
    return (0);
}*/

void	ft_str_ascii_to_bits(char *message)
{
	int	x;
	int	i;
	int	bits;

	x = 128;
	bits = 8;
	i = 0;
	while (message[i] != '\0')
	{
		ft_convert_char_to_bit(message[i]);
		i++;
		write(1, "\n", 1);
	}
	ft_convert_char_to_bit('\0');
	write(1, "\n", 1);
}

void	ft_convert_char_to_bit(char c)
{
	int	x;
	int	bits;

	x = 128;
	bits = 8;
	while (bits > 0)
	{
		if (c < x)
		{
			write(1, "0", 1);
		}
		else if (c >= x)
		{
			write(1, "1", 1);
			c = c - x;
		}
		x = x / 2;
		bits--;
	}
}
