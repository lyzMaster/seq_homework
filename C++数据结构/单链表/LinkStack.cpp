#include "LinkStack.h"
#include <iostream>
using namespace std;

void LinkStack::push(int n) {
    Node* node = new Node(n);
    node->next = top;
    top = node;
}

void LinkStack::pop(){
    top = top->next;
}

int LinkStack::get_top(){
    return top->get_value();
}

void LinkStack::print_stack(){
    while (top){
        int a = get_top();
        cout<<get_top();
        pop();
    }
}


