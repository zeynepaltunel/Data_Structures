#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define EMPTY 0
#define FULL 100

struct node{
	char d;
	struct node *next;
};
typedef struct node node;

struct stack{
 	int cnt; 	/* count of the elements */
 	struct node *top; 	/* pointer to the top element */
};
typedef struct stack stack;

bool isempty(stack *stk){
	return(stk -> cnt == EMPTY);
}

bool isfull(stack *stk){
	return (stk -> cnt == FULL);
}

void initialize(stack *stk){
 	stk -> cnt = 0; 		/* count of the elements */
	stk -> top = NULL; 		/* pointer to the top element */
}

char top(stack *stk){
	return (stk -> top -> d);
}

void push(char x, stack *stk){
    if(!isfull(stk)){
        /* create new node */
        node *temp = (node*)malloc(sizeof(node));
        temp -> d = x; 		//Write new data value
        temp -> next = stk -> top;
        stk -> top = temp;
        stk -> cnt++;
    }
    else
        printf("n Stack is full!!");
}

//If stack is full and we push ---- overflow!!
//If stack is empty and we pop ---- underflow!!

char pop(stack *stk){
    if(!isempty(stk)){
        char x; // will store the top data
        node *temp = stk->top;
        x = stk -> top -> d;
        stk -> top = stk -> top -> next;
        stk -> cnt--;
        return x;
    }
    else   
        printf("Stack is empty!!");
}

//stack LIFO (son giren ilk çıkar) yapıdadir.

int main(){
	char str[] = "CME227";
	int i;
	stack s;
	initialize(&s); 	/* initialize the stack */

	for(i = 0; str[i] != '\0'; ++i){	 /* fill stack */
		push(str[i], &s);
    }

    char x;

    x=pop(&s);
    printf("\n %c Removed from the stack", x);
	
    printf("String in the stack: \n");

	while (!isempty(&s))
		printf("\n %c", pop(&s));
    return 0;    
}
