#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <limits.h>

char *get_next_line(int fd);
int	ft_strlen(const char *str);
char	*ft_strchr(const char *s, int c);
char	*ft_strdup(char *src);
char		*ft_strjoin(char const *s1, char const *s2);
char	*ft_substr(char const *s, unsigned int start, size_t len);
