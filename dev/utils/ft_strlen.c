#include "dev.h"

int	ft_strlen(char *str)
{
	char *tail = str;
	while (*tail)
	{
		tail++;
	}
	return (tail - str);
}
