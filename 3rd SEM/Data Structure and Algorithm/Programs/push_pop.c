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

void peek(){
	printf("%d\n",arr[tos]);
}

void size(){
	printf("%d",tos+1);
}

void isEmpty(){
	if(tos == -1){
		printf("empty\n");
	}
	else{
		printf("not empty\n");
	}
}

void isFull(){
	if(tos == 9){
		printf("full\n");
	}
	else{
		printf("not full\n");
	}
}

void display(){
	int i;
	for(i = 0; i <= tos; i++){
		printf(" %d",arr[i]);
	}
	printf("\n");
}

int main(){
	int num , ch;
start:
	printf("1.push\n");
	printf("2.pop\n");
	printf("3.check empty\n");
	printf("4.check full\n");
	printf("5.peak\n");
	printf("6.display\n");
	printf("7.exit\n");
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
		isEmpty();
		goto start;
	}
	else if(ch == 4){
		isFull();
		goto start;
	}
	else if(ch == 5){
		peek();
		goto start;
	}
	else if(ch == 6){
		display();
		goto start;
	}
	else if(ch == 7){
		goto end;
	}
	else{
		printf("invalid input!\n");
		goto start;
	}
end:
}


