#include "myQueue.h"
#include <iostream>
using namespace std;

int main(){
    queue* queue1 = new queue;

    init(queue1);
    cout<<isEmpty(queue1)<<endl;
    cout<<size(queue1)<<endl;
    deQueue(queue1);
    enQueue(queue1,8888);
    enQueue(queue1,899);
    enQueue(queue1,888998);
    enQueue(queue1,887688);
    enQueue(queue1,887688);
    enQueue(queue1,887688);
    cout<<isEmpty(queue1)<<endl;
    cout<<size(queue1)<<endl;
    cout<<queueFront(queue1)<<endl;
    deQueue(queue1);
    cout<<isEmpty(queue1)<<endl;
    cout<<size(queue1)<<endl;
    cout<<queueFront(queue1)<<endl;
    return 0;
}


