#include "get_next_line.h"
#include <stdio.h>

void leaks(void)
{
	system("leaks a.out");
}

int main(){
	// atexit(leaks);
	int fd = open("file_manifiesto.txt", O_RDONLY);
	// int fd2 = open("file_gnl_easy.txt", O_RDONLY);
	for (int i = 0; i < 1; i++)
		printf("%s", get_next_line(fd));
	/*printf("\nNew file:\n");
	for (int i = 0; i < 2; i++)
		printf("%s", get_next_line(fd2));
	close(fd2);*/
	close(fd);
	return 0;
}
