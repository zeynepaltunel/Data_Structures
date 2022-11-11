#include <stdio.h>
#include <stdlib.h>

#define EMPTY 0
#define FULL 100

typedef int data;
typedef enum{true,false} boolean;

struct node{
    int d;
    struct node *next;
};

typedef struct node node;

struct queue{
    int cnt;
    node *front;
    node *rear;
};

typedef struct queue queue;

void initialize(queue *q){
    q->cnt=0;
    q->front=NULL;
    q->rear=NULL;
}

boolean isEmpty(queue *q){
    return ((boolean)(q->cnt==EMPTY));
}
boolean isFull(queue *q){
    return ((boolean)(q->cnt==FULL));
}

void enqueue(queue *q, data x){
    
    node *temp;
    temp = (node*)malloc(sizeof(node));
    temp->d=x;
    temp->next=NULL;

    if(!isEmpty(q)){
        q->rear->next=temp;
        q->rear=temp;
    }
    else{
        q->front=temp;
        q->rear=temp;
    }
    q->cnt++;
}

data dequeue(queue *q){
    if(isEmpty(q)){
        printf("Queue is empty\n");
        return -100;
    }
    else{
        data x;
        node *temp=q->front;
        x=temp->d;
        q->front=temp->next;
        free(temp);
        q->cnt--;
        return x;
    }
}
void print(queue *q){
    node *p;
    printf("\nQueue structure: ");
    for(p=q->front; p!=NULL; p=p->next){
        printf("%d\t",p->d);
    }
}

int main(){
    queue q;
    data x;
    
    initialize(&q);
    
    printf("Enter value: \n");
    scanf("%d", &x);

    enqueue(&q,x);
    
    printf("Enter value: \n");
    scanf("%d", &x);

    enqueue(&q,x);

    printf("Enter value: \n");
    scanf("%d", &x);

    enqueue(&q,x);

    print(&q);

    dequeue(&q);
    dequeue(&q);
    dequeue(&q);

    print(&q);

    if(isEmpty(&q))
        printf("Queue is empty\n");
    else
        printf("queue is not empty\n");

    return 0;    
}