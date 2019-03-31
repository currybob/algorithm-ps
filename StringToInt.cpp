#include <stdio.h>

int StringToInt(char* s){
	int len = 0;
	while (s[len++]){}
	len -= 1;

	int temp = 0;
	for (int i = 0; i < len; i++){
		temp *= 10;
		temp += s[i] - 48;
	}
	return temp;
}

int main(){
	char input[100];
	scanf("%s", &input);

	printf("%d\n", StringToInt(input));

	return 0;
}