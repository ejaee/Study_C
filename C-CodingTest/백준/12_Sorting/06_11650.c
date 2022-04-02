#include <stdio.h>
#include <stdlib.h>

typedef struct _map
{
	int x;
	int y;
}	map;

int N;

void MergeTwoArea(map *p, int left, int mid, int right)
{
	int fIdx = left;
	int rIdx = mid+1;
	int i;

	map * sortArr = malloc(sizeof(map)*(right+1));
	int sIdx = left;

	while(fIdx<=mid && rIdx<=right)
	{
		if(p[fIdx].x < p[rIdx].x)
			sortArr[sIdx] = p[fIdx++];
		else if(p[fIdx].x > p[rIdx].x)
			sortArr[sIdx] = p[rIdx++];
		else
		{
			if(p[fIdx].y < p[rIdx].y)
				sortArr[sIdx] = p[fIdx++];
			else if(p[fIdx].y > p[rIdx].y)
				sortArr[sIdx] = p[rIdx++];
		}
		sIdx++;
	}

	if(fIdx > mid)
	{
		for(i=rIdx; i<=right; i++, sIdx++)
			sortArr[sIdx] = p[i];
	}
	else
	{
		for(i=fIdx; i<=mid; i++, sIdx++)
			sortArr[sIdx] = p[i];
	}

	for(i=left; i<=right; i++)
		p[i] = sortArr[i];
	
	free(sortArr);
}

void MergeSort(map *p, int left, int right)
{
	int mid;

	if(left < right)
	{
		mid = (left+right) / 2;
		MergeSort(p, left, mid);
		MergeSort(p, mid+1, right);
		MergeTwoArea(p, left, mid, right);
	}
}

int main()
{
	scanf("%d", &N);

	int idx, jdx;
//	int temp;

	map *p = (map*)malloc(sizeof(map) * N);
	idx = -1;
	while (++idx < N)
		scanf("%d %d", &p[idx].x, &p[idx].y);

	MergeSort(p, 0, N - 1);
/*	idx = -1;
	while (++idx < N-1)
	{
		jdx = idx;
		while (++jdx < N)
		{
			if (p[jdx].a < p[idx].a)
			{
				temp = p[jdx].a;
				p[jdx].a = p[idx].a;
				p[idx].a = temp;
				temp = p[jdx].b;
				p[jdx].b = p[idx].b;
				p[idx].b = temp;
			}
			else if (p[jdx].a == p[idx].a && p[jdx].b < p[idx].b)
			{
				temp = p[jdx].a;
				p[jdx].a = p[idx].a;
				p[idx].a = temp;
				temp = p[jdx].b;
				p[jdx].b = p[idx].b;
				p[idx].b = temp;
			}
			
		}
	}*/

	idx = -1;
	while (++idx < N)
		printf("%d %d\n", p[idx].x, p[idx].y);
	return 0;
}
