# Sorting_ Algorithms
## 1. Bubble sort(버블정렬)

<img src="https://user-images.githubusercontent.com/87407504/134512932-0dd23696-0146-4d3a-a726-ba26768067e2.gif" width="400" height="210">

* 정의<br>
	* 인접한 두 항목의 값을 비교해서 일정한 기준을 만족하면 서로의 값을 교환하여 정렬하는 방식<br>
	* 왼쪽을 시작으로 우측방향 순으로 두 짝을 비교하며 왼쪽의 값이 더 클 경우 swap을 반복<br>
	* outer loop를 돌때마다 가장 큰 값이 오른쪽으로 순차적으로 쌓임<br>
* 장점<br>
	* 개념이 단순해서 프로그래밍 하기 쉽다
* 단점<br>
	* 비교대상이 너무 많아서 연산시간이 오래 걸린다

* 비교횟수<br>
	* n번의 경우<br> 
	(n-1)+(n-2)+...+1<br>
	= n* (n-1)/2<br>
* 코드<br>

  ```c
	#include <stdio.h>
	int main(){
	int str[]={10, 40, 50, 20, 30};
	int n = 5;
	int temp;
	// loop part
		for(int i=0; i< n-1; i++){
			for(int j=0; j< n-1-i; j++){
				// 비교 swap
				if(str[j] > str[j+1]){
				temp = str[j];
				str[j] = str[j+1];
				str[j+1] = temp;
				}
			}
		}
		for(int i =0; i< n; i++)
			printf("%d ", str[k]);
			printf("\n");
	}
  ```

* 정리<br>
	* bubble sort는 두개의 loop(outer, inner)와 비교/swap을 이용
	* loop를 통해 서로 인접한 두개의 숫자를 비교
	* n개의 숫자 중 인접하는 숫자의 짝은 n-1이므로 outer loop에서 i< n-1
	* outer loop를 한번 돌면 가장 큰 숫자가 오른쪽에 위치, 즉 숫자 위치가 정해진다
	* inner loop는 숫자 위치가 정해지는 것을 고려하여 j< n-1-i
	* 반복횟수가 증가할 때마다 비교 횟수는 감소한다

## 2. Selection sort(선택정렬)

<img src="https://user-images.githubusercontent.com/87407504/134513057-a845cf3c-e5bf-40d1-89dc-745820756de5.gif" width="400" height="210">

* 정의<br>
	* 제일 작은 숫자를 찾아(select) 맨 왼쪽 위치로 이동(swap)하는 방식
	* 왼쪽의 값을 최솟값으로 정하고 나머지 숫자 중 더 작은 최솟값이 있다면 자리 swap
	* outer loop를 돌때마다 가장 작은 값이 왼쪽으로 순차적으로 쌓임
* 장점<br>
	* 직관적인 코드로 프로그래밍 하기 쉬움
	* 정렬을 위한 비교 횟수는 많지만 교환 횟수는 적음
	* 교환이 많이 이루어져야하는 자료 상태에서 가장 효율적
	* 내림차순으로 정렬되어 있는 자료를 오름차순으로 재정렬 시 최적의 효율
* 단점<br>
	* 버블정렬과 동일하게 비교가 많아 비효율적
	* 이미 정렬된 상태에서 소수의 자료가 추가됨으로 재정렬 시 최악의 처리속도
* 비교횟수<br>

* 코드<br>

  ```c
	#include <stdio.h>
	int main(){
	int str[]={10, 40, 50, 20, 30};
	int n = 5;
	int temp, min;
	// loop part
		for(int i=0; i<n-1; i++){
			min = i;
			for(int j=i+1; j< n; j++){
				// 비교
				if(str[min]> str[j])
				min = j;
			}
			// swap
			temp = str[i];
			str[i] = str[min];
			str[min] = temp;
		}
		for(int i =0; i< n; i++)
			printf("%d ", str[i]);
			printf("\n");
    }
  ```
  
* 정리<br>
	* Selection sort는 두개의 loop(outer, inner)와 비교/swap을 이용
	* 맨 왼쪽 숫자를 min으로 설정 하고 나머지 숫자들과 비교
	* n개의 숫자 중 min을 제외한 나머지 숫자는 n-1개 이므로 outer loop에서 i< n-1
	* 맨 왼쪽 숫자와 나머지 숫자를 비교해야 하므로 j = i+1로 시작
	* j가 i의 값에 따라 커지므로 j< n
	* 설정한 min값보다 더 작은 최소값이 있다면 서로 자리 swap
	
* 코드문제<br>
	* 한번의 outer loop 마다 무조건 swap 발생
	* min값이 바뀌지 않는다면 min(i)값에 min(i)값을 넣는 것은 비효율 적임
