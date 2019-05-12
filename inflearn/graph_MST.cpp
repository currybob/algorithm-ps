// Graph_MinimumSpanningTree(최소비용신장트리)
/*
MST
	입력 : n개의 도시, 도시와 도시를 연결하는 도로 비용
	문제 : 최소의 비용으로 모든 도시들이 서로 연결되게 한다.
			해가 유일하지는 않음.

무방향 가중치 그래프 G=(V,E)
	각 edge (u,v)에 대해서 가중치 W(u,v)
	문제: 다음과 같은 조건을 만족하는 edge들의 부분집합 T를 찾아라. (유일해 아니기 때문)
		1. T에 속한 edge들에 의해 그래프의 모든 정점들이 서로 연결된다.
		2. 가중치의 합이 최소가 된다.

왜 트리라고 부르는가?
	싸이클이 없는 연결된 무방향 그래프를 트리라고 부른단.
	MST 문제의 답은 항상 트리가 됨. 왜?
	노드가 n개인 트리는 항상 n-1개의 edge를 가짐
	cycle이 존재할 수 없음 (노드 중복연결이기 때문 - 가중치 합 최소에 어긋남)

Generic MST 알고리즘
	어떤 MST의 부분집합 A에 대해서 A U {(u,v)}도 역시 어떤 MST의 부분집합이 될 경우
	edge(u,v)는 A에 대해서 안전하다(safe)고 한다.

	1. 처음에는 A는 공집합이다.
	2. 집합 A에 대해서 안전한 edge를 하나 찾은 후 이것을 A에 더한다.
	3. edge의 개수가 n-1개가 될 때까지 2번을 반복한다.

	(seudo code)
	GenericMST(G, w)
		A <- 0
		while A does not form a spanning tree
			do find an edge (u, v) that is safe for A
				A <- A U {(u, v)}
		return A

안전한 edge 찾기
	그래프의 정점들을 두 개의 집합 S와 V-S로 분할한 것을 cut(S, V-S) 라고 부른다.
	edge (u, v)에 대해서 u가 S에 속하고, v는 V-S에 속할 때, edge (u,v)는 cut(S, V-S)을 cross한다고 말한다.
	edge들의 부분집합 A에 속한 어떤 edge도 cut(S, V-S)를 cross하지 않을 때 cut(S, V-S)는 A를 respect 한다고 말한다.
	>> A가 어떤 MST의 부분집합이고, (S, V-S)는 A를 존중하는 cut이라고 하자.
		이 cut을 cross하는 edge들 중 가장 가중치가 작은 edge (u,v)는 A에 대해서 안전하다.

kruskal의 알고리즘
	1. edge들을 가중치의 오름차순으로 정렬한다.
	2. edge들을 그 순서대로 하나씩 선택해간다.
		(단, 이미 선택된 edge들과 cycle을 형성하면 선택하지 않는다.)
	3. n-1개의 edge가 선택되면 종료한다.

사이클 검사
	초기 상태 : 선택된 edge 없음
	각각의 연결요소를 하나의 집합으로 표현

	(seudo code)
	MST-Kriscal(G,w)
		A <- 0
		for each vertex v included in V[G]
			do MAKE-SET(v)
		sort the edges of E into nondecreasing order by weight w
		for each edge (u, v) included in E, taken in nondecreasing order by weight
			do if FIND-SET(u) != FIND-SET(v)
				then A <- A U {(u,v)}
					UNION(u,v)
		return A

서로소인 집합들의 표현
	각 집합을 하나의 트리로 표현
	집합의 각 원소들이 트리의 노드가 됨. 누가 루트이고 누가 누구의 부모이든 상관없음.
	트리의 각 노드는 자식노드가 아닌 부모 노드의 주소를 가짐 (상향식 트리)
	(그 주소가 자기 노드와 같으면 루트 노드)
	> 모든 트리를 하나의 배열로 표현 (상향식 트리라 가능)

FIND-Set(v)
	자신이 속한 트리의 루트를 찾음

	(seudo code)
	FIND-Set(x)
		if x != p[x]
			then p[x] <- FIND-Set(p[x])
		return p[x]

	시간복잡도 : O(h), h는 트리의 높이 / 최악의 경우 : O(n)

	Union(u,v)
		한 트리의 루트를 다른 트리의 루트의 자식 노드로 만듦

	(suedo code)
	UNION(u,v)
		x <- FIND-Set(u);
		y <- FIND-Set(v);
		p[x] <- y;

	시간복잡도 : 루트 노드를 찾은 이후에는 O(1), 하지만 루트를 찾는데 O(h)

	시간복잡도 향상시키기
		weighted union
			트리의 높이를 가능한 낮게 유지하기 위해!
			두 집합을 union할 때 작은 트리의 루트를 큰 트리의 루트의 자식으로 만듦.
			(여기서 크기란 노드의 개수)
			각 트리의 크기(노드의 개수)를 카운트하고 있어야 함

		(seudo code)
		WeightedUnion(u,v)
			x <- FIND-Set(u);
			y <- FIND-Set(v);
			if size[x] > size[y] then
				p[x] <- y;
				size[x] <- size[x] + size[y];
			else
				p[y] <- x;
				size[y] <- size[y] + size[x];

		시간복잡도 : O(logn)

		path compression
		루트 노드를 찾아 올라가면서 지나간 노드들을 루트의 밑에 자식으로 갖다 붙여버림
		FIND-Set-PC(x)
			while x != p[x] do
				p[x] <- p[p[x]];
				x <- p[x];
			end
			return p[x]

		weighted union with path compression (WUPC)
			M번의 union-find 연산의 총 시간복잡도는 O(N+MlogN). 여기서 N은 원소의 개수
			거의 선형시간 알고리즘, 즉 한 번의 Find 혹은 Union이 거의 O(1)시간

			시간복잡도
				Initialize	O(1)
				First for loop	|v| MAKE-SETs
				Sort E	O(|E|log|E|)
				Second for loop	O(|E|) FIND-SETs and UNIONS
				>> O(|E|log|E|)

Prim의 알고리즘
	임의의 노드를 출발노드로 선택
	출발 노드를 포함하는 트리를 점점 키워감.
	매 단계에서 이미 트리에 포함된 노드와 포함되지 않은 노드를 연결하는 edge들 중 
	가장 가중치가 작은 edge를 선택

	가중치가 최소인 edge 찾기
		V_A : 이미 트리에 포함된 노드들
		V_A 에 속하지 않은 각 노드 v에 대해서 다음과 같은 값을 유지
			key(v) : 이미 V_A에 속한 노드와 자신을 연결하는 edge들 중 가중치가 최소인 edge (u,v)의 가중치
			pi(v) : 그 edge (u,v)의 끝점 u
		>> 가중치가 최소인 edge를 찾는 대신 key값이 최소인 노드를 찾는다. (시간복잡도 감소)
		   매번 k를 새로 계산해주는 것이 아니라, 최소인 노드 찾을 때마다 그에 맞게 key값을 update
	
	(seudo code)
	MST-Prim(G, w, r)
	for each u included in V do
		key[u] <- infinite
		pi[u] <- NIL
	end
	V_A <- {r}
	key[r] <- 0
	while |V_A| < n do
		find u included in V_A with the minimum key value;

		V_A <- V_A U {u}
		for each v do not included in V_A adjacet to u do
			if key[v] > w(u,v) then
				key[n] <- w(u,v)
				pi[v] <- u
			end
		end
	end
	
	시간복잡도 : O(n^2)

	key값이 최소인 노드 찾기
		최소 우선순위 큐를 사용
			V - V_A에 속한 노드들을 저장
			Extract-Min : key값이 최소인 노드를 삭제하고 반환

	(seudo code)
	MST-Prim(G, w, r)
	for each u included in V do
		key[u] <- infinite
		pi[u] <- NIL
	end
	key[r] <- 0
	Q <- V[G]
	while Q != 0
		do u <- Extract-Min(Q)
			for each v included in Adj[u]
				do if v included in Q and w(u,v) < key [v]
					pi[v] <- u
						key[v] <- w(u,v)
			end
	end

	시간복잡도 : O(mlogn)

	binary heap을 사용하여 우선순위 큐를 구현한 경우 
	while loop	
		n번의 Extract-Min 연산 : O(nlogn)
		m번의 Decrease-key 연산 : O(mlogn)
	따라서 시간복잡도 : O(nlogn + mlogn) = O(mlogn)
	우선순위 큐를 사용하지 않고 단순하게 구현할 경우 : O(n^2)
	Fibonacci 힙을 사용하여 O(m + nlogn)에 구현 가능 [Fredman-Tarjan 1984]
*/

