#include <iostream>
#include "Seq.h"
using namespace std;

int main(){
    Seq ops;
    Seq seq1 = ops.creat(8);
    seq1.print_ele();
    seq1.delete_range(2,6);
    return 0;
}
