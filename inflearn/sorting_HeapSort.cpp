// Sorting_ HeapSort
/*
heap sort
	최악의 경우 시간복잡도 O(nlogn)
	sorts in place : 추가 배열 불필요
	binary heap 자료 구조를 사용

heap
	complete binary tree이면서
	heap porperty를 만족해야 함

	binary trees
		하나의 parent가 최대 2개의 child를 가질 수 있는 tree
		- full binary trees
			모든 레벨에 노드들이 꽉 차 있는 형태
		- complete binary trees
			마지막 레벨을 제외하면 완전히 꽉 차있고,
			마지막 레벨에는 가장 오른쪽부터 연속된 몇 개의 노드가 비어있을 수 있음

	heap property
		- max heap property -> 이거라고 가정!
			부모는 자식보다 크거나 같다
		- min heap property
			부모는 자식보다 작거나 같다

		동일한 데이터를 가진 여러 heap이 존재할 수 있음.

	heap은 1차원 배열로 표현 가능
		루트 노드 A[1]
		A[i]의 부모 = A[i/2]
		A[i]의 왼쪽 자식 = A[2i]
		A[i]의 오른쪽 자식 = A[2i+1]

		기본 연산 : Max-Heapify
		전체를 힙으로 만들어라!
		트리의 전체 모양은 complete binary tree
		왼쪽 subtree는 그 자체로 heap이고 오른쪽 subtree 그 자체로도 heap일 때
		유일하게 루트만이 heap property를 만족 안하는 경우
		>> 두 자식들 중 더 큰 쪽이 나보다 크면 exchange 한다.

		(seudo code)
		// recursive version
		MAX-HEAPIFY(A, i){
			if there is no child of A[i]
				return;
			k <- index of the biggest child of i;
			if A[i] >= A[k]
				return;
			exchange A[i] and A[k];
			MAX-HEAPIFY(A, k);
		} // root 노드에 대한 heapify는 MAX-HEAPIFY(1)을 호출하면 됨

		// iterative version
		MAX-HEAPIFY(A, i){
			while A[i] has a child do
				k <- index of the biggest child of i;
				if A[i] >= A[k]
					return;
				exchange A[i] and A[k];
				i = k;
		}

		시간복잡도 : o(logn)

정렬할 배열을 힙으로 만들기
	(seudo code)
	Build-Max-Heap(A){
		heap-size[A] <- length[A]
		for i <- round(length[A]/2) down to 1
			do MAX-HEAPIFY(A, i)
	}

	시간복잡도 : O(n)

오름차순 정렬
	heap sort의 한 가지 확실한 것은 최대값이 루트에 있다는 것
	따라서 heap 정렬을 완료할때마다 루트값을 배열의 마지막으로 보내줌

	(seudo code)
	HEAPSORT(A){
		BUILD-MAX-HEAP(A)
		for i <- heap_size downto 2 do
			exchange A[1] <-> A[i]
			heap_size <- heap_size - 1
			MAX-HEAPIFY(A, 1)
	}

	시간복잡도 : O(nlogn)
*/

