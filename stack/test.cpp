#include "myQueue.h"
#include <iostream>
using namespace std;

int main(){
    stack* stack1 = new stack;
    init(stack1);
    pop(stack1);
    cout<<stackTop(stack1)<<endl;
    push(stack1,100);
    push(stack1,2);
    push(stack1,3);
    push(stack1,4);
    push(stack1,666);
    push(stack1,6654);
    pop(stack1);
    pop(stack1);
    cout<<stackTop(stack1)<<endl;
    cout<<stack1->top<<endl;
    return 0;
}


