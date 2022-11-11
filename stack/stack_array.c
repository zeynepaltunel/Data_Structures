#include<stdio.h>
#define STACK_SIZE 4

typedef struct{
 	int data[STACK_SIZE];
	int top;
}stack;

void reset(stack * stk){
	stk->top=-1;
}

void push( int c, stack * stk){
	if(stk->top!= STACK_SIZE-1){
	 	stk->top++;
		stk->data[stk->top]=c;
		printf("\n %d Added..",c);
	}
	else
		printf("\nStack is Full!!");
}

int pop (stack * stk){
	if(stk->top!=-1){
		return stk->data[stk->top--];
	}
    else
        printf("\n Stack is Empty!!");
    return;
}

int main(){
	stack ss; int x;
	reset(&ss);

	push(4,&ss);
	push(5,&ss);
	push(3,&ss);
	push(2,&ss);
	push(11,&ss);

	x= pop(&ss);
	printf("\n %d Removed from the stack",x);
	x= pop(&ss);
	printf("\n %d Removed from the stack",x);
	x= pop(&ss);
	printf("\n %d Removed from the stack",x);
	x= pop(&ss);
	printf("\n %d Removed from the stack",x);
	x= pop(&ss);
	printf("\n %d Removed from the stack",x);

    return 0;
}