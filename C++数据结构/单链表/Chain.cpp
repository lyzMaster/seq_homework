#include "Chain.h"
#include <iostream>

using namespace std;

Node* Chain::create(){      //rear create with head
    Node* current;
    current = head;
    for (;;){
        int x;
        cin>>x;
        if (x==-1){
            break;
        }
        Node* node = new Node(x);
        current->next = node;
        current = node;
        current->next = nullptr;
    }
    return head;
}

void Chain::print_ele(){
    cout<<"head";
    Node* current = head;
    while (current->next){
        current = current->next;
        cout<<"->";
        cout<<current->get_value();
    }
    cout<<endl;
}

int Chain::get_length(){   //include head.
    int count = 0;
    Node* current = head;
    while (current->next){
        current = current->next;
        count++;
    }
    return count;
}

Node* Chain::search(int value){
    Node* current = head;
    int count = 0;
    while (current->next){
        current = current->next;
        count++;     //this is compare time.
        if (current->get_value()==value){
            return current;
        }
    }
}

void Chain::insert(int position,int value){
    Node* node = new Node(value);
    Node* current = head;
    for (int i=1;i<position;i++){
        current = current->next;
    }
    node->next = current->next;
    current->next = node;
}


void Chain::delete_ele_by_value(int value){
    Node* current = head;
    int count = 0;
    while (current->next){
        count++;      //this is compare time.
        if (current->next->get_value()==value){
            current->next = current->next->next;
            break;
        }
        current = current->next;
    }
}

void Chain::insertion_sort() {
    Node *current = head->next;
    Node *new_head = new Node;
    new_head->next = new Node(current->get_value());
    Node *pointer = new_head;
    bool inserted = false;
    while (current->next) {
        while (pointer->next) {
            if (current->next->get_value() <= pointer->next->get_value()) {
                Node *node = new Node(current->next->get_value());
                node->next = pointer->next;
                pointer->next = node;
                inserted = true;
                break;
            }
            pointer = pointer->next;
        }
        if (!inserted) {
            Node *node = new Node(current->next->get_value());
            pointer->next = node;
        }
        pointer = new_head;
        current = current->next;
        inserted = false;
        head = new_head;
    }
}

void Chain::invert() {
    Node* current,*next_current;
    current = next_current = head->next;
    head->next = nullptr;
    while (next_current){
        current = next_current;
        next_current = next_current->next;
        current->next = head->next;
        head->next = current;
    }
}

void Chain::merge(Node* head1){
    Node* l1 = head->next;
    Node* l2 = head1->next;
    Node* new_head = new Node;
    Node* current = new_head;
    while (l1&&l2){
        if (l1->get_value() < l2->get_value()){
            current->next = l1;
            l1 = l1->next;
        } else if (l1->get_value() > l2->get_value()){
            current->next = l2;
            l2 = l2->next;
        } else if (l1->get_value() == l2->get_value()){
            current->next = l1;
            l1 = l1->next;
            l2 = l2->next;
        }
        current = current->next;
    }
    if (l1){
        current->next = l1;
    }
    if (l2){
        current->next = l2;
    }
    head = new_head;
}

void Chain::split(){
    int count = 1;
    Node* new_head = new Node;
    Node* new_current = new_head;
    Node* current = head->next;
    Node* last_current = head;
    while (current){
        if (count%2==0){
            new_current->next = current;
            current = current->next;
            new_current = new_current->next;
            new_current->next = nullptr;
        } else{
            last_current->next = current;
            current = current->next;
            last_current = last_current->next;
            last_current->next = nullptr;
        }
        count++;
    }
    print_node_ele(new_head);
}

void Chain::print_node_ele(Node* node){
    cout<<"head";
    Node* current = node;
    while (current->next){
        current = current->next;
        cout<<"->";
        cout<<current->get_value();
    }
    cout<<endl;
}

