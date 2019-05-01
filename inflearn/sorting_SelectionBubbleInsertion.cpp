// Sorting_basic
/*
Bubble sort, Insertion sort, Selection sort, Quick sort, Merge sort, Heap sort, Radix sort

(오름차순 정렬)
Selection Sort 
	1) 가장 큰 값을 찾는다.
	2) 가장 큰 값과 맨 마지막 값을 자리를 바꾼다.
	3) 맨 마지막 값이 가장 큰 값이 될 것.
	4) 나머지 값들에 대해 똑같이 반복.
	
	(seudo code) - O(n^2)
	selectionSort(A[], n){
		for last <- n downto 2{
			A[1...last] 중 가장 큰 수 A[k]를 찾는다;
			A[k] <-> A[last];
		}
	}

Bubble Sort
	가장 큰 값을 맨 마지막으로 보낸다는 점에서 Selection sort와 유사 
	1) 자기 다음값과 비교해서 내가 더 크면 둘이 자리를 바꿈
	2) 계속 진행하다보면 그 중 제일 큰 값이 맨 마지막 자리에 오게 됨

	(seudo code) - O(n^2)
	BubbleSort(A[], n){
		for last <- n down to 2{
			for i <- 1 to last-1
				if(A[i] > A[i+1]) then A[i] <-> A[i+1];
		}
	}

Insertion Sort
	첫번째 데이터는 1개니까 정렬되어있다고 보고 
	두번째 데이터부터 데이터를 추가할 때마다 재정렬 해준다는 생각
	k번째 데이터를 추가해줄 때 이미 k-1번째까지 잘 정렬된 데이터 사이에 어떻게 잘 끼워넣을 수 있을까?
	앞에서부터 비교하는 것은 비효율적! 비교 뿐만이 아니라 비교 후 배열안에서 재정렬 할 때 뒤에 것들까지 다 봐줘야 함
	뒤에서부터 비교하면 비교 & 재정렬이 동시에 일어나므로 좀 더 효율적
	1) k-1과 k 비교 후 k보다 k-1의 값이 더 크면 k-1값을 뒤로 보냄 (k번째 자리로)
	이 과정을 더 이상 큰 값이 나타나지 않을때까지 반복
	최악의 경우는 Selection, Bubble sort와 비슷하지만 평균적으로 조금 더 빠름 

	(seudo code) - O(n^2)
	InsertionSort(A[], n){
		for i <- 2 to n {
			A[1...i]의 적당한 자리에 A[i]를 삽입한다.
		}
	}
*/
