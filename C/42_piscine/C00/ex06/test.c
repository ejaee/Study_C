#include <unistd.h>

void	putchar(char	c)
{
	write(1, &c, 1);
}

void	putarr(int n, int* arr, int com)	// 받은 arr를 출력하고 comma 찍는 함수
{
	int idx;

	idx = 0;
	while (idx < n)				// 보내진 arr의 내용 출력하기
	{
		putchar(arr[idx] + '0');
		idx++;
	}

	if (com == 1)				// comma 출력
	{
		putchar(',');
		putchar(' ');
	}
}

void	putplus(int n, int *arr)	// 일의 자리수가 9가되어 다음 자리수를 올려줘
{
	int	i;							// idx
	int	m;

	i = n - 1;		// 오름차순 이니까 n-1부터 시작
	m = 9;
	while (arr[i] == m)				// 어느 자리수를 올려줘야하는지 기준설정
	{
		i--;
		m--;
	}
	arr[i] +=1;		// idx설정이 되었으니 해당 idx의 값에 +1
	while (i < n)
	{
		arr[i+1] = arr[i] + 1;	// +1해준 값 오른쪽 숫자들도 초기값 리셋팅
		i +=1;
	}
}

void	ft_print_combn(int	n)
{
	int arr[10];
	int idx;			// 배열의 인덱스 배열

	idx = 0;
	while (idx < n)		// 초기값을 셋팅함
	{
		arr[idx] = idx;
		idx++;
	}
	putarr(n, arr, 1);	// 셋팅값을 출력 by func putarr
	while (arr[0] != 10-n)		// n이 3이라면 마지막은 789, 즉 10-3 = 7은 한번나옴
	{
		if (arr[n-1] != 9)		// 배열 끝자리가 9일때까지 하나씩 1씩 올린다
			arr[n-1] += 1;
		else
			putplus(n, arr);	// 배열 끝자리가 9, 다음 초기값을 셋팅해준다
		if (arr[0] == 10-n){
			putarr(n, arr, 0);
			return;
		}
		putarr(n, arr, 1);		// 내용 출력하기 + comma
	}
}

int	main(){
	ft_print_combn(3);
	return 0;
}
