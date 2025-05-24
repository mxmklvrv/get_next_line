/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mklevero <mklevero@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 14:55:42 by mklevero          #+#    #+#             */
/*   Updated: 2025/05/23 16:11:21 by mklevero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_get_line(int fd, char *leftovers, char *buffer)
{
	ssize_t	byte_was_read;
	char	*tmp;

	byte_was_read = 1;
	while (byte_was_read > 0)
	{
		byte_was_read = read(fd, buffer, BUFFER_SIZE);
		if (byte_was_read <= 0)
			break ;
		buffer[byte_was_read] = '\0';
		if (!leftovers)
			leftovers = ft_strdup("");
		tmp = leftovers;
		leftovers = ft_strjoin(tmp, buffer);
		free(tmp);
		tmp = NULL;
		if (ft_strchr(buffer, '\n'))
			break ;
	}
	if (byte_was_read < 0)
	{
		free(leftovers);
		return (NULL);
	}
	return (leftovers);
}

char	*ft_save_leftovers(char *full_line)
{
	char	*remainings;
	char	*ptr_nl;

	ptr_nl = ft_strchr(full_line, '\n');
	if (ptr_nl)
	{
		remainings = ft_strdup(ptr_nl + 1);
		if (!remainings || *remainings == '\0')
		{
			free(remainings);
			remainings = NULL;
			return (NULL);
		}
		*(ptr_nl + 1) = '\0';
		return (remainings);
	}
	return (NULL);
}

char	*get_next_line(int fd)
{
	char		*result;
	char		*buffer;
	static char	*leftovers[MAX_FD];

	if (BUFFER_SIZE <= 0 || fd < 0 || fd >= MAX_FD)
		return (NULL);
	result = NULL;
	buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (free(leftovers[fd]), leftovers[fd] = NULL, NULL);
	leftovers[fd] = ft_get_line(fd, leftovers[fd], buffer);
	free(buffer);
	buffer = NULL;
	if (!leftovers[fd])
		return (free(leftovers[fd]), leftovers[fd] = NULL, NULL);
	result = leftovers[fd];
	leftovers[fd] = ft_save_leftovers(result);
	return (result);
}
