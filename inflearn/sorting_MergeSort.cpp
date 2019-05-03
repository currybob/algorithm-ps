// Sorting_MergeSort
/*
(Divide and Conquer) - Merge sort, Quick sort, Heap sort
	분할 : 해결하고자 하는 문제를 작은 크기의 '동일한' 문제들로 분할
	정복 : 각각의 작은 문제를 순환적으로 해결 - 전체 문제와 동일한 방법 (Recursion)
	합병 : 작은 문제의 해를 합하여(merge) 원래 문제에 대한 해를 구함
	예) 앞서 했던 recursion 강의에서 최대값 구하는 예제 

Merge sort
	1) 데이터가 저장된 배열을 절반으로 나눔 - divide
	2) 각각을 순환적으로 정렬 - recursively sort
	3) 정렬된 두 개의 배열을 합쳐 전체를 정렬 - merge
	merge할 때, 정렬이 일어남. 
	1) 정렬된 두 배열에서 가장 작은 값들을 서로 비교. A[i]와 A[j] 중 더 작은 값을 A[k]에 저장
	2) 만약 A[i]가 A[k]에 저장되었다고 한다면, 다시 A[i+1]과 A[j]를 비교, A[k+1]에 저장
	3) i나 j가 정렬된 배열의 index를 벗어나면 중단

	(seudo code)
	mergeSort(A[], p, r){ // index p 부터 index r 까지를 정렬하는 함수
		if (p < r) then{
			q <- (p+q)/2;
			mergeSort(A, p, q); // 전반부 정렬
			mergeSort(A, q+1, r); // 후반부 정렬
			merge(A, p, q, r); // 합병
		}
	}

	merge(A[], p, q, r){
		정렬되어 있는 두 배열 A[p..q]와 A[q+1...r]을 합하여
		정렬된 하나의 배열 A[p...r]을 만든다.
	}

시간 복잡도
	T(n) = 0 , if n=1
			T([n/2]) + T([n/2]) + n , otherwise
		= O(nlogn)
*/

#include <stdio.h>

void merge(int data[], int p, int q, int r){
	int i = p, j = q + 1, k = p;
	int tmp[10]; // 넉넉히 잡기
	while (i <= q && j <= r){
		if (data[i] <= data[j])
			tmp[k++] = data[i++];
		else
			tmp[k++] = data[j++];
	}
	while (i <= q)
		tmp[k++] = data[i++];
	while (j <= r)
		tmp[k++] = data[j++];
	for (int i = p; i <= r; i++)
		data[i] = tmp[i];
}

void mergeSort(int data[], int p, int r){
	if (p < r){
		int q = (p + r) / 2;
		mergeSort(data, p, q);
		mergeSort(data, q + 1, r);
		merge(data, p, q, r);
	}
}

int main(){
	int data[10] = {34, 5, 21, 43, 1, 2, 76, 42, 28, 0};

	mergeSort(data, 0, 9);

	for (int i = 0; i < 10; i++)
		printf("%d ", data[i]);
	puts("");

	return 0;
}
