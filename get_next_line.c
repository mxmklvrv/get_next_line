/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mklevero <mklevero@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 16:48:33 by mklevero          #+#    #+#             */
/*   Updated: 2025/05/21 19:28:51 by mklevero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_get_line(int fd, char *leftovers, char *buffer)
{
	ssize_t	byte_was_read;
	char	*tmp;

	byte_was_read = 1;
	while (byte_was_read > 0)
	{
		byte_was_read = read(fd, buffer, BUFFER_SIZE);
		if (byte_was_read == 0)
			break ;
		else if (byte_was_read < 0)
		{
			free(leftovers);
			return (NULL);
		}
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
		if (*remainings == '\0')
		{
			free(remainings);
			remainings = NULL;
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
	static char	*leftovers;

	result = NULL;
	buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	if (BUFFER_SIZE <= 0 || fd < 0)  // might check if fd is closed as well.
	{
		free (leftovers);
		free(buffer);
		leftovers = NULL;
		buffer = NULL;
		return (NULL);
	}
	result = ft_get_line(fd, leftovers, buffer);
	free(buffer);
	buffer = NULL;
	if (!result)
		return (NULL);
	leftovers = ft_save_leftovers(result);
	return (result);
}

int	main(void)
{
	char	*line;
	int		fd;

	fd = open("text.txt", O_RDONLY);
	
	// while ((line = get_next_line(fd)) != NULL)
	// {
	// 	printf("Line: %s, %d ", line, );
	// 	free(line);
	// 	close(fd);
	// }
	// close(fd);

	line = get_next_line(fd);
	printf("Line: %s\n", line);
	free(line);
	close(fd);

	// // line = get_next_line(fd);
	// // printf("Line: %s\n", line);
	// // free(line);
	return (0);
	
}

// int	main(void)
// {
// 	int		fd;
// 	char	*next_line;
// 	int		count;

// 	count = 0;
// 	fd = open("text.txt", O_RDONLY);
// 	if (fd == -1)
// 		return (1);
// 	while (1)
// 	{
// 		next_line = get_next_line(fd);
// 		if (!next_line)
// 			break ;
// 		count++;
// 		printf("[%d] -> %s", count, next_line);
// 		free (next_line);
// 		next_line = NULL;
// 	}
// 	close(fd);
// 	return (0);
// }


// int	main(void)
// {
// 	int		fd;
// 	char	*next_line;
// 	int		count;

// 	count = 0;
// 	fd = open("text.txt", O_RDONLY);
// 	if (fd == -1)
// 		return (1);
// 	while (1)
// 	{
// 		next_line = get_next_line(fd);
// 		if (!next_line)
// 			break ;
// 		count++;
// 		printf("[%d] -> %s", count, next_line);
// 		free (next_line);
// 		next_line = NULL;
// 	}
// 	close(fd);
// 	return (0);
// }