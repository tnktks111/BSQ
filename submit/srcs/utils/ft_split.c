#include "dev.h"
char **ft_split(char *str, int row, int col)
{
    char **words = (char **)malloc(sizeof(char *) * (row + 1));
    int i = 0;
    
	while(*str != '\n')
		str++;
	str++;
    while (i < row)
    {
        words[i] = (char *)malloc(sizeof(char) * (col + 1));
        int j = 0;
        while(j < col && *str != '\n' && *str != '\0')
            words[i][j++] = *str++;
        words[i][j] = '\0'; // 文字列の終端
        if (*str == '\n') str++;
        i++;
    }
    words[i] = NULL;
    return (words);
}