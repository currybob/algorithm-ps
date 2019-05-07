// Graph
/*
(무방향) 그래프 G = (V, E)
	V : 노드(node) 혹은 정점(vertex)
	E : 노드쌍을 연결하는 edge 혹은 link
	개체(object)들 간의 이진관계를 표현
	n = |V|, m = |E|

방향 그래프(Directed Graph) G = (V, E)
	edge (u, v)는 u로부터 v로의 방향을 가짐

가중치(weighted) 그래프
	edge마다 weight가 지정

인접행렬 (adjacency matrix)
	nxn 행렬 A = (a_ij), where a_ij = {1 if (i, j) include in E, 0 otherwise}
	저장공간 : O(n^2)
	어떤 node v에 인접한 모든 노드 찾기 : O(n) 시간
	어떤 edge (u, v)가 존재하는지 검사 : O(1) 시간

인접리스트 (adjacency list)
	정점 집합을 표현하는 하나의 배열과
	각 정점마다 인접한 정점들의 연결 리스트
	저장 공간 : O(n+m)
	어떤 node v에 인접한 모든 노드 찾기 : O(degree(v)) 시간
	(최악의 경우 degree(v) = n - 1 / 인접행렬보다 유리)
	어떤 edge (u, v)가 존재하는지 검사 : O(degree(u)) 시간
	(v에 연결된 리스트들을 다 확인해줘야 함 / 인접행렬보다 불리)

방향 그래프 의 경우
	인접행렬은 비대칭
	인접리스트는 m개의 노드를 가짐

가중치 그래프의 인접행렬 표현
	edge의 존재를 나타내는 값으로 1대신 edge의 가중치를 저장
	edge가 없을 때 혹은 대각선 :
		특별히 정해진 규칙은 없으며, 그래프와 가중치가 의미하는 바에 따라서
		예: 가중치가 거리 혹은 비용을 의미하는 경우라면 edge가 없으면 infinite, 대각선은 0
		예: 만약 가중치가 용량을 의미한다면 edge가 없을 때 0, 대각선은 infinite

경로와 연결성
	무방향 그래프 G = (V, E)에서 노드 u와 노드 v를 연결하는 경로가 존재할 때, v와 u는 서로 연결되어 있다고 말함
	모든 노드 쌍들이 서로 연결된 그래프를 connected 그래프라고 한다.
	연결요소(connected component)
*/

