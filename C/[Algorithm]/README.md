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
				// comparison/swap
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
		// comparison/swap
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
	
* 문제점<br>
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
	* 자료 배열의 모든 요소를 앞에서부터 차례대로 이미 정렬된 배열 부분과 비교하여 자신의 위치를 찾아 삽입함으로써 정렬을 완성하는 알고리즘
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
	// loop part
	    for(int i=1; i<n; i++){
 	        j = i;
	        // comparison/swap
	        while(j>0 && str[j] < str[j-1]){
	        temp = str[j];
	        str[j] = str[j-1];
	        str[j-1] = temp;
	        j--;
	        }
	    for(int k =0; k<n; k++)
		printf("%d ", str[k]);
	        printf("\n");
	    }
	}
  ```

* 정리<br>
	* Insertion sort는 두개의 loop(outer, inner)와 comparison/swap을 이용
	* 순서는 왼쪽부터 오른쪽 방향으로 전개
	* 맨 왼쪽 숫자를 고정하고 두번째 숫자부터 비교/swap
	* inner loop에서 j의 값은 비교 갯수를 의미
	* while문 사용 시 비교할 갯수가 남았고(j>0) 왼쪽이 오른쪽 값보다 더 클 경우(str[j] < str[j-1]) swap
	* 왼쪽보다 오른쪽 값이 더 크다면 while 실행 되지 않으면서 그자리에 본인이 들어감


[양식]
## 3. Insertion sort(삽입정렬)
* 정의<br>
* 장점<br>
* 단점<br>
* 비교횟수<br>
* 코드<br>

  ```c
  ```

* 정리<br>
