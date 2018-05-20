#include <iostream>
using namespace std;

typedef int datatype;
const datatype max_size = 5;
struct queue{
    datatype front;
    datatype rear;
    int count;
    datatype data[max_size];
};

void init(queue* q){
    q->rear = q->front = 0;
    q->count = 0;
}
bool isEmpty(queue* q){
    return q->count==0;
}

bool isFull(queue* q){
    return q->count==max_size;
}

int size(queue* q){
    return q->count;
}

void enQueue(queue* q,datatype n){
    if (isFull(q)){
        cout<<"out of bound"<<endl;
        return;
    }
    q->count++;
    q->data[q->rear] = n;
    q->rear = (q->rear+1)%max_size;
}

void deQueue(queue* q){
    if (isEmpty(q)){
        cout<<"no data"<<endl;
        return;
    }
    q->count--;
    q->front = (q->front+1)%max_size;
}

datatype queueFront(queue* q){
    return q->data[q->front];
}



