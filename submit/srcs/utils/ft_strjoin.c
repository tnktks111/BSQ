#include "dev.h"
char	*ft_strjoin(char *s1, char *s2, int len2)
{
	int		len1;
	char	*res;
	int		i;
	int		j;

	len1 = ft_strlen(s1);
	res = (char *)malloc(len1 + len2 + 1);
	if (!res)
		return (NULL);
	i = -1;
	while (++i < len1)
		res[i] = s1[i];
	j = 0;
	while (j < len2)
	{
		res[i + j] = s2[j];
		j++;
	}
	res[i + j] = '\0';
	free(s1);
	return (res);
}