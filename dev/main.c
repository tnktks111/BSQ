int main(int argc, char *argv[])
{
	int i = 1;
	if (argc > 1)
	{
		while (i < argc)
			if (parse(argv[i++]))
				ft_error();
	}
	return (0);
}