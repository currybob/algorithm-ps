// Sorting_QuickSort
/*
quick sort
	merge sort와 다르게 pivot을 기준으로 두 부분으로 나눠줌
	여기서는 마지막을 pivot으로 설정한다고 가정
	
	분할 : 배열을 다음과 같은 조건이 만족되도록 두 부분으로 나눈다.
		elements in lower parts <= elements in upper parts
	정복 : 각 부분을 순환적으로 정렬
	합병 : nothing to do -> pivot 앞쪽에 있는 애들은 무조건 뒤쪽에 있는 애들보다 작을것이기 때문

	(seudo code)
	quickSort(A[], p, r){
		if(p < r) then {
			q = partition(A, p, r);
			quickSort(A, p, q-1);
			quickSort(A, q+1, r); // A[q]는 pivot 자리일 것
		}
	}

	partition(A[], p, r){
		배열 A[p...r]의 원소들을 A[r]을 기준으로 양쪽으로 재배치하고
		A[r]이 자리한 위치를 return 한다.
		if A[j] >= x
			j <- j+1;
		else
			i <- i+1;
			exchange A[i] and A[j];
			j <- j+1;
	}

	partition(A[], p, r){
		x <- A[r];
		i <- p-1;
		for j <- p to r-1{
			if A[j] <= x then
				i <- i+1'
				exchange A[i] and A[j];
		}
		exchange A[i+1] and A[r];
		return i+1;
	}

시간복잡도
	- 항상 한 쪽은 0개, 다른 쪽은 n-1개로 분할되는 경우 (worst case)
		T(n) = T(0) + T(n-1) + n-1
			 = T(n-1) + n + n-1 = ... = O(n^2)
		worst case에서는 merge sort보다 quick sort가 더 느림
	- 이미 정렬된 입력 데이터 (마지막 원소를 피봇으로 선택하는 경우)
	- 항상 절반으로 분할되는 경우 (best case)
		T(n) = 2T(n/2) + O(n)
			 = O(nlogn)
		merge sort와 같아짐
	- Balanced partition?
		항상 한 쪽이 적어도 1/9 이상이 되도록 분할된다면? O(nlogn)
		따라서 극단적인 경우만 아니라면 상당히 빠른 방법임을 알 수 있음

pivot의 선택
	- 첫번째 값이나 마지막 값을 pivot으로 선택
		이미 정렬된 데이터 혹은 거꾸로 정렬된 데이터가 worst case
		현실의 데이터는 랜덤하지 않으므로 정렬된 데이터가 입력으로 들어올 가능성은 매우 높음
		따라서 좋은 방법이라고 할 수 없음
	- Median of Three
		첫번째 값과 마지막 값, 그리고 가운데 값 중에서 중간값(median)을 pivot으로 선택
		내가 선택한 pivot이 최대값이거나 최소값일 확률을 줄이자는 것
		최악의 경우 시간복잡도가 달라지지는 않음
	- Randomized Quicksort
		pivot을 랜덤하게 선택
		no worst case instance, but worst case execution
		평균 시간복잡도 O(nlogn)
*/

#include <stdio.h>

void exchange(int data[], int a, int b){
	int tmp = data[a];
	data[a] = data[b];
	data[b] = tmp;
}

int partition(int data[], int p, int r){
	int x = data[r];
	int i = p - 1;
	for (int j = p; j < r; j++){
		if (data[j] <= x){
			i += 1;
			exchange(data, i, j);
		}
	}
	exchange(data, i + 1, r);
	return i + 1;
}

void quickSort(int data[], int p, int r){
	if (p < r){
		int q = partition(data, p, r);
		quickSort(data, p, q - 1);
		quickSort(data, q + 1, r);
	}
}

int main(){
	int data[10] = {34, 5, 21, 43, 1, 2, 76, 42, 28, 0};
	
	quickSort(data, 0, 9);

	for (int i = 0; i < 10; i++)
		printf("%d ", data[i]);
	puts("");
	
	return 0;
}

