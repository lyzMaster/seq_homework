#ifndef CHAIN_CHAIN_H
#define CHAIN_CHAIN_H

#include "Node.h"

class Chain {
public:
    Node* head = new Node;  //一定要在类里定义！！才能保证不同
    Node* create();
    void print_ele();
    Node* search(int value);
    void insert(int position,int value);
    void delete_ele_by_value(int value);
    int get_length();
    void insertion_sort();
    void invert();
    void merge(Node* chain2);
    void split();

private:
    void print_node_ele(Node* node);
};


#endif //CHAIN_CHAIN_H
