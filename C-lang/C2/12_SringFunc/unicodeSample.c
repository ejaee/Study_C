#include <stdio.h>
#include <wchar.h>
int	main(){

	wchar_t	*p = L"String";
	wchar_t dest[32];
	wchar_t *test = L"testing";

	swprintf(dest, 32, L"%s", p);		//error!
	wprintf(L"%s\n", dest);				//error!!
	wprintf(test);
	return 0;
}
