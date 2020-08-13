#include <stdlib.h>

int main(int args, char **argv)
{
	char *str;
	char *line;
	int i = 0;

	str = malloc(1000000000);
	line = malloc(123302);
	while (i < 10000)
	{
		str[i] = i - '0';
		i++;
	}
	str[i] = '\0';
	if (argv[1][0] == '1')
	{
		free(str);
		free(line);
	}
	else if (argv[1][0] != 1)
		exit(0);
	return (0);
}
