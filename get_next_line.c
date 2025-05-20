/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mklevero <mklevero@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 16:48:33 by mklevero          #+#    #+#             */
/*   Updated: 2025/05/20 15:49:42 by mklevero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char		*result;
	char		*buffer;
	static char	*leftowers;

	result = NULL;
	buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	if (BUFFER_SIZE <= 0 || fd < 0)
	{
		free(buffer);
		buffer = NULL;
		return (NULL);
	}
	result = get_line(fd, remainings, buffer); 
}

char *get_line(int fd, char *remainings, char *buffer)
{


}
