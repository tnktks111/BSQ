#include "dev.h"
//正常動作で0,それ以外は1
int validation(char *str)
{
	char empty;
	char obstacle;
	char fill;
	int row;
	int col;
	int row_count;
	if (!check_head(str))
		return (1);
	row = str[0] - '0';
	empty = str[1];
	obstacle = str[2];
	fill = str[3];
	str = &str[5];
	col = check_size(str);
	row_count = 0;
	while(*str)
	{
		if (!check_row(str, empty, obstacle, col))
			return (1);
		str += col;
		row_count++;
	}
	return (row_count != row);
}

int is_printable(char c)
{
	if (c < 32 || c > 126)
		return (0);
	return (1);
}

int check_head(char *str)
{
	if (str[0] < '0' || str[0] > '9')
		return (0);
	if (str[0] == str[1] || str[1] == str[2] || str[2] == str[3])
		return (0);
	if (!(is_printable(str[0]) && is_printable(str[1]) && is_printable(str[2])))
		return (0);
	if (str[4] != '\n')
		return (0);
	return (1);
}

int check_size(char *str)
{
	int count;

	count = 0;
	if (*str == '\n')
		return (-1);
	while (*str && *str != '\n')
		count++;
	return (count);
}


//\nを除く一列のサイズが返り値("abc\n" -> 3)
int check_row(char *row, char empty, char obstacle, int size)
{
	int i;

	i = 0;
	while (row[i] != '\n')
	{
		if (row[i] != empty || row[i] != obstacle)
			return (0);
		i++;
	}
	if (i != size)
		return (0);
	return (1);
}