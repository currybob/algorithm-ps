// Recursion - Basic

#include <stdio.h>

// 0부터 n까지의 합을 구하는 함수
int addInt(int n){
	if (n == 0)
		return 0;
	else
		return n + addInt(n - 1);
}

// factorial
int factorial(int n){
	if (n == 0)
		return 1;
	else
		return n * factorial(n - 1);
}

// x^n
int power(double x, int n){
	if (n == 0)
		return 1;
	else
		return x * power(x, n - 1);
}

// fibonacci
int fibonacci(int n){
	if (n < 2)
		return n;
	else
		return fibonacci(n - 1) + fibonacci(n - 2);
}

// 최대공약수 (Greatest Common Divisor)
int gcd(int m, int n){
	if (m < n){
		int tmp = m; m = n; n = tmp;
	}
	if (m % n == 0)
		return n;
	else
		return gcd(n, m % n);
}
 
int gcd_v2(int m, int n){
	if (n == 0)
		return m;
	else
		return gcd_v2(n, m % n);
}

// 문자열길이 계산
int strLen(char *str){
	if (*str == '\0')
		return 0;
	else
		str++;
	return 1 + strLen(str);
}

// 문자열 프린트
void printStr(char *str){
	if (*str == '\0')
		return;
	else{
		printf("%c", *str);
		str++;
		printStr(str);
	}
}

// 문자열 뒤집어 프린트.....
void printReverse(char *str){
	if (*str == '\0')
		return;
	else{
		str++;
		printReverse(str);
		str--;
		printf("%c", *str);
	}
}

// 2진수
void printInBinary(int n){
	if (n < 2)
		printf("%d", n);
	else{
		printInBinary(n / 2);
		printf("%d", n % 2);
	}
}

// 배열의 합 구하기
int sumArray(int n, int *data){
	if (n <= 0)
		return 0;
	else
		return sumArray(n - 1, data) + data[n - 1];
}

// 배열 정수 읽어오기 >> 입력 받아오는 함수
void readArray(int n, int *data){
	if (n == 0)
		return;
	else{
		readArray(n - 1, data);
		scanf("%d", &data[n - 1]);
	}
}

// 순차 탐색
int sequentialSearch(int* data, int n, int target){
	for (int i = 0; i < n; i++){
		if (data[i] == target)
			return i;
	}
	return -1;
}

int sequentialSearch_v2(int *data, int begin, int end, int target){
	if (begin > end)
		return -1;
	else if (target == data[begin])
		return begin;
	else
		return sequentialSearch_v2(data, begin + 1, end, target);
}

// 순차 탐색 다른 버젼 (중간값 탐색)
int sequentialSearch_v3(int *data, int begin, int end, int target){
	if (begin > end)
		return -1;
	else{
		int middle = (begin + end) / 2;
		if (data[middle] == target)
			return middle;
		int index = sequentialSearch_v3(data, begin, middle - 1, target);
		if (index != -1)
			return index;
		else
			return sequentialSearch_v3(data, middle + 1, end, target);
	}
}

int max(int a, int b){
	return a > b ? a : b;
}
// 최대값 찾기
int findMax(int *data, int begin, int end){
	if (begin == end)
		return data[begin];
	else
		max(data[begin], findMax(data, begin + 1, end));
}

int findMax_v2(int *data, int begin, int end){
	if (begin == end)
		return data[begin];
	else{
		int middle = (begin + end) / 2;
		int max1 = findMax_v2(data, begin, middle);
		int max2 = findMax_v2(data, middle + 1, end);
		return max(max1, max2);
	}
}

// 이진검색
// data가 크기 순으로 배열에 저장되어 있을 때만 사용가능
// 중간값을 기준으로 나머지 반을 없애주면서 탐색
bool my_strcmp(char* a, char *b){
	while (*a){
		if (*a != *b)
			return false;
		a++;
		b++;
	}
	return true;
}

int binarySearch(char *data[], char *target, int begin, int end){
	if (begin > end)
		return -1;
	else{
		int middle = (begin + end) / 2;
		int cmpResult = my_strcmp(data[middle], target);
		if (my_strcmp(data[middle], target))
			return middle;
		else if (cmpResult == false)
			return binarySearch(data, target, begin, middle - 1);
		else
			return binarySearch(data, target, middle + 1, end);
	}
}

int main(){
	char *inputChar = "hello my name is";
	//printf("%d\n", strLen(inputChar));
	//printReverse(inputChar);
	/*
	int data[5] = { 0 };
	int n = 5;
	readArray(n, data);
	int idx = 0;
	while (n--){
		printf("%d", data[idx++]);
	}
	*/
	int data[5] = { 2, 45, 61, 55, 98 };
	//printf("%d\n", findMax(data, 0, 4));
	
	return 0;
}
