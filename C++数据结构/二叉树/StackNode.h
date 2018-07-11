#ifndef UNTITLED1_STACKNODE_H
#define UNTITLED1_STACKNODE_H

#include "Node.h"
class StackNode {
public:
    Node* data;
    StackNode* next;
    StackNode();
    StackNode(Node* node);
};


#endif //UNTITLED1_STACKNODE_H
