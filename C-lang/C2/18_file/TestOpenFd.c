#include <stdio.h>
#include <fcntl.h>

int  main()
{
	int fd;
	int fd2;

	fd = open("hello.txt", O_RDONLY);
	fd2 = open("helloo.txt", O_RDONLY);
	
	printf("%d\n", fd);
	printf("%d\n", fd2);
	return 0;
}
