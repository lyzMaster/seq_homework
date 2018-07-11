#ifndef UNTITLED1_QUEUE_H
#define UNTITLED1_QUEUE_H

#include "StackNode.h"
#include <cstddef>

class Queue {
public:
    StackNode* first;
    StackNode* last;
    int count;
    void push(Node* node);
    Node* pop();
    bool is_empty();
};


#endif //UNTITLED1_QUEUE_H
