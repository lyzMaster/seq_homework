#ifndef UNTITLED1_NODE_H
#define UNTITLED1_NODE_H


class Node {
public:
    Node* lchild;
    Node* rchild;
    Node();
    Node(int x);
    void set_data(int x);
    int get_data();

private:
    int data;
};


#endif
