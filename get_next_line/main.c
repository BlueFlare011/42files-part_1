#include "get_next_line.h"
#include <stdio.h>

void leaks(void)
{
	system("leaks a.out");
}

int main(){
	atexit(leaks);
	char *str;
	int fd = open("file_tester.txt", O_RDONLY);
	for (int i = 0; i < 1; i++)
	{
		str = get_next_line(-1);
		printf("%s", str);
		free(str);
	}
	close(fd);
	return 0;
}
