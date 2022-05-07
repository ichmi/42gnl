#include <stdio.h>
#include <fcntl.h>
#include "get_next_line.h"

int main()
{
	// Single fd
	// int fd = open("files/f0", O_RDONLY);
	// char *p = get_next_line(fd);
	// while (p)
	// {
	// 	printf("%s", p);
	// 	free(p);
	// 	p = get_next_line(fd);
	// }
	// free(p);
	// close(fd);

	// Multiple fds
	int		fd1 = open("files/f1", O_RDONLY);
	int		fd2 = open("files/f2", O_RDONLY);
	int		fd3 = open("files/f3", O_RDONLY);
	char	*p;

	for (int i=0; i < 3; ++i)
	{
		p = get_next_line(fd1);
		printf("%s", p);
		free(p);
		p = get_next_line(fd2);
		printf("%s", p);
		free(p);
		p = get_next_line(fd3);
		printf("%s", p);
		free(p);
	}
	close(fd1);
	close(fd2);
	close(fd3);
	return (0);
}
