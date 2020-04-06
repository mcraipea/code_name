#include "code_name.h"

void        putstr(char *s)
{
    while (*s)
        write(1, s++, 1);
}

char		*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		j;
	int		size;
	char	*dest;

	i = 0;
	j = 0;
	if (!s1 && !s2)
		size = 0;
	else
		size = strlen(s1) + strlen(s2);
	if (!(dest = malloc(sizeof(char) * size + 1)))
		return (NULL);
	while (s1[i])
		dest[j++] = s1[i++];
	i = 0;
	while (s2[i])
		dest[j++] = s2[i++];
	dest[j] = '\0';
	return (dest);
}