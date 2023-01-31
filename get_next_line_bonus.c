/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luhego <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 16:28:03 by luhego            #+#    #+#             */
/*   Updated: 2023/01/31 16:40:14 by luhego           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static int	ft_line_len(char *line)
{
	int	l;

	l = 0;
	while (line[l] && line[l] != '\n')
		l++;
	return (l + 1);
}

static char	*ft_strrchr(const char *s, int c)
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

static char	*ft_substr(char *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	s_len;

	if (s == NULL)
		return (0);
	s_len = ft_strlen(s);
	if (len > s_len - start)
		len = s_len - start;
	if (start >= s_len)
		return (ft_calloc(1, sizeof(char)));
	str = ft_calloc(len + 1, sizeof(char));
	if (str == NULL)
		return (NULL);
	ft_strlcat(str, &s[start], len + 1);
	free(s);
	return (str);
}

static char	*read_line(int fd, char *stash)
{
	int		sizeofread;
	char	*line;

	line = ft_calloc(BUFFER_SIZE, sizeof(char));
	sizeofread = 1;
	if (stash)
		ft_strlcat(line, stash, BUFFER_SIZE);
	while (sizeofread > 0 && ft_strrchr(line, '\n') == NULL)
	{
		sizeofread = read(fd, stash, BUFFER_SIZE);
		line = ft_strjoin(line, stash);
	}
	if (!sizeofread)
	{
		free(line);
		return (NULL);
	}
	return (line);
}

char	*get_next_line(int fd)
{
	static char	stash[1024][BUFFER_SIZE + 1];
	char		*line;
	int			line_len;
	int			i;

	line = read_line(fd, stash[fd]);
	if (!line)
		return (NULL);
	line_len = ft_line_len(line);
	i = 0;
	while (line[line_len + i])
	{
		stash[fd][i] = line[line_len + i];
		i++;
	}
	stash[fd][i] = '\0';
	line = ft_substr(line, 0, line_len);
	return (line);
}
