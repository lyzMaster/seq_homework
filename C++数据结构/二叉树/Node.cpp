#include "Node.h"
#include <cstddef>


int Node::get_data(){
    return data;
}

void Node::set_data(int x) {
    data = x;
}

Node::Node(int x){
    set_data(x);
    lchild = NULL;
    rchild = NULL;
}

Node::Node(){
    lchild = NULL;
    rchild = NULL;
}

