#ifndef UNTITLED1_TREE_H
#define UNTITLED1_TREE_H

#include "Node.h"

class TreeOps {
public:
    Node* create(Node* node);
    void root_first_traversal(Node* node);
    void root_last_traversal(Node* node);
    void root_mid_traversal(Node* node);
    int how_many_leaf(Node* root);
    int depth(Node* root);
    void invert(Node* node);
    Node* create_binary_sort(Node* root,int a);
    Node* search_binary_sort_node(Node* root,int a);
    Node* insert_binary_sort_node(Node* root,int a);
    Node* delete_binary_sort_node(Node* root,int a);
    void root_first_traversal_with_stack(Node* root);
    void layer_by_layer_traversal(Node* root);

private:
    Node* search_next_mid_node(Node *root,Node* search_node);
};


#endif //UNTITLED1_TREE_H
