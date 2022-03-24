#include <stdio.h>
#include <string.h>

int main() {
	int input;
	scanf("%d", &input);
	int value = 666;

	for(int idx = 0; idx != input; value++){
		char str[8];
		sprintf(str, "%d", value);
        if (strstr(str, "666") != NULL)
            idx++;
    }
	--value;
	printf("%d\n", value);

  return 0;
}
