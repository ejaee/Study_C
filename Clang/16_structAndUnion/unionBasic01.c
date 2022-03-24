#include <stdio.h>

typedef	union	IP_ADDR
{
	int			address;
	short		Data[2];
	unsigned char	addr[4];
}	IP;

int	main(){
	IP	ip = {0};
	ip.address = 0x41424344;
	printf("%c%c%c%c\n", ip.addr[0], ip.addr[1], ip.addr[2], ip.addr[3]);
	printf("x : %x, d : %d\n", ip.Data[0], ip.Data[0]);
	printf("x : %x, d : %d\n", ip.Data[1], ip.Data[1]);

	return 0;
}
