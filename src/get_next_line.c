/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brdani <brdani@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 04:45:02 by brdani            #+#    #+#             */
/*   Updated: 2024/11/25 17:43:45 by brdani           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_join_free(char *stash, char *buffer)
{
	char	*tmp;

	tmp = ft_strjoin(stash, buffer);
	free(stash);
	return (tmp);
}

char	*read_fd(int fd, char *stash)
{
	char	*buffer;
	int		bt;

	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (buffer == NULL)
		return (NULL);
	bt = 1;
	while (bt > 0)
	{
		bt = read(fd, buffer, BUFFER_SIZE);
		if (bt == -1)
		{
			free (stash);
			free (buffer);
			stash = NULL;
			buffer = NULL;
			return (stash);
		}
		buffer[bt] = '\0';
		stash = ft_join_free(stash, buffer);
		if (ft_strchr(stash, '\n'))
			break ;
	}
	free (buffer);
	return (stash);
}

char	*extract_line(char *stash)
{
	int		i;
	char	*str;

	i = 0;
	if (!stash[i])
		return (NULL);
	while (stash[i] && stash[i] != '\n')
		i++;
	str = ft_calloc(i + 2, sizeof(char));
	i = 0;
	while (stash[i] && stash[i] != '\n')
	{
		str[i] = stash[i];
		i++;
	}
	if (stash[i] && stash[i] == '\n')
	{
		str[i] = '\n';
		i++;
	}
	return (str);
}

char	*clean_line(char *stash)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	j = 0;
	while (stash[i] && stash[i] != '\n')
		i++;
	if (!stash[i] || (stash[i] == '\n' && !stash[i + 1]))
	{
		free (stash);
		return (NULL);
	}
	str = ft_calloc(ft_strlen(stash) - i + 1, sizeof(char));
	while (stash[++i])
		str[j++] = stash[i];
	str[j] = '\0';
	free (stash);
	return (str);
}

char	*get_next_line(int fd)
{
	static char	*stash;
	char		*line;

	if (fd < 0 || BUFFER_SIZE < 0)
		return (NULL);
	if (!stash)
		stash = ft_calloc(1, (sizeof(char)));
	stash = read_fd(fd, stash);
	if (!stash)
		return (NULL);
	line = extract_line(stash);
	stash = clean_line(stash);
	return (line);
}
