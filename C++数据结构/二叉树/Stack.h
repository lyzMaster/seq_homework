#ifndef UNTITLED1_STACK_H
#define UNTITLED1_STACK_H

#include "StackNode.h"

class Stack {
public:
    StackNode* top;
    void push(Node* node);
    Node* pop();
    bool isEmpty();
};


#endif //UNTITLED1_STACK_H
