#ifndef CHAIN_LINKSTACK_H
#define CHAIN_LINKSTACK_H

#include "Node.h"
class LinkStack {
public:
    Node* top = nullptr;   //add null
    void push(int n);
    int get_top();
    void pop();
    void print_stack();
};


#endif //CHAIN_LINKSTACK_H
