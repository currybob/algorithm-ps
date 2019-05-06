// Sorting_PriorityQueue
/*
Insert
	새로운 노드 추가할 때, 그 노드는 반드시 맨 끝에 추가되어야 함
	그 다음 max heap property를 충족시키기 위해 정렬

	(seudo code)
	MAX-HEAP-INSERT(A, key){
		heap_size = heap_size + 1;
		A[heap_size] = key;
		i = heap_size; // 맨 끝
		while(i > 1 and A[PARENT(i)] < A[i]){
			// 루트 노드가 아니고, 현 노드가 부모 노드보다 클 때
			exchange A[i] and A[PARENT(i)];
			i = PARENT(i);
		}
	}

	시간복잡도 : O(logn)

EXTRACT_MAX()
	최댓값을 찾아서 삭제
	
	heap sort는 최댓값을 찾기에 최적화 된 알고리즘
	항상 최댓값은 루트 노드이기 때문에
	
	삭제를 간편하게 하기 위해 루트 노드와 마지막 노드를 바꿔주고
	마지막 노드를 지워주면 됨.
	대신 max heap property가 깨지기 때문에 재정렬 필요

	(seudo code)
	HEAP-EXTRACT-MAX(A)
		i heap-size[A] < 1
			then error "empty heap"
		max <- A[1]
		A[1] <- A[heap-size[A]]
		heap-size[A] <- heap-size[A] - 1
		MAX-HEAPIFY(A, 1)
		return max

		시간복잡도 : O(logn)
*/

