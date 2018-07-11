#include <iostream>
using namespace std;

typedef int datatype;
const datatype max_size = 5;
struct stack{
    datatype top;
    datatype data[max_size];
};

void init(stack* s){
    s->top = -1;
}

bool isEmpty(stack* s){
    return s->top == -1;
};

bool isFull(stack* s){
    return s->top==max_size-1;
}

void push(stack* s,datatype n){
    if (isFull(s)){
        cout<<"out of bound"<<endl;
        return;
    }
    s->top++;
    s->data[s->top] = n;
}

void pop(stack* s){
    if (isEmpty(s)){
        cout<<"no ele"<<endl;
        return;
    }
    s->top--;
}

datatype stackTop(stack* s){
    return s->data[s->top];
}