#include <iostream>
#include <cmath>
#include "Chain.h"
#include "LinkStack.h"
using namespace std;

void ten2eight();
void eight2ten();

int main() {
    cout<<"=====welcome to operate Link====="<<endl;
    cout<<"1:create Link"<<endl;
    cout<<"2:print elements of Link"<<endl;
    cout<<"3:get the length of Link"<<endl;
    cout<<"4:insert a Node to Link"<<endl;
    cout<<"5:delete a Node by Value"<<endl;
    cout<<"6:insertion sort"<<endl;
    cout<<"7:invert a Link"<<endl;
    cout<<"8:merge the Link with another"<<endl;
    cout<<"9:split the Link"<<endl;
    cout<<"10:Decimal to Octal"<<endl;
    cout<<"11:Octal to Decimal"<<endl;
    cout<<"12:exit"<<endl;

    Chain chain1;

    while (1){
        int i;
        cin>>i;
        if (i==1){
            cout<<"please enter value,end with '-1':"<<endl;
            chain1.create();
        }

        else if (i==2){
            chain1.print_ele();
        }

        else if (i==3){
            cout<<"length is:"<<chain1.get_length()<<endl;
        }

        else if (i==4){
            cout<<"please enter Position and Value:";
            int pos,val;
            cin>>pos>>val;
            chain1.insert(pos,val);
        }

        else if (i==5){
            cout<<"please enter the Value which you want to delete:";
            int val;
            chain1.delete_ele_by_value(val);
        }

        else if (i==6){
            cout<<"insertion sort of the Link"<<endl;
            chain1.insertion_sort();
            cout<<"successful!"<<endl;
        }

        else if (i==7){
            cout<<"invert the Link"<<endl;
            chain1.invert();
            cout<<"successful!"<<endl;
        }

        else if (i==8){
            Chain chain2;
            cout<<"please enter values of a new Link"<<endl;
            Node* node = chain2.create();
            chain1.merge(node);
        }

        else if (i==9){
            chain1.split();
            cout<<"split successfully!";
            chain1.print_ele();
        }

        else if (i==10){
            cout<<"please enter the Decimal value:";
            ten2eight();
        }

        else if (i==11){
            cout<<"please enter the Octal value,end with '=':";
            eight2ten();
        }

        else if (i==12){
            cout<<"exit? Y/N:";
            char x;
            cin>>x;
            if (x=='Y'||x=='y'){
                break;
            }
            else{
                continue;
            }
        }

        else{
            cout<<"error code!again:";
            continue;
        }
    }


    eight2ten();
}

void ten2eight(){
    LinkStack stack;
    int x;
    cin>>x;
    while (x){
        stack.push(x%8);
        x = x/8;
    }
    stack.print_stack();
    cout<<endl;
}


//八进制转十进制
void eight2ten(){
    LinkStack stack1;
    while (1){
        char i;
        cin>>i;
        if (int(i)==61){
            break;
        }
        stack1.push(int(i)-48);
    }
    int num = 0,sum = 0;
    while (stack1.top){
        sum = sum + stack1.get_top()*pow(8,num);
        num++;
        stack1.pop();
    }
    cout<<sum<<endl;
}