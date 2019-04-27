// N-Queens Problem
/*
Backtrakcing
총 N^N 개의 경우 탐색
막다른 길에 도달하면 가장 최근에 내린 결정을 번복

상태공간트리
찾는 해를 포함하는 트리
즉, 해가 존재한다면 그것은 반드시 이 트리의 어떤 한 노드에 해당
따라서 이 트리를 체계적으로 탐색하면 해를 구할 수 있음
>> DFS - 1) recursion 2) stack

(Backtracking/DFS suedo code)
returnType queens( currentNode ){
	if non-promising
		report failure and return;
	else if success
		report answer and return;
	else
		visit children recursively;
}

(N-Queens Problem seudo code)
int loc[N + 1]; // 특정 level의 말이 어디에 놓여있는지 표현하는 전역변수, 열 정보만 사용해서 표현가능

bool promising( int level ){
	for (int i = 1; i < level; i++){
		if(loc[i] == loc[level])
			return false;
		else if(level - i == abs(loc[level] - loc[i])) // diagonal 
			return false;
	}
	return true;
}

bool queens( int level ){
	if (!promising(level)) // promising : 놓인 말들끼리 충돌하는가 검사
		return false;
	else if (level == N)
		return true;
	
	for (int i = 1; i <= N; i++){
		loc[level + 1] = i; // 다음 level의 말을 for문을 이용해 각 열에 놓은 후 재귀통해 검사 
		if (queens(level + 1))
			return true;
	}
	return false;
}
*/

#include <stdio.h>

int N = 8;
int location[8];

int my_abs(int val){
	return val > 0 ? val : -val;
}

bool promising(int level){
	int i;
	for (i = 0; i < level; ++i){
		if (location[i] == location[level])
			return false;
		else if (level - i == my_abs(location[level] - location[i]))
			return false;
	}
	return true;
}

bool queen(int level){
	if (!promising(level))
		return false;
	else if (level == N - 1){
		int i; 
		for (i = 0; i <= level; ++i)
			printf("(%d, %d)\n", i, location[i]);
		return true;
	}

	int i;
	for (i = 0; i < N; ++i){
		location[level + 1] = i;
		if (queen(level + 1))
			return true;
	}
	return false;
}

int main(){
	N = 8; 

	queen(0);

	return 0;
}