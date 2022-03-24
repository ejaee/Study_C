#include <stdio.h>
#include <stdlib.h>

#define MAX 110

int M, N, K;
int map[MAX][MAX] = {0, };
int visit[MAX][MAX] = {0, };
int zone_size[MAX*MAX] = {0, };

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

int count = 0;

void DFS(int x, int y)
{
    visit[x][y] = 1;

    for(int i=0; i<4; i++) {
        int nx = x+dx[i];
        int ny = y+dy[i];

        if(visit[nx][ny] == 1) continue;
        if(nx<0 || nx>=N || ny<0 || ny>=M) continue;
        if(map[nx][ny] == 0) {
            DFS(nx, ny);
            zone_size[count]++;
        }
    }
}

int compare(const void* a, const void* b)
{
    return *(int *)a - *(int *)b;
}

int main()
{
    int sx, sy, dx, dy;
    int color = 1;
    scanf("%d %d %d", &M, &N, &K);
    for(int i=0; i<K; i++) {
        scanf("%d %d %d %d", &sx, &sy, &dx, &dy);
        for(int ii=sx; ii<dx; ii++) {
            for(int jj=sy; jj<dy; jj++) {
                map[ii][(M-1-jj)] = color;
            }
        }
        color += 1;
    }

	int idx, jdx;
	idx = -1;
	while (++idx < M)
	{
		jdx = -1;
		while (++jdx < N)
			printf("%d", map[idx][jdx]);
		printf("\n");
	}

    count = 0;
    for(int i=0; i<N; i++) {
        for(int j=0; j<M; j++) {
            if(map[i][j] == 0 && visit[i][j] == 0) {
                count++;
                zone_size[count] = 1;
                DFS(i, j);
            }
        }
    }

    printf("%d\n", count);
    qsort(zone_size, count, sizeof(int), compare);
    for(int i=1; i<=count; i++)
        printf("%d ", zone_size[i]);
    printf("\n");
    return 0;
}

