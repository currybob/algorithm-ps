// DAG (Directed Acyclic Graph)
/*
DAG
	DAG는 방향 사이클(directed cycle)이 없는 방향 그래프
	(자기 자신으로 되돌아올 수 없음)
	예: 작업들의 우선순위

위상정렬 (topological ordering)
	DAG에서 노드들의 순서화 v1, v2, .... vn, 단 모든 edge (vi, vj)에 대해서 i < j가 되도록
	(indegree : 노드로 들어오는 엣지, outdegree : 노드에서 나가는 엣지)
	indegree가 0인 노드들 순서대로 진행.
	노드에 들어가게 되면 outdegree들을 지워줌

	(seudo code)
	topologicalSort1(G){
		for <- 1 to n {
			진입간선이 없는 임의의 정점 u를 선택한다; // indegree를 계산?
			A[i] <- u;
			정점 u와 u의 진출간선을 모두 제거한다;
		}
		배열 A[1,...,n]에는 정점들이 위상정렬되어 있다.
	}	

	수행시간 : O(n+m)

	topologicalSort2(G){
		for each v included in V
			visited[v] <- NO;
		make an empty linked list R;
		for each v included in V
			if(visited[v] == NO) then
				DFS-TS(v, R);
	}

	DFS-TS(v, R){
		visited[v] <- YES;
		for each x adjacent to v do
			if(visited[x] == NO) then
				DFS-TS(X, R);
		add v at the front of the linked list R;
	} // 알고리즘이 끝나면 연결리스트 R에는 정점들이 위상정렬된 순서로 매달려 있다.

	수행시간 : O(n+m)
*/

