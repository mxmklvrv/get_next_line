

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 55
# endif

# ifndef MAX_FD
#  define MAX_FD 1024
# endif

# include <fcntl.h> // remove, for open 
# include <stdio.h> // remove, for printf
# include <stdlib.h>
# include <unistd.h>

char	*get_next_line(int fd);
char	*ft_get_line(int fd, char *leftovers, char *buffer);
char	*ft_save_leftovers(char *full_line);

char	*ft_strdup(const char *s);
char	*ft_strchr(const char *s, int c);
char	*ft_strjoin(char const *s1, char const *s2);
size_t	ft_strlen(const char *s);

#endif
