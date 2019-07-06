//https://programmers.co.kr/learn/courses/30/lessons/42840

#include <string>
#include <vector>
#include <stdio.h>

using namespace std;

int check_one[5] = { 1, 2, 3, 4, 5 };
int check_two[8] = { 2, 1, 2, 3, 2, 4, 2, 5 };
int check_three[10] = { 3, 3, 1, 1, 2, 2, 4, 4, 5, 5 };

vector<int> findMax(int a, int b, int c){
	vector<int> answer;
	if (a < b){
		if (b < c)
			answer.push_back(3);
		else if (b == c){
			answer.push_back(2);
			answer.push_back(3);
		}
		else
			answer.push_back(2);
	}
	else if (a == b){
		if (b < c)
			answer.push_back(3);
		else if (b == c){
			answer.push_back(1);
			answer.push_back(2);
			answer.push_back(3);
		}
		else{
			answer.push_back(1);
			answer.push_back(2);
		}
	}
	else{
		if (b < c){
			if (a < c)
				answer.push_back(3);
			else if (a == c){
				answer.push_back(1);
				answer.push_back(3);
			}
			else{
				answer.push_back(1);
			}
		}
		else
			answer.push_back(1);
	}
	return answer;
}

vector<int> solution(vector<int> answers) {
	int sum = 0;
	int answerNum = answers.size();
	// 1
	for (int i = 0; i < answerNum; i++){
		if (answers[i] == check_one[i % 5])
			sum += 1;
	}
	int one = sum;
	// 2
	sum = 0;
	for (int i = 0; i < answerNum; i++){
		if (answers[i] == check_two[i % 8])
			sum += 1;
	}
	int two = sum;
	// 3
	sum = 0;
	for (int i = 0; i < answerNum; i++){
		if (answers[i] == check_three[i % 10])
			sum += 1;
	}
	int three = sum;
	
	return findMax(one, two, three);
}

int main(){
	// tc 1
    // vector<int> answers = { 1, 2, 3, 4, 5 };
	// tc 2
    vector<int> answers = { 1, 3, 2, 4, 2 };
	
	vector<int> sol = solution(answers);
	int solNum = sol.size();

	for (int i = 0; i < solNum; i++)
		printf("%d ", sol[i]);
	puts("");

	return 0;
}