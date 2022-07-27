#include <stdio.h>
#include "get_next_line.h"

int main()
{
	int fd = open("pollyana.txt", O_RDONLY);
	
	for (int i = 0; i < 10; i++)
	{
		printf("%s", get_next_line(fd));
	}
	close(fd);
	return (0);
}