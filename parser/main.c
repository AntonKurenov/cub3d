#include <stdio.h>
#include <fcntl.h>

int main(void)
{
	int fd;
	char *name = "map.pub";

	if ((fd = open(name, O_RDONLY)) == -1)
	{
		printf("fd = %d\n", fd);
		return (0);
	}
	return (0);
}
