#include<stdio.h>
#include<fcntl.h>

#include "get_next_line.h"

int main(int argc, char **argv)
{
	char *line;
	int ret;
	int fd;
	int i = 1;

	if (argc != 2)
		return (-1);
	fd = open(argv[1], O_RDONLY);
	while((ret = get_next_line(fd, &line)) >= 0)
	{
		printf("%d : %s\n", i, line);
		free(line);
		i++;
		if (ret == 0)
			break;
	}
	close(fd);
	return (0);
}
