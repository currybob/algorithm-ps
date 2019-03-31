#include <stdio.h>

int temp[1000];

int fibo(int n) {
	if (n <= 1)
		temp[n] = 1;
	if (temp[n] > 0)
		return temp[n];

	temp[n] = fibo(n - 1) + fibo(n - 2);
	return temp[n];
}

int main(){
	int input = 0;
	scanf("%d", &input);
	printf("%d\n", fibo(input - 1));
	
	return 0;
}