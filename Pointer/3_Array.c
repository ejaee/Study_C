#include <stdio.h>

int	main()
{
	// 배열은 자료형의 연속적인 메모리 공간
	// 배열의 이름은 배열의 시작 주소가 된다
	int arr[5] = {1, 2, 3, 4, 5};

	printf("[] : %d == * : %d == &* : %d\n", arr[2], *(arr + 2), *&arr[2]);

	// 다차원 배열
	char arrr[2][3] = { 'A', 'B', 'C', 'D', 'E', 'F'};

	printf("\n다차원 배열 arrr[2][3]의 주소\n");
	printf("arrr = %x\narrr[0] = %x\narrr[1] = %x\n", arrr, arrr[0], arrr[1]);
	printf("arrr = %x\narrr[0] = %x\n&arrr[0][0] = %x\n", arrr, arrr[0], &arrr[0][0]);
	printf("arrr size = %d\narrr[0] size = %d\narrr[1] size = %d\n", \
			sizeof(arrr), sizeof(arrr[0]), sizeof(arrr[1]));
	// arrr + 1은 열의 갯수만큼 더해진다
	// 행의 시작주소 arrr[0]와 arrr[1]에 + 1을 하면 char만큼 더해진다
	// &arr[0][0] + 1 와 arr[0] + 1 둘다 char만큼 더해진다
	printf("\n&arrr[0][0] = %x\n&arrr[0][0] + 1 = %x\narrr[0] = %x\narrr[0] + 1 = %x\narrr[1] = %x\narrr[1] + 1 = %x\narrr = %x\narrr + 1 = %x", \
			&arrr[0][0], &arrr[0][0] + 1, arrr[0], arrr[0] + 1, arrr[1], arrr[1] + 1, arrr, arrr+1);

	printf("\n&arrr[0][0] = %x\n arrr[0] = %x\narrr = %x\n", &arrr[0][0], arrr[0], arrr);
	printf("\narrr = %x\narrr + 1 = %x\n*(arrr + 1) = %x\n**(arrr + 1) = %c\n", arrr, arrr+1, *(arrr+1), **(arrr+1));
	// arr[1][0] == *(*(arr + 1) + 0) = **(arr + 1)
	printf("\narrr[1][0] = %c\n*(*(arr + 1) + 0) = %c\n **(arr + 1) = %c\n", \
			arrr[1][0], *(*(arrr + 1) + 0), **(arrr + 1));

	// 3차원 배열
	char arr3[2][3][2];
	// arr3 + 1은 행과 열의 갯수만큼 더해진다
	// arr3[0] + 1
	printf("\narr3 = %x\narr3 + 1 = %x\narr3[0] + 1 = %x\narr3[0][0] + 1 = %x\narr3[0][0][0] + 1 = %x\n" \
			, arr3, arr3+1, arr3[0]+1, arr3[0][0] + 1, &arr3[0][0][0] + 1);

	// int형 배열요소 접근
	printf("\nint형 배열요소 접근\n");
	int arr1[6] = {1, 2, 3, 4, 5, 6};

	printf("arr1 = %x\n", arr1);
	printf("[]로 값 접근 = %d %d %d %d %d %d\n", \
			arr1[0], arr1[1], arr1[2], arr1[3], arr1[4], arr1[5]);
	printf("*로 값 접근 = %d %d %d %d %d %d\n", \
			*(arr1), *(arr1 + 1), *(arr1 + 2), *(arr1 + 3), *(arr1 + 4), *(arr1 + 5));
	printf("(&arr1[2])[-2] = %d\n(&arr1[2])[-1] = %d\n(&arr1[2])[0] = %d\n", \
			(&arr1[2])[-2], (&arr1[2])[-1], (&arr1[2])[0]);

	int arr2[2][3] = {1, 2, 3, 4, 5, 6};
	printf("\n2차원 배열\n");
	printf("arr2[0][0] = %d\n*arr2[0] = %d\n**arr2 = %d\n", arr2[0][0], *arr2[0], **arr2);
	printf("arr2[0][1] = %d\n*(arr2[0] + 1) = %d\n*(*arr2 + 1) = %d\n", arr2[0][1], *(arr2[0] + 1), *(*arr2) + 1);
	printf("arr2[0][2] = %d\n*(arr2[0] + 2) = %d\n*(*arr2 + 2) = %d\n", arr2[0][2], *(arr2[0] + 2), *(*arr2) + 2);

	printf("arr2[1][0] = %d\n*arr2[1] = %d\n**(arr2 + 1) = %d\n", arr2[1][0], *arr2[1], **(arr2 + 1));
	printf("arr2[1][1] = %d\n*(arr2[1] + 1) = %d\n*(*(arr2 + 1) + 1) = %d\n", arr2[1][1], *(arr2[1] + 1), *(*(arr2 + 1) + 1));
	printf("arr2[1][2] = %d\n*(arr2[1] + 2) = %d\n*(*(arr2 + 1) + 2) = %d\n", arr2[1][2], *(arr2[1] + 2), *(*(arr2 + 1) + 2));
	// 정리 : 2차원 배열에서 2차원 주소 arr에 +1를 하면 열의 갯수만큼 더해짐
	// 1차원 주소 arr[0]와 &arr[0][0]에 +1를 하면 int 만큼 더해짐!
	// 2차원에서 값을  *로 접근할 때 **(arr + 1) 와  *(*(arr + 1) + 1) 연산을 명확히 알자
	
	// <참고>
	// 만약 우리가 2차원 배열의 시작주소를 상수주소로 알고 있다면
	// int arr[2][3]일때
	// ((int (*)[3])0x12ff68)[1][2] 을 통해 값을 접근할 수 있다
}
