#include <stdio.h>

void ReverseString(char* input){
	int len = 0;
	while (input[len++]){}
	len -= 1;
	
	char temp;
	for (int i = 0; i < len/2; i++){
		temp = input[i];
		input[i] = input[len - 1 - i];
		input[len - 1 - i] = temp;
	}

	for (int i = 0; i < len; i++)
		printf("%c", input[i]);
}

int main(){
	char input[100];
	scanf("%s", &input);

	ReverseString(input);

	return 0;
}