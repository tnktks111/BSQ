#include "dev.h"
int main(int argc, char *argv[])
{
	int i = 1;
	char input[BUF_SIZE];

	if (argc == 1)
	{
		get_input(input);
		if (parse(input))
			ft_putstr_error("map error\n");
	}
	if (argc > 1)
	{
		while (i < argc)
			if (parse(argv[i++]))
				ft_putstr_error("map error\n");
	}
	return (0);
}