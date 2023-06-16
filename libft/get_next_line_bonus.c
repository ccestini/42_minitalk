/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccestini <ccestini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 17:49:15 by ccestini          #+#    #+#             */
/*   Updated: 2022/05/10 12:39:41 by ccestini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*get_next_line(int fd);
char	*ft_gnl_read_file(int fd, char *str);

char	*get_next_line(int fd)
{
	static char	*str[256];
	char		*line;

	if (fd < 0 || fd > 256 || BUFFER_SIZE <= 0)
		return (NULL);
	str[fd] = ft_gnl_read_file(fd, str[fd]);
	if (!str[fd])
		return (NULL);
	line = ft_gnl_get_line(str[fd]);
	str[fd] = ft_gnl_get_remain(str[fd]);
	return (line);
}

char	*ft_gnl_read_file(int fd, char *str)
{
	int		i;
	char	*remain;
	char	*buffer;

	i = 1;
	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	while (i > 0)
	{
		i = read(fd, buffer, BUFFER_SIZE);
		if (i == -1)
		{
			free(buffer);
			return (NULL);
		}
		remain = str;
		buffer[i] = '\0';
		str = ft_gnl_join(remain, buffer);
		if (ft_gnl_hasline(str) >= 1)
			break ;
	}
	free(buffer);
	return (str);
}
/*
#include<stdio.h>
#include<fcntl.h>

// testando bonus part com loop
int	main(void)
{
  	char	*line;
	int	file3 = open("file3.txt", O_RDONLY);
	int	file4 = open("file4.txt", O_RDONLY);
	int z = 1;
	int y = 1;

	while (file3)
	{
		line = get_next_line(file3);
		if(!line)
			break ;
		printf("fd = %d and line[%d] = %s", file3, z, line);
		z++;
		free(line);
	}
	while (file4)
	{
		line = get_next_line(file4);
		if(!line)
			break ;
		printf("fd = %d and line[%d] = %s", file4, y, line);
		y++;
		free(line);
	}
	close(file3);
	close(file4);
	return (0);
}*/