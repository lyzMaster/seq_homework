#include <iostream>
#include "Node.h"
using namespace std;

Node* new_head = new Node;

Node::Node(int data) {
    set_data(data);
}

Node::Node() {
    set_data(-1);
}

int Node::get_value(){
    return get_data();
}

