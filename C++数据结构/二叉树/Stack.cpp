#include "Stack.h"
#include <cstddef>

void Stack::push(Node* node){
    StackNode* stackNode = new StackNode(node);
    stackNode->next = top;
    top = stackNode;
}

Node* Stack::pop(){
    StackNode* topp = top;  //忘记保存top,以至于返回空指针
    top = top->next;
    return topp->data;
}

bool Stack::isEmpty() {
    return top == NULL;
}


