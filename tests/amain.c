#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>
#include <string.h>

// int	main(int argc, char **argv)
// {
// 	int		file_count;
// 	int		files[file_count + 1];
// 	int		active_count;
// 	char	file_is_active[file_count];
// 	char	*line;

// 	file_count = argc - 1;
// 	if (argc > 1)
// 	{
// 		for (int i = 0; i < file_count; i++)
// 			files[i] = open(argv[i + 1], O_RDONLY);
// 	}
// 	else
// 	{
// 		files[0] = 0;
// 		file_count = 1;
// 	}
// 	active_count = file_count;
// 	memset(file_is_active, 1, sizeof(file_is_active));
// 	for (int i = 0; active_count > 0; i = (i + 1) % file_count)
// 	{
// 		if (file_is_active[i])
// 		{
// 			line = get_next_line(files[i]);
// 			if (line == NULL)
// 			{
// 				file_is_active[i] = 0;
// 				active_count--;
// 			}
// 			else
// 			{
// 				printf("%s", line);
// 				free(line);
// 			}
// 		}
// 	}
// }

int	main(void)
{
	int		fd;
	char	*next_line;
	int		count;

	count = 0;
	fd = open("sailor_moon.txt", O_RDONLY);
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
