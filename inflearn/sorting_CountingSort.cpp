// Sorting_SortingInLinearTime
/*
Non-Comparsion Sort
	어떤 Comparison Sort도 Linear Time을 가질 수 없음

	Counting Sort
		n개의 정수를 정렬하라. 단, 모든 정수는 0에서 k사이의 정수이다.
		예) n명의 학생들의 시험점수를 정렬하라. 단 모든 점수는 100이하의 양의 정수이다.
		
		예) k = 5인 경우의 예
			A = {2, 5, 3, 0, 2, 3, 0, 3}
			counting 배열을 만듦 C = {2, 0, 2, 3, 0, 1} 각각의 숫자 갯수를 나타냄
			counting 배열의 값에 따라 그 index를 반복해서 출력하면 됨
			>> 0 0 2 2 3 3 3 5

			(seudo code)
			int A[n];
			int C[k] = {0,};
			for (int i = 1; i <= n; i++)
				C[A[i]]++;
			for (int s = 1, i = 0; i <= k; i++){
				for(int j = 0; j < C[i]; j++)
					A[s++] = j;
			}

			위의 경우 숫자만 정렬이 됨
			만약 학생 이름도 같이 있다면 그 이름들은 정렬이 되지 않음

			>> Counting 배열에 누적값을 계산해서 넣자
			i보다 작거나 같은 것들의 개수가 배열에 들어가있는 것
			B라는 추가배열의 누적값번째 index에 값을 넣어주면 정렬이 됨
			예) A = {2, 5, 3, 0, 2, 3, 0, 3} C = {2, 2, 4, 7, 7, 8}
			    B[7] = 3 -> B[6] = 3 ....
			
			(seudo code)
			CountingSort(A, B, k)
				for i <- 0 to k
					do C[i] <- 0
				for j <- 1 to length[A]
					do C[A[j]] <- C[A[j]] + 1
				for i <- 1 to k
					do C[i] <- C[i] + C[i - 1]
				for j <- length[A] downto 1
					do B[C[A[j]]] <- A[j]
						C[A[j]] <- C[A[j]] - 1

			시간복잡도
				O(n+k) 또는 O(n) if k=O(n)  : linear time
				k가 클 경우 비실용적
				Stable 정렬 알고리즘
					입력에 동일한 값이 있을 때 입력에 먼저 나오는 값이 출력에서도 먼저 나온다
					Counting Sort는 stable하다.
*/

