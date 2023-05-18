#include <stdio.h>
#include <stdlib.h>
int tos = -1;
int arr[10];

void push(int num){
	if( tos >= -1 && tos < 10){
		tos += 1;
		arr[tos] = num;
	}
	else {
		printf("stackoverflow \n");
	}
}

void pop(){
	if( tos > -1){
		int hld = arr[tos];
		tos -= 1;
		printf("%d \n",hld);
	}
	else {
		printf("stactunderflow \n");
	}
}

int main(){
	int num , ch;
start:
	printf("1.push\n");
	printf("2.pop\n");
	printf("3.exit\n");
	scanf("%d",&ch);
	if(ch == 1){
		printf("enter value to push\n");
		scanf("%d",&num);
		push(num);
		goto start;
	}
	else if(ch == 2){
		pop();
		goto start;
	}
	else if(ch == 3){
		goto end;
	}
	else{
		printf("invalid input!");
	}
end:
	system("clear");
}


