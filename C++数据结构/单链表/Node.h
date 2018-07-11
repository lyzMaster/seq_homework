#ifndef CHAIN_NODE_H
#define CHAIN_NODE_H

class Node {
public:
    Node *next;
    Node(int data_);
    Node();
    int get_value();
private:
    int data;
    int get_data(){
        return data;
    };
    void set_data(int x){
        data = x;
    };
};

#endif

