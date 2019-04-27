// 멱집합 powerset
/*
{a, b, c, d, e, f}의 모든 부분집합을 나열하려면
	a를 제외한 {b, c, d, e, f}의 모든 부분집합들을 나열하고
	{b, c, d, e, f}의 모든 부분집합에 {a}를 추가한 집합들을 나열하면 된다.
		{c, d, e, f}의 모든 부분집합에 {a}를 추가한 집합들을 나열하고
		{c, d, e, f}의 모든 부분집합에 {a, b}를 추가한 집합들을 나열한다.
			{d, e, f}의 모든 부분집합들에 {a}를 추가한 집합들을 나열하고
			{d, e, f}의 모든 부분집합에 {a, c}를 추가한 집합들을 나열한다.

(seudo code)
if S is an empty set
	print nothing;
else
	let t be the first element of S;
	find all subsets of S-{t} by calling powerSet(S-{t}); 
	// 이렇게 하면 powerSet 함수는 여러 개의 집합들을 return 해야 한다. 
	print the subsets; 
	print the subsets with adding t;
	// 그러면 얘네도 print가 아니라 return이 되어야 함
	// 바람직하지 않음. 그냥 프린트 해버리는 게 메모리 관점 더 효율적
>> 좋지 못한 알고리즘

(seudo code - Revision)
// S의 멱집합을 구한 후 각각에 집합 P를 합집합하여 출력
powerSet(P, S) 
	if S is an empty set
		print P;
	else
		let t be the fisrt element of S;
		powerSet(P, S-{t});
		powerSet(P U {t}, S-{t});
*/

#include <stdio.h>

char data[] = { 'a', 'b', 'c', 'd', 'e', 'f' };
int n = 6;
bool P[6];

void powerSet(int k){
	if (k == n){ // empty set
		int i;
		for (i = 0; i < n; ++i){
			if (P[i])
				printf("%c ", data[i]);
		}
		printf("\n");
		return;
	}

	P[k] = false; // data[k]를 포함하지 않는 경우
	powerSet(k + 1);
	P[k] = true;  // data[k]를 포함하는 경우 
	powerSet(k + 1);
}

int main(){

	powerSet(0);
	
	return 0;
}
