#include "Queue.h"

void Queue::push(Node* node){
    if(!first){
        first = new StackNode(node);
        last = first;
        count++;
        return;
    }
    StackNode* stackNode = new StackNode(node);
    last->next = stackNode;
    last = stackNode;
    count++;
}

Node* Queue::pop(){
    Node* firstt = first->data;
    first = first->next;
    count--;
    return firstt;
}

bool Queue::is_empty() {
    return count==0;
}

