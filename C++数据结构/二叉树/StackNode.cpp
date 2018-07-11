#include "StackNode.h"
#include <cstddef>

StackNode::StackNode(){
    next = NULL;
    data= NULL;
}

StackNode::StackNode(Node *node) {
    data = node;
    next = NULL;
}
