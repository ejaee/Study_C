#include "UsefulHeap.h"

void	HeapInit(Heap *ph, PriorityComp pc)
{
	ph->numOfData = 0;
	ph->comp = pc;
}

int     HIsEmpty(Heap *ph)      // 변함없음
{
    if(ph->numOfData == 0)
        return TRUE;
    else
        return FALSE;
}

int GetParentIDX(int idx)       // 변함없음
{
    return idx/2;
}

int GetLChildIDX(int idx)       // 변함없음
{
    return idx*2;
}

int GetRChildIDX(int idx)       // 변함없음
{
    return GetLChildIDX(idx) + 1;
}

// 두 개의 자식 노드 중 높은 우선순위의 자식 노드 인덱스 값 반환
int GetHiPriChildIDX(Heap *ph, int idx)
{
    // 완전 이진 트리 특성에 따라 왼쪽 노드를 기준으로 확인
    if(GetLChildIDX(idx) > ph->numOfData)       // 자식 노드 없다면(p355)
        return 0;
    else if(GetLChildIDX(idx) == ph->numOfData) // 왼쪽 하나라면
        return GetLChildIDX(idx);
    else    // 둘 다 있다면
    {
    //  if(ph->heapArr[GetLChildIDX(idx)].pr > ph->heapArr[GetRChildIDX(idx)].pr)
		if(ph->comp(ph->heapArr[GetLChildIDX(idx)], ph->heapArr[GetRChildIDX(idx)]) < 0)
			return GetRChildIDX(idx);
        else
            return GetLChildIDX(idx);
    }
}

// 힙에 데이터 저장
void    HInsert(Heap *ph, HData data)
{
    int idx = ph->numOfData+1;
    //HeapElem nelem = {pr, data};

    while (idx != 1)    //  힙 저장과정 방식에 맞게
    {
	//	if (pr < (ph->heapArr[GetParentIDX(idx)].pr))    부모가 더 크면
		if (ph->comp(data, ph->heapArr[GetParentIDX(idx)]) > 0)
		{
            ph->heapArr[idx] = ph->heapArr[GetParentIDX(idx)];  // 부모 값 넣어주고
            idx = GetParentIDX(idx);    // 부모의 인덱스를 전달하고
        }
        else
            break;
    }

    ph->heapArr[idx] = data;   // 인덱스와 값 원래 부모자리에 넣기
    ph->numOfData += 1; //  개수 측정
}

// 마지막 노드가 있어야 할 위치를 ParentLdx에 저장된 인덱스 값을 갱신해가며 찾아감
HData HDelete(Heap *ph)
{
    HData retData = ph->heapArr[1];          // 삭제할 데이터. 리턴을 위해
    HData lastElem = ph->heapArr[ph->numOfData]; // 힙의 마지막 노드 저장

    //  아래의 변수 parentIdx에는 마지막 노드가 저장될 위치정보가 담긴다
    int parentIdx = 1;  // 루트 노드가 위치 해야할 인덱스를 부여
    int childIdx;

    //  루트 노드의 `우선순위가 높은 자식 노드`를 시작으로 반복문 시작
    while (childIdx = GetHiPriChildIDX(ph, parentIdx))  // 우선순위 높은 자식노드 전>달
    {
    //  if(lastElem.pr <= ph->heapArr[childIdx].pr) // 마지막 노드와 우선순위 비교
        if (ph->comp(lastElem, ph->heapArr[childIdx]) >= 0)
			break;
        //  교체
        ph->heapArr[parentIdx] = ph->heapArr[childIdx];
        parentIdx = childIdx;   //  마지막 노드가 저장될 위치 정보를 한 레벨 내림
    }   //  반복문 탈출 하면 parentIdx에 마지막 노드 위치 정보가 저장

    ph->heapArr[parentIdx] = lastElem;  // 마지막 노드 최종 저장
    ph->numOfData -= 1; // 제거했으니까
    return retData;
}

