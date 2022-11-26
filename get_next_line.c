/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luhego <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 16:28:03 by luhego            #+#    #+#             */
/*   Updated: 2022/11/26 16:19:58 by luhego           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	char	*str;

	i = 0;
	str = (char i*)s;
	while (s[i])
		i++;
	while (i >= 0)
	{
		if (s[i] == (unsigned char)c)
			return (&str[i]);
		i--;
	}
	if ((unsigned char)c == '\0')
		return (&str[i]);
	return (0);
}

char	*get_next_line(int fd)
{
	char	*buff;
	char	*line;

	buff = malloc(sizeof(char) * 6);
	read(fd, buff, 5);
	line = buff;
	read(fd, buff, 5);
	line = line + buff;
	return (line);
}

int	main(void)
{
	int		fd;
	char	*next_line;

	fd = open("text.c", O_RDONLY);
	next_line = get_next_line(fd);
	printf("la chaine copier est = \"%s\"", next_line);
	return (0);
}
