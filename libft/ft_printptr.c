/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printptr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccestini <ccestini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 13:03:49 by ccestini          #+#    #+#             */
/*   Updated: 2022/05/10 12:29:38 by ccestini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_printhexa_ptr(unsigned long long int n)
{
	char	*hexa;
	int		len;

	len = 0;
	hexa = "0123456789abcdef";
	if (n >= 16)
		len = len + ft_printhexa_ptr(n / 16);
	len = len + write(1, &hexa[n % 16], 1);
	return (len);
}

int	ft_printptr(void *p)
{
	int	len;

	write(1, "0x", 2);
	len = 2;
	len = len + ft_printhexa_ptr((unsigned long long)p);
	return (len);
}
/*
int main()
{
  void  *p;
  
  int x = -254141;
  p = &x;
  ft_printptr(p);
  printf("\n");
  printf("%p", p);
  printf("\n");
 }
 */
