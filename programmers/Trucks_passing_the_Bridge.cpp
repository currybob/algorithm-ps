//https://programmers.co.kr/learn/courses/30/lessons/42583

#include <string>
#include <vector>

using namespace std;

typedef struct queue{
	int val;
	int loc_time;
}Queue;

Queue Q_bridge[20000];
int front_b, rear_b, front_w, rear_w;

int solution(int bridge_length, int weight, vector<int> truck_weights){
	int time = 0;
	int truckNum = truck_weights.size();
	int finishNum = 0;
	int sum = 0;

	while (finishNum != truckNum){
		time += 1;
		for (int i = front_b; i < rear_b; i++){
			if (Q_bridge[i].loc_time == bridge_length){
				front_b++;
				sum -= Q_bridge[i].val;
				finishNum += 1;
			}
		}
		if (front_w < truckNum && truck_weights[front_w] + sum <= weight){
			Q_bridge[rear_b++].val = truck_weights[front_w];
			sum += truck_weights[front_w++];
		}
		for (int i = front_b; i < rear_b; i++)
			Q_bridge[i].loc_time += 1;
	}

	return time;
}

int main(){
	int bridge_length = 100;
	int weight = 100;
	vector<int> truck_weights = { 10, 10, 10, 10, 10, 10, 10, 10, 10, 10 };

	printf("%d\n", solution(bridge_length, weight, truck_weights));
}