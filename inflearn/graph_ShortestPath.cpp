// Graph_ShortestPath
/*
최단경로 (shortest path)
	가중치 (방향) 그래프 G=(V,E), 즉 모든 edge에 가중치가 있음 - BFS만으로는 최단경로를 구할 수 없음
	경로 p = (v0, v1, ... , vk)의 길이는 경로상의 모든 edge의 가중치의 합
	노드 u에서 v까지의 최단경로의 길이를 S(u, v)라고 표시하자.

	유형
		1. Single-source
			하나의 출발 노드 s로부터 다른 모든 노드까지의 최단 경로를 찾아라.
			예 : Dijkstra의 알고리즘

		2. Single-destination
			모든 노드로부터 하나의 목적지 노드까지의 최단 경로를 찾아라
			Single-source 문제와 동일

		3. Single-pair
			주어진 하나의 출발 노드 s로부터 하나의 목적지 노드 t까지의 최단 경로를 찾아라
			최악의 경우 시간복잡도에서 Single-source 문제보다 나은 알고리즘이 없음

		4. All-pairs
			모든 노드 쌍에 대해서 최단 경로를 찾아라
			예 : Floyd 알고리즘

	최단경로와 음수 가중치
		음수 사이클이 있으면 최단 경로가 정의되지 않음
		알고리즘에 따라 음수 가중치가 있어도 작동하는 경우가 있고 그렇지 않은 경우도 있음
	
	최단경로의 기본 특성
		최단 경로의 어떤 부분경로도 역시 최단 경로이다.
		최단 경로는 사이클을 포함하지 않는다. (음수 사이클이 없다는 가정하에서)

	Single-source 최단경로문제
		입력 : 음수 사이클이 없는 가중치 방향그래프 G=(V,E)와 출발 노드 s
		목적 : 각 노드 v에 대해서 다음을 계산한다.
			d[v]
				현재까지 찾은 s에서 v까지의 최선의 경로
				처음에는 d[s] = 0, d[v] = infinite로 시작한다.
				알고리즘이 진행됨에 따라서 감소해간다. 하지만 항상 d[v] >= S(s,v)를 유지한다.
				최종적으로는 d[v] = S(s,v)가 된다.
			pi[v]
				s에서 v까지의 최단경로상에서 v의 직전 노드(predecessor)
				그런 노드가 없는 경우 pi[v] = NULL

		기본연산 : Relaxation
		(seudo code)
			if d[v] > d[u] + w(u,v)
				then d[v] <- d[u] + w(u,v)
					pi[v] <- u

		대부분의 single-source 최단경로 알고리즘의 기본 구조
			1. 초기화 : d[s] = 0, 노드 v != s 에 대해서 d[v] = infinite, pi[v] = NULL
			2. edge들에 대한 반복적인 relaxation
		알고리즘들 간의 차이는 어떤 edge에 대해서, 어떤 순서로 relaxation을 하느냐에 있음
		
		기본 알고리즘
			(seudo code)
			Generic-Single-Source(G,w,s)
				Initialize-single-source(G,s)
				repeat
					for each edge (u,v) included in E
						RELAX(u,v,w)
				until there is no change
			
			>> n-1번의 반복으로 충분 (edge의 개수를 넘어가지는 않을 것)
	
		Bellman-Ford 알고리즘
			(seudo code)
			Bellman-Ford(G,w,s)
				Initialize-single-source(G,s)
				for i <- 1 to |V[G]| - 1
 					dp for each edge (u,v) included in E
						do RELAX(u,v,w)
				for each edge (u,v) included in E[G]
					do if d[v] > d[u] + w(u,v)
						then return FALSE // 음수 사이클이 존재한다는 의미
				return TRUE
			
			시간복잡도 : O(nm)
			Worst case 
				d[v]가 한 번 갱신될 때마다 전부 다 바뀜

		Dijkstra의 알고리즘
			음수 가중치가 없다고 가정
			s로부터 최단경로의 길이를 이미 알아낸 노드들의 집합 S를 유지. 
			맨 처음엔 S = {s}
			Loop invariant
				u not included in S 인 각 노드 u에 대해서 d(u)는 이미 S에 속한 노드들만 거쳐서
				s로부터 u까지 가는 최단경로의 길이

			정리 : d(u) = min(d(v)) 인 노드 u에 대해서, d(u)는 s에서 u까지의 최단경로의 길이이다.
			증명 : (proof by contradiction)
				아니라고 하자. 그러면 s에서 u까지 다른 최단경로가 존재
				d(v) >= d(u)이므로 모순

			d(u)가 최소인 노드 u (not included in S)를 찾고, S에 u를 추가
			S가 변경되었므로 다른 노드들의 d(v)값을 갱신
				d(v) = min{d(v), d(u) + w(u,v)}
			즉, edge (u,v)에 대해서 relaxation하면 Loop invariant가 계속 유지됨
			
			(seudo code)
			Dijkstra(G, w, s)
				for each u do
					d[u] <- infinite
					pi[u] <- NULL
				end
				d[s] <- 0
				while |S| < n do
					find u not included in S with the minimum d[u] value;
					S <- S u {u}
					for each v not included in adjacent to u do
						if d[v] > d[u] + w(u,v) then
							d[v] <- d[u] + w(u,v)
							pi[v] <- u
						end
					end
				end

				시간복잡도 : O(n^2)
					Prim의 알고리즘과 동일함
					우선순위 큐를 사용하지 않고 단순하게 구현할 경우 O(n^2)
					binary heap을 우선순위 큐로 사용할 경우 O(nlogn + mlogn)
					Fibonacci heap을 사용하면 O(nlogn+m)에 구현가능

		Floyd-warshall Algorithm - DP의 대표적인 예
			가중치 방향 그래프 G = (V, E), V = {1, 2, ..., n}
			모든 노드 쌍들간의 최단경로의 길이를 구함
			d_k[i, j]
				중간에 노드집합 {1, 2, ...., k}에 속한 노드들만 거쳐서 
				노드 i에서 j까지 가는 최단경로의 길이 
					d_k[i, j] = min{d_k-1[i, j], d_k-1[i, k] + d_k-1[k, j]}
					-> 노드 k를 지나는 경우와 지나지 않는 경우 2가지가 있음 
	
			(seudo code)
			FloydWarshall(G){
				for i <- 1 to n
					for j <- 1 to n 
						d_0[i, j] <- W_ij;
				for k <- 1 to n
					for i <- 1 to n
						for j <- 1 to n
							d_k[i, j] <- min{d_k-1[i, j], d_k-1[i, k] + d_k-1[k, j]};
			}
			
			시간복잡도 : O(n^3)
			
			(update)
			FloydWarshall(G){
				for i <- 1 to n
					for j <- 1 to n 
						d[i, j] <- W_ij;
				for k <- 1 to n
					for i <- 1 to n
						for j <- 1 to n
							d[i, j] <- min{d[i, j], d[i, k] + d[k, j]};
			}

			(find path)
			FloydWarshall(G){
				for i <- 1 to n
					for j <- 1 to n 
						d[i, j] <- W_ij;
						pi[i, j] <- NIL;
				for k <- 1 to n
					for i <- 1 to n
						for j <- 1 to n
							d[i, j] <- min{d[i, j], d[i, k] + d[k, j]};
							pi[i, j] = k;
			}

			printPath(s, t, pi){
				if pi[s, t] == NIL then
					return;
				printPath(s, pi[s, t]);
				print(pi[s, t]);
				printPath(pi[s, t], t);
			}
			s에서 t까지 가는 경로가 존재한다는 가정하에 최단경로상의 중간노드들을 출력
*/