* 해결방법<br>

  ```c
	// flag를 정의
	int flag ; 
	
	// min값이 바뀌었을 때 flag = 1이라는 값을 부여
	if(str[min]> str[j])
	min = j;
	flag = 1;

	//flag = 1일 경우에만 swap 발동
	if(flag = 1){
	//swap
	temp = str[i];
	str[i] = str[min];
	str[min] = temp;
	}
  ``` 

## 3. Insertion sort(삽입정렬)

<img src="https://user-images.githubusercontent.com/87407504/134513124-5dea28e2-7b97-430b-9f7b-303ac372e6ac.gif" width="400" height="210">

* 정의<br>
	* 자료 배열의 모든 요소를 앞에서부터 차례대로 이미 정렬된 배열 부분과 비교하여 자신의 우치를 찾아 삽입함으로써 정렬을 완성하는 알고리즘
	* 두 번째 자료부터 시작하여 그 앞의 자료들과 비교하여 삽입할 위치를 지정한 후 자료를 뒤로 옮기고 지정한 자리에 자료를 삽입하여 정렬하는 알고리즘
	* 여러장의 카드를 정리된 상태로 가지고 있다가 새로운 카드를 끼워 넣는 것과 유사
	* 두 번째 자료는 첫 번째, 세 번째 자료는 두 번째와 첫 번째 자료와 비교한 후 자료가 삽입될 위치를 찾음
	* 삽입될 위치를 찾았다면 그 위치에 자료를 삽입하기 위해 자료를 한 칸씩 뒤로 이동
* 장점<br>
	* 안정적인 정렬 방법
	* 다른 복잡한 정렬 방법보다 유리
	* 이미 레코드들이 정렬된 상태에서 소수의 자료가 추가됨으로 재정렬 시 매우 효율적
* 단점<br>
	* 비교적 많은 레코드들의 이동을 포함
	* 레코드 수가 많고 레코드 크기가 클 경우 부적합

* 비교횟수<br>
	* 이동 없이 1번의 비교만 이루어짐
	* 최선의 경우 : outer loop = (n-1)번
	* 최악의 경우 : outer loop = n* (n-1)/2
* 코드<br>

  ```c
	#include <stdio.h>
	int main(){
	int str[]={50, 40, 10, 20, 30};
	int n = 5;
	int temp, j;
	// loop part 맨 왼쪽 고정, 두번째부터 시작
		for(int i=1; i<n; i++){
			j = i;
			//judgment
			while(j>0 && str[j] < str[j-1]){
			//swap 왼쪽것이 오른쪽보다 더 클때 swap해야지
			temp = str[j];
			str[j] = str[j-1];
			str[j-1] = temp;
			// 비교 1회 종료
			j--;
			}
			for(int k =0; k<n; k++)
				printf("%d ", str[k]);
				printf("\n");
		}
	}
  ```

* 정리<br>
	* Insertion sort는 두개의 loop를 가지는데 inner loop로 비교하여 swap
	* 시작은 맨 왼쪽은 고정하고 두번째부터 시작
	* i는 j에게 두번째 숫자를 부여하고 inner로 진입
	* j는 비교 갯수를 의미하기위해 while 조건으로 j>0를 부여
	* 첫번째 자리보다 두번째 자리가 더 큰 숫자가 와야 하므로 두 자리 수를 비교
	* 왼쪽이 더 클 경우 swap 해야 하므로 while 조건으로 str[j] < str[j-1]
	* 비교할 갯수가 남았고 첫번째 값이 두번째 값보다 클 경우 while 발동 - swap
	* swap이 끝나면 비교 갯수를 줄여야 하므로 j--
	* 비교 값(오른쪽 값)이 왼쪽 값보다 작을 경우 while을 반복하고 클 경우 비교 종료

## 4. Merge sort(합병정렬)

* 정의<br>
	* 분할정복법
		* 분할(Divide) : 데이터가 저장된 배열을 절반으로 나눔
		* 정복(Conquer) : 각각을 순환적으로 정렬
		* 합병 : 정렬된 두개의 배열을 합쳐(merge) 전체를 정렬
	* 두개의 정렬된 list를 합쳐서 하나의 정렬된 list로 만들어줌
	* 두개의 정렬된 list는 오(내)름차순으로 정렬된 상태
	* 각각의 최소(대)값을 차례대로 비교하여 저장될 추가 배열상에 정렬
	* 정렬된 추가 배열의 값을 원래의 배열로 재정렬
	* 다시말해 A그릇을 a1와 a2로 나누고 각각 정렬하여 B에 정렬한 후 다시 A로 옮김
* 장점<br>
	* 무조건 절반으로 분할하기 때문에 동일한 시간 복잡도를 가짐
* 단점<br>
	* 추가적인 메모리가 필요함
