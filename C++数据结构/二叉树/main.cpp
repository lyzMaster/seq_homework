#include <iostream>
#include "TreeOps.h"
using namespace std;

TreeOps ops;
Node* create_binary_sort_tree();

int main() {
    Node* root;
    Node* root1;
    cout<<"1:create binary tree,\'0\' means null,please use root first traversal"<<endl;
    cout<<"2:root first traversal"<<endl;
    cout<<"3:root mid traversal"<<endl;
    cout<<"4:root last traversal"<<endl;
    cout<<"5:number of leaves"<<endl;
    cout<<"6:depth of Tree"<<endl;
    cout<<"7.invert the Tree"<<endl;
    cout<<"8.create binary sort tree,please input with root first traversal,end with 0"<<endl;
    cout<<"9.search a node of the binary sort tree(will output data of the node)"<<endl;
    cout<<"10.insert a node of the binary sort tree"<<endl;
    cout<<"11.delete a node of the binary sort tree"<<endl;
    cout<<"12.root first traversal with stack(will output the value of the sort tree)"<<endl;
    cout<<"13.layer by layer traversal(will output the value of the sort tree)"<<endl;
    for(;;){
        int i;
        cin>>i;
        if(i==1){
            root = ops.create(root);
        }
        else if(i==2){
            ops.root_first_traversal(root);
        }
        else if(i==3){
            ops.root_mid_traversal(root);
        }
        else if(i==4){
            ops.root_last_traversal(root);
        }
        else if(i==5){
            cout<<ops.how_many_leaf(root)<<endl;
        }
        else if(i==6){
            cout<<ops.depth(root)<<endl;
        }
        else if(i==7){
            ops.invert(root);
            cout<<"successful!"<<endl;
        }
        else if(i==8){
            root1 = create_binary_sort_tree();
        }
        else if(i==9){
            int x;
            cout<<"please enter the value that you want to delete:";
            cin>>x;
            Node* nodee = ops.search_binary_sort_node(root1,x);
            cout<<nodee->get_data()<<endl;
        }
        else if(i==10){
            cout<<"please enter the value that you want to insert:";
            int x;
            cin>>x;
            ops.insert_binary_sort_node(root1,x);
        }
        else if(i==11){
            cout<<"please enter the value that you want to delete:";
            int x;
            cin>>x;
            ops.delete_binary_sort_node(root1,x);
        }
        else if(i==12){
            ops.root_first_traversal_with_stack(root1);
        }
        else if(i==13){
            ops.layer_by_layer_traversal(root1);
        }
    }
//    root1 = create_binary_sort_tree();
//    ops.root_first_traversal_with_stack(root1);
    return 0;
}

Node* create_binary_sort_tree(){
    Node* root1;
    bool is_new = true;
    for (;;) {
        int a;
        cin>>a;
        if (a==0){
            break;
        }
        if (is_new){
            root1 = new Node(a);
            is_new = false;
        } else{
            ops.create_binary_sort(root1,a);
        }
    }
    return root1;
}

