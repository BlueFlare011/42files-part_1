#include <stdio.h>
#include "get_next_line.h"

int main()
{
	int fd = open("pollyana.txt", O_RDONLY);
	char *line;
	
	for (int i = 0; i < 10; i++)
	{
		line = get_next_line(fd);
		printf("%s", line);
		free(line);
	}
	close(fd);
	return (0);
}