* 시간복잡도<br>
	* T(n) if n = 1; 0
	       otherwise; 2T(n/2)+n
* 코드<br>

  ```c
	#include <stdio.h>
	// sort(a[], b, c) --> a[b, ..., c]을 정렬한다
	void mergesort(int str[], int p, int r);
	void merge(int str[], int p, int q, int r);
	int main(){
		int str[8]={5,4,1,2,3,8,6,7};
		
		mergesort(str, 0, 7);
		for(int i =0; i< 8; i++)
			printf("%d ", str[i]);
		return 0;
		}
	
	void mergesort(int str[], int p, int r){
		int q;
		if(p < r){
			q = (p+r)/2;
			mergesort(str, p, q);
			mergesort(str, q+1, r);
			merge(str, p, q, r);
		}
	}
	
	void merge(int str[], int p, int q, int r){
		int i =p, j=q+1, k=p;
		int tmp[8];
		while(i<=q && j<=r){
			if(str[i] <= str[j]) tmp[k++] = str[i++];
			else tmp[k++] = str[j++];
		}
		while(i<=q) tmp[k++] = str[i++];
		while(j<=r) tmp[k++] = str[j++];
		for(int a = p; a<=r; a++) str[a] = tmp[a];
	}
  ```

* 정리<br>
	* 두개의 함수를 이용해 정렬
	* 분할정복법을 사용(분할 - 정복 - 합병)
	* 함수 1) mergesort
		* 1개가 될때까지 잘반으로 나눔
		* 나눌게 있을때까지(if(p < r)) 절반으로 나눔(q = (p+r)/2)
		* 함수 1안에 함수 2포함
	* 함수 2) merge
		* mergesort를 통해 나누어진 상태로 시작
		* 새로 정렬받을 배열을 설정(tmp[8])
		* 나누어진 배열 중 두개씩 비교(p~q, q+1~r)
		* 각각 i와 j를 정의하고 마지막인 q와 r보다 높아지면 끝
		* 비교 시작은 첫번째인 p와 q+1(i=p, j=q+1)
		* 오른쪽 배열의 값이 크면 tmp그릇에 왼쪽 값 전달
		* 왼쪽 배열의 값이 크면 tmp그릇에 오른쪽 값 전달
		* 어느 한 배열이 비교할 값이 끝나면 while-1 끝
		* 왼쪽 갯수만 남았을 경우 while-2로 tmp 전달(오른쪽 --> while3)
		* for문을 통해 새로운 그릇 tmp에서 원래 그릇 str로 전달
		* i와 k는 같은 p 값을 받는데 i는 나누어진 한 배열의 시작값으로 비교에 사용, k는 tmp의 시작값으로 왼쪽부터 값을 전달받는데 사용

## 5. Quick sort(빠른정렬)
* 정의<br>
	* 합병정렬과 같은 분할정복법
		* 분할 : 배열을 다음과 같은 조건이 만족되도록 두 부분으로 나눈다
			특정 조건을 통해 기준 값(pivot)을 설정하고 pivot을 통해
			작은 값 큰 값을 나눈다
			
			>파티션(partition)
			
		* 정복 : 각 부분을 순환적으로 정렬한다
		* 합병 : nothing to do
		* Pivot 값을 첫번째 값이나 마지막 값으로 선택하는 것은 좋은 방법이 아니다
			- 현실의 데이터는 랜덤하지 않기 때문
			- 소프트웨어를 만들때 이미 다른 소프트웨어로 인해 처리되는 경우가 많은데 사전 단계에서 정렬된 상태에서 데이터가 들어오는 경우가 많음 따라서 pivot을 처음이나 마지막 수로 설정할 경우 최소, 최대값이 되어 최악의 경우가 된다
			- 첫번째 값과 마지막 값, 그리고 그 가운데 값 중에서 중간값을 pivot으로 설정하는 경우가 좋다
			- Randomized Quicksort도 흔히 쓰인다
* 장점<br>
	* 빠르게 정렬하는 방법으로 가장 많이 사용됨
	*
* 단점<br>
* 비교횟수<br>
	* 파티션하는데 걸리는 시간 : O(n), 데이터의 갯수가 n개일 때 n-1번의 연산
	* T(n) // 합병정렬처럼 반반으로 나눠지는 것이 아닌, pivot값에 따라 바뀐다
		* 최악의 경우 : pivot이 최대,최소값이되어 쏠리는 경우 n-1개와 pivot으로 나뉨 --> T(n) = n(n-1)/2 = 0(n* n)
		* 최선의 경우 : pivot이 항상 절반으로 분할되는 경우 merge sort와 같다 --> T(n) = 2t(n/2)+ 0(n) = 0(nlogn)
		* Balanced_P : 	
		
			>이후에 다시 적을 것 인프런 '40 
