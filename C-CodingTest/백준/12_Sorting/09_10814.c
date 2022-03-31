#include <stdio.h>
#include <stdlib.h>

typedef struct _member
{
	int age;
	char name[100];
} member;

int N;

int compare(const void* first, const void* second)
{
	member *a = (member *)first;
	member *b = (member *)second;

	return (a->age > b->age ? 1 : a->age < b->age ? -1 : 0);
}

int main()
{
	scanf("%d", &N);

	int temp;
	int idx, jdx;
	member *list;
	
	list = (member *)malloc(sizeof(member) * N);
	idx = -1;
	while (++idx < N)
		scanf(" %d %s", &list[idx].age, list[idx].name);

	qsort(list, N, sizeof(list[0]), compare);

	idx = -1;
	while (++idx < N)
		printf("%d %s\n", list[idx].age, list[idx].name);

}
