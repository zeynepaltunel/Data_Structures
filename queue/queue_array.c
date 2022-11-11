#include <stdio.h>
#include <stdlib.h>
#define QUEUE_SIZE 4

typedef enum{true,false} boolean;

typedef struct{
    int cnt;
    int front;
    int rear;
    int data[QUEUE_SIZE];
}queue;

void initialize(queue *q){
    q->cnt=0;
    q->front=0;
    q->rear=-1;
}

boolean isEmpty(queue *q){
    return((boolean)(q->cnt==0));
}

boolean isFull(queue*q){
    return((boolean)(q->cnt==QUEUE_SIZE));
}

void enqueue(queue *q, int x){
    if(isFull(q))
        printf("Queue is full!\n");
    else{
        q->rear++;
        q->cnt++;
        if(q->rear==QUEUE_SIZE)
            q->rear=0;
        q->data[q->rear]=x;    
    }    
}

int dequeue(queue *q){
    if(isEmpty(q)){
        printf("Queue is empty!\n");
        return -100;
    }
    else{
        int x = q->data[q->front];
        q->data[q->front]=0;
        q->front++;
        q->cnt--;
        if(q->front==QUEUE_SIZE)
            q->front=0;
        return x;    
    }
}

void print(queue *q){
    for(int i=0; i<QUEUE_SIZE; i++){
        printf("%d\n", q->data[i]);
    }
}

int main(){

    queue q;
    int x;
    initialize(&q);

    printf("Enter a value: ");
    scanf("%d", &x);
    enqueue(&q,x);

    printf("Enter a value: ");
    scanf("%d", &x);
    enqueue(&q,x);

    printf("Enter a value: ");
    scanf("%d", &x);
    enqueue(&q,x);

    printf("Enter a value: ");
    scanf("%d", &x);
    enqueue(&q,x);

    printf("Enter a value: ");
    scanf("%d", &x);
    enqueue(&q,x);

    printf("Enter a value: ");
    scanf("%d", &x);
    enqueue(&q,x);

    int y;
    y=dequeue(&q);
    printf("%d is deleted\n", y);
    y=dequeue(&q);
    printf("%d is deleted\n", y);
    y=dequeue(&q);
    printf("%d is deleted\n", y);
    y=dequeue(&q);
    printf("%d is deleted\n", y);
    y=dequeue(&q);

    enqueue(&q,111);
    
    print(&q);

    return 0;
}