* 코드<br>

  ```c
	#include <stdio.h>
	void QuickSort(int arr[], int left, int right);
	int main(void) {
		int data[10] = { 5, 4, 1, 9, 3, 8, 6, 7, 10, 2 };
		printf(" --정렬 전 순서--\n"); //정렬하기 전 상태 출력.
		for (int i = 0; i < 10; i++) {
			printf("%d ", data[i]);
		}
		printf("\n\n");
		QuickSort(data, 0, 9);
		printf(" --정렬 후 순서--\n"); //정렬한 후 상태 출력.
		for (int i = 0; i < 10; i++) {
			printf("%d ", data[i]);
		}
		printf("\n");
		return 0;
	}
	//함수 정의
	void QuickSort(int arr[], int left, int right) {
		int L = left, R = right;
		int temp;
		int pivot = arr[(left + right) / 2]; //중간값을 pivot으로 설정
		printf("L : %d / pivot : %d / R : %d\n", L, (left + right)/2, R); //데이터 확인 부분.
		//아래의 while문을 통하여 pivot 기준으로 좌, 우 크고 작은 값 나열. = Partition
		while (L <= R) {
		//pivot이 중간 값이고, 비교 대상 arr[L], arr[R]은 pivot과 비교하니 중간 지점을 넘어가면 종료.
			while (arr[L] < pivot) //left부터 증가하며 pivot 이상 값을 찾음.
			L++;
			while (arr[R] > pivot) //right부터 감소하며 pivot 이하 값을 찾음.
			R--;
			//L, R 모두 최대 pivot 위치까지 이동.
			if (L <= R) { //현재 L이 R이하면. (이유 : L>R 부분은 이미 정리가 된 상태임).
			if (L != R) { //같지 않은 경우만.
				temp = arr[L];
				arr[L] = arr[R];
				arr[R] = temp;
			} //L과 R이 같다면 교환(SWAP)은 필요 없고 한 칸씩 진행만 해주면 됨.
			L++; R--; //그리고 L,R 한 칸 더 진행.
			for (int i = 0; i < 10; i++) { //데이터 확인 부분.
				printf("%d ", arr[i]);
			}
			printf("\n");
			}
		}
		printf("\n");
		//조건 확인하여 재귀함수로.
		printf("QuickSort 재귀 호출 확인(만족 시 호출)\n1.left : %d < R : %d \n2.right : %d > L : %d\n\n", left, R, right, L); //데이터 확인 부분.
		if (left < R)
			QuickSort(arr, left, R);
		if (L < right)
			QuickSort(arr, L, right);
	}
  ```

* 정리<br>
	* 중간값을 pivot으로 설정하고 진행
	* 분할정복법을 사용(mergesort와 다르게 합병은 하지않음)
	* QuickSort 함수를 거치고 재귀함수 사용
	* 양끝쪽부터 pivot까지 왼(오른)쪽은 pivot보다 작으(크)면 게속이동
	* 이동이 멈추면 swap이 필요하다는 것을 의미
	* swap의 조건은 L와 R이 pivot을 지나가지 않으면서 서로 같지 않을 떄 swap
	* swap이 되었다면 L와 R 한칸 씩 이동 이후 pivot을 지나갈 때 까지 진행
	* 위 조건이 완료되었다면 순환적으로 정렬하기 위해 PIvot을 기준으로 나누어 재귀함수로 진입
	* 하나하나 나누어질 때 까지 재귀함수 진행하면 정렬 완료
	
[양식]
## 6. Quick sort(합병정렬)
* 정의<br>
	*
* 장점<br>
* 단점<br>
* 비교횟수<br>
* 코드<br>

  ```c
	#include <stdio.h>
	void mergesort(int str[], int p, int r);
	void merge(int str[], int p, int q, int r);
	int main(){
		int str[8]={5,4,1,2,3,8,6,7};
		// 분할 - 정복 - 정렬
		mergesort(str, 0, 7);
		for(int i =0; i< 8; i++)
			printf("%d ", str[i]);
		return 0;
		}
	//
	void mergesort(int str[], int p, int r){
		int q;
		if(p < r){
			q = (p+r)/2;
			mergesort(str, p, q);
			mergesort(str, q+1, r);
			merge(str, p, q, r);
		}
	}
	void merge(int str[], int p, int q, int r){
		int i =p, j=q+1, k=p;
		int tmp[8];
		while(i<=q && j<=r){
			if(str[i] <= str[j]) tmp[k++] = str[i++];
			else tmp[k++] = str[j++];
		}
		while(i<=q) tmp[k++] = str[i++];
		while(j<=r) tmp[k++] = str[j++];
		for(int a = p; a<=r; a++) str[a] = tmp[a];
	}
  ```

  * 정리<br>