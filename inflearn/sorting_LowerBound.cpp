// Sorting_ComparisonSort (정렬의 lower bound)
/*
Comparison Sort
	데이터들간의 상대적 크기관계만을 이용해서 정렬하는 알고리즘
	따라서 데이터들간의 크기 관계가 정의되어 있으면 어떤 데이터에든 적용가능 (문자열, 알파벳, 사용자 정의 객체 등)
	Bubble / Insertion / Merge / Quick / Heap sort 

Non-comparison Sort
	정렬할 데이터에 대한 사전지식을 이용 - 적용에 제한
	Bucket sort
	Radix sort

Comparison Sort - Lower bound
	입력된 데이터를 한번씩 다 보기위해서 최소 O(n)의 시간복잡도 필요
	merge sort와 heap sort 알고리즘들의 시간복잡도는 O(nlogn)
	어떤 comparison sort 알고리즘도 O(nlogn)보다 나을 수 없다.

Decision Tree
	Abstraction of any comparsion sort
	Leaf node (자식이 없는 노드) 개수 : n!
	최악의 경우 시간복잡도는 트리의 높이
	트리의 높이는 : height >= log(n!) = O(nlogn)
	(full binary tree 형태일 때, 높이는 가장 낮고 node 개수는 최다)
	decision tree의 leaf node는 n!일 것, 그러면 높이는 항상 log(n!) 보다는 높음
	그래서 O(nlogn) 보다 최선일 수는 없음
*/

