#include "TreeOps.h"
#include <iostream>
#include <algorithm>
#include "Stack.h"
#include "Queue.h"
#include <cstddef>

using namespace std;

Node* TreeOps::create(Node* node){
    if (!node){
        node = new Node;
    }
    int x;
    cin>>x;
    if (x==0){
        node = NULL;
    }
    else{
        node->set_data(x);
        node->lchild = create(node->lchild);
        node->rchild = create(node->rchild);   //?原：create(node->rchild)
    }
    return node;
}

void TreeOps::root_first_traversal(Node* root) {
    if (!root){
        return ;
    }
    cout<<root->get_data()<<' ';
    root_first_traversal(root->lchild);
    root_first_traversal(root->rchild);
}

void TreeOps::root_last_traversal(Node *root) {
    if (!root){
        return;
    }
    root_last_traversal(root->lchild);
    root_last_traversal(root->rchild);
    cout<<root->get_data()<<' ';
}

void TreeOps::root_mid_traversal(Node *root) {
    if (!root){
        return;
    }
    root_mid_traversal(root->lchild);
    cout<<root->get_data()<<' ';
    root_mid_traversal(root->rchild);
}

int TreeOps::how_many_leaf(Node* root){
    if (!root){
        return 0;
    }
    if (!root->lchild&&!root->rchild){
        return 1;
    }
    return (how_many_leaf(root->lchild)+how_many_leaf(root->rchild));
}

int TreeOps::depth(Node* root){
    if (!root){
        return 0;
    }
    int l_depth = depth(root->lchild);
    int r_depth = depth(root->rchild);
    return l_depth > r_depth ? l_depth + 1 : r_depth + 1;
}

void TreeOps::invert(Node* root){
    if ((!root)||(!root->lchild&&!root->rchild)){//||(!root->lchild&&!root->rchild) 加上这句话少进一层递归
        return;
    }
    swap(root->lchild,root->rchild);
    invert(root->lchild);
    invert(root->rchild);
}

Node* TreeOps::create_binary_sort(Node* root,int a){
    if (!root){
        root = new Node(a);
    }

    else if (a<root->get_data()){
        root->lchild = create_binary_sort(root->lchild,a);
    }

    else if(a>=root->get_data()){
        root->rchild = create_binary_sort(root->rchild,a);
    }
    return root;
}

Node* TreeOps::search_binary_sort_node(Node* root,int a){
    static Node* node;
    if (!root){
        return root;
    }

    else if (a>root->get_data()){
        search_binary_sort_node(root->rchild,a);
    }

    else if(a<root->get_data()){
        search_binary_sort_node(root->lchild,a);
    }

    else if(a==root->get_data()){
        node = root;
        return node;
    }
    return node;
}

Node* TreeOps::insert_binary_sort_node(Node* root,int a){
    if (a>=root->get_data()){
        if (!root->rchild){
            Node* node = new Node(a);
            root->rchild = node;
            return root;
        }
        insert_binary_sort_node(root->rchild,a);
    }

    else if(a<root->get_data()){
        if (!root->lchild){
            Node* node = new Node(a);
            root->lchild = node;
            return root;
        }
        insert_binary_sort_node(root->lchild,a);
    }
}

Node* TreeOps::search_next_mid_node(Node *root,Node* search_node) {
    static bool is_equal = false;
    static Node* node;
    if (!root){
        return root;
    }
    search_next_mid_node(root->lchild,search_node);
    if (is_equal){
        node = root;
        is_equal = false;    //忘记把此变量置为false，返回的node是root
        return node;
    }
    if (root==search_node){
        is_equal = true;
    }
    search_next_mid_node(root->rchild,search_node);
    return node;
}

Node* TreeOps::delete_binary_sort_node(Node* root,int a){
    Node* node = search_binary_sort_node(root,a);
    if (!node->lchild&&!node->rchild){
        int c = node->get_data();
        cout<<c<<endl;
        delete node;
        node = NULL;
    }
    else if(!node->lchild&&node->rchild){
        *node = *(node->rchild);
    }
    else if(node->lchild&&!node->rchild){
        *node = *(node->lchild);
    }
    else if(node->lchild&&node->rchild){     //wrong!
        Node* next = search_next_mid_node(root,node);
        int d = next->get_data();
        next->set_data(node->get_data());
        node->set_data(d);
        delete next;
        next = NULL;
    }
    return root;
}

void TreeOps::root_first_traversal_with_stack(Node *node) {   //用栈实现
    Stack* stack = new Stack;
    stack->push(node);
    while (!stack->isEmpty() && node){
        Node* node = stack->pop();
        int b = node->get_data();
        cout<<node->get_data()<<" ";
        if (node->rchild){        //先右 后左很重要！
            stack->push(node->rchild);
        }
        if(node->lchild){
            stack->push(node->lchild);
        }
    }
    cout<<endl;
}

void TreeOps::layer_by_layer_traversal(Node *root) {
    Queue* queue = new Queue;
    queue->push(root);
    while (!queue->is_empty() && root){
        Node* node = queue->pop();
        cout<<node->get_data()<<" ";
        if (node->lchild){
            queue->push(node->lchild);
        }
        if (node->rchild){
            queue->push(node->rchild);
        }
    }
    cout<<endl;
}


