#include "dev.h"
void	ft_putstrarr(char **arr)
{
	while(*arr != NULL)
	{
		ft_putstr(*arr++);
		write(1, "\n", 1);
	}
}