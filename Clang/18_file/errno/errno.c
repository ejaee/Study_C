#include <stdio.h>
#include <errno.h>

int main()
{
	errno = E2BIG;
	perror("error meassgae");
	errno = EACCES;
	perror("error meassgae");

	return 0;
}
