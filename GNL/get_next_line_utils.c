#include "get_next_line.h"

int	ft_strlen(const char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

char	*ft_strchr(const char *s, int c)
{
	int a;

	a = 0;
	while (s[a])
	{
		if (s[a] == c)
			return ((char*)s + a);
		a++;
	}
	if (s[a] == c)
		return ((char*)s + a);
	return (NULL);
}
char	*ft_strdup(char *src)
{
	char	*str;
	int		i;

	i = 0;
	while (src[i] != '\0')
		i++;
	if (!(str = malloc(sizeof(char) * i + 1)))
		return (0);
	i = 0;
	while (src[i] != '\0')
	{
		str[i] = src[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char		*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		j;
	char	*str;

	i = ft_strlen(s1) + ft_strlen(s2) + 1;
	if (!(str = (char*)malloc(sizeof(char) * i)))
		return (NULL);
	i = 0;
	j = 0;
	if (s1)
		while (s1[j])
			str[i++] = s1[j++];
	j = 0;
	if (s2)
		while (s2[j])
			str[i++] = s2[j++];
	str[i] = '\0';
	return (str);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;
	int		i;

	i = 0;
	if (s == NULL || (int)start >= ft_strlen(s))
		return (ft_strdup(""));
	if (!(str = malloc(sizeof(char) * (len + 1))))
		return (NULL);
	while (i != (int)len)
	{
		str[i] = s[start + i];
		i++;
	}
	str[len] = '\0';
	return (str);
}
