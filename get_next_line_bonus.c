

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
		return (free(leftovers[fd]), NULL);
	leftovers[fd] = ft_get_line(fd, leftovers[fd], buffer);
	free(buffer);
	buffer = NULL;
	if (!leftovers[fd])
		return (NULL);
	result = leftovers[fd];
	leftovers[fd] = ft_save_leftovers(result);
	return (result);
}
/*
 int	main(void)
 {
 	int		fd;
 	char	*next_line;
 	int		count;
 	count = 0;
 	fd = open("text.txt", O_RDONLY);
 	if (fd == -1)
 		return (1);
 	while (1)
 	{
 		next_line = get_next_line(fd);
 		if (!next_line)
 			break ;
 		count++;
 		printf("[%d] -> %s", count, next_line);
 		free(next_line);
 		next_line = NULL;
 	}
 	close(fd);
 	return (0);
 }
*/
/*
int	main(void)
{
	int		fd1;
	int		fd2;
	char	*next_line1;
	char	*next_line2;
	int		count;

	count = 0;
	fd1 = open("a.txt", O_RDONLY);
	fd2 = open("b.txt", O_RDONLY);
	if (fd1 < 0 || fd2 < 0)
		return (1);
	while (1)
	{
		next_line1 = get_next_line(fd1);
		if (!next_line1)
			break ;
		next_line2 = get_next_line(fd2);
		if (!next_line2)
		{
			free (next_line1);
			break ;
		}
		count++;
		printf("fd1 - %d -> %s", count, next_line1);
		free (next_line1);
		printf("fd2 - %d -> %s", count, next_line2);
		free (next_line2);
	}
	close(fd1);
	close(fd2);
	return (0);
}
*/
