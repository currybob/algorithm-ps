// BFS_Graph Traversal (그래프 순회)
/*
그래프 순회
	순회(traversal)
	그래프의 모든 노드들을 방문하는 일

대표적 2가지 방법
	BFS (Breadth-First Search, 너비우선순회)
	DFS (Depth-First Search, 깊이우선순회)

BFS
	BFS 알고리즘은 다음 순서로 노드들을 방문
		L0 = {S}, 여기서 S는 출발 노드
		L1 = L0의 모든 이웃 노드들
		L2 = L1의 이웃들 중 L0에 속하지 않는 노드들
		:
		Li = L_i-1의 이웃들 중 L_i-2에 속하지 않는 노드들

큐를 이용한 BFS
	1. check the start node; // visited
	2. insert the start node into the queue;

(seudo code)
	while the queue is not empty do
		remove a node v from queue;
		for each unchecked neighbour w of v do
			check and insert w into the queue;

	BFS(G, S)
		Q <- 0;
		Enqueue(Q, S);
		while Q != 0 do
			u <- Dequeue(Q)
			for each v adjacent to u do
				if v is unvisited then
					mark v as visited;
					Enqueue(Q, V);
				end
			end
		end

BFS와 최단경로
	S에서 Li에 속한 노드까지의 최단 경로의 길이는 i이다.
	(여기에서 경로의 길이는 경로에 속한 edge의 개수를 의미한다.)
	BFS를 하면서 각 노드에 대해서 최단 경로의 길이를 구할 수 있다.
	입력 : 방향 혹은 무방향 그래프 G=(V, E), 그리고 출발노드 S
	출력 : 모든 노드 V에 대해서
	d[V] = S로부터 V까지의 최단 경로의 길이 (edge의 개수)
	pi[V] = S로부터 V까지의 최단 경로상에서 V의 직전 노드 (predecessor)

	(seudo code)
	BFS(G, S)
		Q <- 0;
		d[S] <- 0;
		pi[S] <- null;
		Enqueue(Q, S);
		while Q != 0 do
			u <- Dequeue(Q)
			for each v adjacent to u do
				if v is unvisited then
					mark v as visited;
					d[v] <- d[u] + 1; // 보통 모든 노드들에 대해 d[v] = -1로 초기화해두고, -1이면 unvisited, 0이면 visited
					pi[v] <- u;
					Enqueue(Q, V);
				end
			end
		end

	시간복잡도 : O(n+m) with adjacent list / O(n^2) with adjacent matrix

	printPath(G, S, V)
		if V == S then
			print S;
		else if pi[V] == NULL then
			print 'no path from s to v exists';
		else
			printPath(G, S, pi[V]);
			print V;

BFS 트리
	각 node v와 pi[V]를 연결하는 edge들로 구성된 트리
	BFS 트리에서 S에서 V까지의 경로는 S에서 V까지 가는 최단경로
	어떤 edge도 2개의 layer를 건너가지 않는다.
	(동일 레이어의 노드를 연결하거나, 혹은 1개의 layer를 건너간다.)

*** 그래프가 disconnected 이거나 혹은 방향 그래프라면 BFS에 의해서 모든 노드가 방문되지 않을 수도 있음

BFS를 반복하여 모든 노드 방문
	(seudo code)
	BFS-ALL(G)
		while there exists unvisited node V
			BFS(G, V);
*/

