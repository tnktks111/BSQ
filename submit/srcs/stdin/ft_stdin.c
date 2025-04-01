#include "dev.h"
int	get_input(char *input)
{
	int		i;
	int		bytes_read;
	char	ch;

	i = 0;
	bytes_read = read(0, &ch, 1);
	while (bytes_read > 0 && i < BUF_SIZE - 1)
	{
		if (ch == '\n' || ch == '\0')
			break;
		if (i >= BUF_SIZE - 1)
			return (0);
		input[i++] = ch;
		bytes_read = read(0, &ch, 1);
	}
	input[i] = '\0';
	return (1);
}