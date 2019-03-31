#include <stdio.h>

int fibo(int n){
	if (n == 1)
		return 1;
	if (n == 2)
		return 1;

	return fibo(n - 1) + fibo(n - 2);
}

int main(){
	int input = 0;
	scanf("%d", &input);
	printf("%d\n", fibo(input));
	
	return 0;
}