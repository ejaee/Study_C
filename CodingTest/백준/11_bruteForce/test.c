#include <stdio.h>

int main(){
    int num[500][500] = {0};
    int N, M, sum = 0, max = 0;
    scanf("%d %d", &N, &M);
    // scanf
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            scanf("%d", &num[i][j]);
        }
    }
    //ㅡ
    for(int i = 0; i < N; i++){
        for(int j = 0; j+3 < M; j++){
            sum = num[i][j] + num[i][j+1] + num[i][j+2] +num[i][j+3];
            if (max < sum)  max = sum;
        }
    }
    // |
    for(int j = 0; j < M; j++){
        for(int i = 0; i+3 < N; i++){
            sum = num[i][j] + num[i+1][j] + num [i+2][j] + num[i+3][j];
            if (max < sum)  max = sum;
        }
    }
    // ㅁ
    for(int i = 0; i+1 < N; i++){
        for(int j = 0; j+1< M; j++){
            sum = num[i][j] + num[i][j+1] + num[i+1][j] + num[i+1][j+1];
            if (max < sum)  max = sum;
        }
    }
    // 가로6
    for(int i = 0; i+1 < N; i++){
        for(int j = 0; j+2 < M; j++){
            // z
            sum = num[i][j] + num[i][j+1] + num[i+1][j+1] + num[i+1][j+2];
            if (max < sum)  max = sum;
            sum = num[i][j+2] + num[i][j+1] + num[i+1][j+1] + num[i+1][j];
            if (max < sum)  max = sum;
            // ㄱ ㄴ
            sum = num[i][j] + num[i][j+1] + num[i][j+2] + num[i+1][j+2];
            if (max < sum)  max = sum;
            sum = num[i][j] + num[i+1][j] + num[i+1][j+1] + num[i+1][j+2];
            if (max < sum)  max = sum;
            sum = num[i][j+2] + num[i][j+1] + num[i][j] + num[i+1][j];
            if (max < sum)  max = sum;
            sum = num[i][j+2] + num[i+1][j+2] + num[i+1][j+1] + num[i+1][j];
            if (max < sum)  max = sum;
            //ㅗㅜ
            sum = num[i][j+1] + num[i+1][j] + num[i+1][j+1] + num[i+1][j+2];
            if (max < sum)  max = sum;
            sum = num[i][j] + num[i][j+1] + num[i][j+2] + num[i+1][j+1];
            if (max < sum)  max = sum;

        }
    }

    // 세로6
    for(int i = 0; i+2 < M; i++){
        for(int j = 0; j+1 < N; j++){
            // z
            sum = num[i][j] + num[i+1][j] + num[i+1][j+1] + num[i+2][j+1];
            if (max < sum)  max = sum;
            sum = num[i][j+1] + num[i+1][j+1] + num[i+1][j] + num[i+2][j];
            if (max < sum)  max = sum;
            // ㄱㄴ
            sum = num[i][j] + num[i][j+1] + num[i+1][j+1] + num[i+2][j+1];
            if (max < sum)  max = sum;
            sum = num[i][j+1] + num[i][j] + num[i+1][j] + num[i+2][j];
            if (max < sum)  max = sum;
            sum = num[i][j] + num[i+1][j] + num[i+2][j] + num[i+2][j+1];
            if (max < sum)  max = sum;
            sum = num[i][j+1] + num[i+1][j+1] + num[i+2][j+1] + num[i+2][j];
            if (max < sum)  max = sum;
            // ㅏㅓ
            sum = num[i][j] + num[i+1][j] + num[i+2][j] + num[i+1][j+1];
            if (max < sum)  max = sum;
            sum = num[i][j+1] + num[i+1][j+1] + num[i+2][j+1] + num[i+1][j];
            if (max < sum)  max = sum;
        }
    }

    printf("%d", max);
    return 0;
}
