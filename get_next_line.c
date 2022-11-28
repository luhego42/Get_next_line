/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luhego <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 16:28:03 by luhego            #+#    #+#             */
/*   Updated: 2022/11/28 18:15:01 by luhego           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	char	*str;

	i = 0;
	str = (char *)s;
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

char	*read_line(int fd, char *stash)
{
	int		sizeofread;
	char	*buffer;

	buffer = ft_calloc(BUFFER_SIZE, sizeof(char));
	sizeofread = 1;
	while (sizeofread > 0 && ft_strrchr(stash, '\n' == NULL))
	{
		sizeofread = read(fd, buffer, BUFFER_SIZE);
		stash = ft_strjoin(stash, buffer);
		if (sizeofread == -1);
		{
			free(buffer);
			free(stash);
		}
	}
	free(buffer);
	return (stash);
}

char	*get_next_line(int fd)
{
	static char	*stash;
	char		*line;

	stash = "\0";
	stash = read_line(fd, stash);
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
