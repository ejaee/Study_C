#ifndef __ARRAY_LIST_H__
#define __ARRAY_LIST_H__

#define TRUE	1
#define FALSE	0

/*** ArrayList의 정의 ****/
#define LIST_LEN	100
typedef int LData;	 		    // 리스트에 int형 데이터의 저장을 위한 선언

typedef struct __ArrayList
{
	LData arr[LIST_LEN];                // 데이터의 저장공간이 배열로 선언
	int numOfData;                      // 저장된 데이터의 수 기록
	int curPosition;                    // 데이터 참조위치 기록
} ArrayList;

/*** ArrayList와 관련된 연산들 ***/
typedef ArrayList List;       	  	    // List는 배열 기반 리스트임을 선언
					    // LinkedList List로 변경하면 리스트 종류가 바뀌도록 만든 

void ListInit(List * plist);           	    // 초기화
void LInsert(List * plist, LData data);     // 데이터를 저장

int LFirst(List * plist, LData * pdata);    // 첫 데이터 참조
int LNext(List * plist, LData * pdata);     // 두번째 이후 데이터 참조

LData LRemove(List * plist);                // 참조한 데이터 삭제
int LCount(List * plist);                   // 저장된 데이터 수 반환

#endif
