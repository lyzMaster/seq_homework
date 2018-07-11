#include <iostream>
#include <cmath>
#include <cstdlib>
using namespace std;

class Seq{
public:
    double coe;
    int exp;
    Seq* next;
    Seq();
    Seq(double coe,int exp);
};

Seq::Seq(){
    next = nullptr;
}

Seq::Seq(double coee, int expp) {
    coe = coee;
    exp = expp;
    next = nullptr;
}

Seq* create(){
    double a=1;
    int b=1;
    Seq* head = new Seq;
    Seq* current = head;
    bool first = true;
    while (1){
        cin>>a;
        cin>>b;
        if(a==0&&b==0){
            if(first){
                return nullptr;
            }
            break;
        }
        Seq* node = new Seq(a,b);
        current->next = node;
        current = current->next;
        first = false;
    }
    return head;
}

int get_length(Seq* seq){
    Seq* temp = seq->next;
    int count = 0;
    while(temp){
        if(temp->coe==0){
            temp = temp->next;
            continue;
        }
        count++;
        temp = temp->next;
    }
    return count;
}

void print_ele(Seq* seq){
    int length = get_length(seq);
    seq = seq->next;
    if(length==0){
        cout<<0<<endl;
        return;
    }
    while (seq){
        if(seq->coe==0){
            seq = seq->next;
            continue;
        }
        cout<<seq->coe<<",";
        cout<<seq->exp<<"  ";
        seq = seq->next;
    }
    cout<<endl;
}

void print_format(Seq* seq){
    int length = get_length(seq);
    seq = seq->next;
    if(length==0){
        cout<<0<<endl;
        return;
    }
    bool first = true;
    while (seq){
        if(seq->coe==0){
            seq = seq->next;
            continue;
        }
        if(seq->coe>0&&first==false){
            cout<<"+";
        }
        if(seq->coe!=1&&seq->coe!=-1){
            cout<<seq->coe;
        }
        else if((seq->coe==1&&seq->exp==0)||(seq->coe==-1&&seq->exp==0)){
            cout<<seq->coe;
        }
        else if(seq->coe==-1&&seq->exp!=0){
            cout<<"-";
        }
        first = false;
        if (seq->exp!=0){
            cout<<"x";
            if(seq->exp!=1){
                cout<<"^"<<seq->exp;
            }
        }
        seq = seq->next;
    }
}

Seq* insertion_sort(Seq* head) {
    Seq *current = head->next;
    Seq *new_head = new Seq;
    new_head->next = new Seq(current->coe,current->exp);
    Seq *pointer = new_head;
    bool inserted = false;
    while (current->next) {
        while (pointer->next) {
            if (current->next->exp >= pointer->next->exp) {
                Seq *node = new Seq(current->next->coe,current->next->exp);
                node->next = pointer->next;
                pointer->next = node;
                inserted = true;
                break;
            }
            pointer = pointer->next;
        }
        if (!inserted) {
            Seq *node = new Seq(current->next->coe,current->next->exp);
            pointer->next = node;
        }
        pointer = new_head;
        current = current->next;
        inserted = false;
        head = new_head;
    }
    return head;
}

Seq* add(Seq* seq1,Seq* seq2){
    Seq* l1 = seq1->next;
    Seq* l2 = seq2->next;
    Seq* new_head = new Seq;
    Seq* current = new_head;
    while (l1&&l2){
        if (l1->exp > l2->exp){
            current->next = l1;
            l1 = l1->next;
        } else if (l1->exp < l2->exp){
            current->next = l2;
            l2 = l2->next;
        } else if (l1->exp == l2->exp){
            l1->coe = l1->coe+l2->coe;
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
    return new_head;
}

Seq* reduce(Seq* seq1,Seq* seq2){
    Seq* seq2_copy = seq2->next;
    while (seq2_copy){
        seq2_copy->coe = -seq2_copy->coe;
        seq2_copy = seq2_copy->next;
    }
    return add(seq1,seq2);
}

Seq* de_repeat(Seq* seq){
    Seq* current = seq->next;
    Seq* current_next = current->next;
    while (current_next){
        if(current->exp==current_next->exp){
            current_next->coe = current->coe+current_next->coe;
            Seq* will_del = current_next;
            *current = *current_next;
            delete(will_del);
        }
        current = current_next;
        current_next = current_next->next;
    }
    return seq;
}

double cal_poly(Seq* seq,double x){
    double sum = 0;
    seq = seq->next;
    while (seq){
        sum+=seq->coe*pow(x,seq->exp);
        seq = seq->next;
    }
    return sum;
}

Seq* derivative(Seq* seq){
    Seq* der = new Seq;
    Seq* current = der;
    seq = seq->next;
    while (seq){
        double a = seq->coe*seq->exp;
        int b = seq->exp-1;
        Seq* node = new Seq(a,b);
        current->next = node;
        current = current->next;
        seq = seq->next;
    }
    return der;
}

Seq* multiply(Seq* seq1,Seq* seq2){
    Seq* muti = new Seq;
    Seq* current = muti;
    seq1 = seq1->next;
    seq2 = seq2->next;
    Seq* seq1_head = seq1;
    while (seq2){
        while(seq1){
            double a = seq1->coe*seq2->coe;
            int b = seq1->exp+seq2->exp;
            Seq* node = new Seq(a,b);
            current->next = node;
            current = current->next;
            seq1 = seq1->next;
        }
        seq1 = seq1_head;    //忘记把seq1调整到头部
        seq2 = seq2->next;
    }
    return muti;
}

void main_menu(){
    cout<<"********* 一元稀疏多项式简单计算器 *********"<<endl;
    cout<<endl;
    cout<<"1.单个多项式操作"<<endl;
    cout<<"2.两个多项式运算操作，并对运算结果进行多项式操作"<<endl;
    cout<<"3.退出"<<endl;
}

void sigle_menu(){
    cout<<"******* 单个多项式操作 *******"<<endl;
    cout<<"1.对此多项式按 *整数序列形式* 输出"<<endl;
    cout<<"2.对此多项式按 *类数学表达式* 输出"<<endl;
    cout<<"3.计算该多项式在x处的值"<<endl;
    cout<<"4.计算该多项式的导函数"<<endl;
    cout<<"5.返回主菜单"<<endl;
    cout<<endl;
}

void muti_menu_one(){
    cout<<"******* 两个多项式操作 *******"<<endl;
    cout<<"1.对两个多项式进行 加减乘 运算"<<endl;
}

void muti_menu_two(){
    cout<<"******* 对得到的结果多项式进行操作 *******"<<endl;
    cout<<"1.对结果多项式按 *整数序列形式* 输出"<<endl;
    cout<<"2.对结果多项式按 *类数学表达式* 输出"<<endl;
    cout<<"3.计算结果多项式在x处的值"<<endl;
    cout<<"4.计算结果多项式的导函数"<<endl;
    cout<<"5.返回主菜单"<<endl;
}

void tips(){
    cout<<"输入格式："<<endl;
    cout<<"每行两个数据："<<endl;
    cout<<"系数 次方数(中间空格隔开) 0 0 结束"<<endl;
    cout<<"注意：当一个多项式为0时，请直接输入 0 0 ！"<<endl;
    cout<<"例如："<<endl;
    cout<<"多项式：3x^12+5x^100+4x+6 的输入应为："<<endl;
    cout<<"3 12"<<endl;
    cout<<"5 100"<<endl;
    cout<<"4 1"<<endl;
    cout<<"6 0"<<endl;
    cout<<"0 0"<<endl;
    cout<<endl;
}

int main() {
    Seq* seq0;
    Seq* seq1;
    Seq* seq2;
    Seq* seq3;
    Seq* seq0_d;
    Seq* seq3_d;
    for(;;){
//        system("cls");
        main_menu();
        int i;
        cin>>i;
        if(i==1){
//            system("cls");
            cout<<"请按要求输入多项式相关信息！"<<endl;
            tips();
            cout<<"请输入:"<<endl;
            seq0 = create();
            cout<<endl;
            cout<<"创建成功！"<<endl;
            cout<<endl;
            if(!seq0){
                cout<<"warning!!! 0无法操作！重新输入！"<<endl;
                continue;
            }
            seq0 = insertion_sort(seq0);
            seq0 = de_repeat(seq0);
            sigle_menu();

            for(;;){
                cout<<"请输入命令:";
                int i1;
                cin>>i1;
                if(i1==1){
                    cout<<get_length(seq0)<<"  ";
                    print_ele(seq0);
                    cout<<endl;
                    cout<<endl;
                }
                else if(i1==2){
                    print_format(seq0);
                    cout<<endl;
                    cout<<endl;
                }
                else if(i1==3){
                    cout<<"请输入x：";
                    double i2;
                    cin>>i2;
                    cout<<cal_poly(seq0,i2);
                    cout<<endl;
                    cout<<endl;
                }
                else if(i1==4){
                    seq0_d = derivative(seq0);
                    cout<<"导函数为：";
                    print_format(seq0_d);
                    cout<<endl;
                    cout<<endl;
                }
                else if(i1==5){
                    break;
                }
            }
        }

        else if(i==2){
//            system("cls");
            muti_menu_one();
            cout<<"请按要求输入多项式相关信息！"<<endl;
            tips();
            cout<<"请输入第一个多项式:"<<endl;
            seq1 = create();
            cout<<endl;
            cout<<"创建成功！"<<endl;
            cout<<endl;
            cout<<"请输入第二个多项式:"<<endl;
            seq2 = create();
            cout<<endl;
            cout<<"创建成功！"<<endl;
            cout<<endl;
            cout<<"请输入操作：1.加；2.减；3.乘";
            cout<<endl;
            int p;
            cin>>p;
            if (seq1&&seq2){
                seq1 = insertion_sort(seq1);
                seq2 = insertion_sort(seq2);
                if(p==1){
                    seq3 = add(seq1,seq2);
                }
                else if(p==2){
                    seq3 = reduce(seq1,seq2);
                }
                else if(p==3){
                    seq3 = multiply(seq1,seq2);
                }
                else{
                    cout<<"error!!"<<endl;
                }
            }
            else if(!seq1&&seq2){
                seq2 = insertion_sort(seq2);
                if(p==1){
                    seq3 = seq2;
                }
                else if(p==2){
                    Seq* seq2_copy = seq2->next;
                    while (seq2_copy){
                        seq2_copy->coe = -seq2_copy->coe;
                        seq2_copy = seq2_copy->next;
                    }
                    seq3 = seq2;
                }
                else if(p==3){
                    cout<<"与0相乘结果是0，无法进行其他操作！"<<endl;
                    continue;
                }
                else{
                    cout<<"error!!"<<endl;
                    continue;
                }
            }
            else if(seq1&&!seq2){
                seq1 = insertion_sort(seq1);
                if(p==1){
                    seq3 = seq1;
                }
                else if(p==2){
                    seq3 = seq1;
                }
                else if(p==3){
                    cout<<"与0相乘结果是0，无法进行其他操作！"<<endl;
                    continue;
                }
                else{
                    cout<<"error!!"<<endl;
                    continue;
                }
            }
            cout<<"计算成功！"<<endl;
//            system("cls");
            muti_menu_two();
            for(;;){
                cout<<"请输入命令:";
                int i1;
                cin>>i1;
                if(i1==1){
                    cout<<get_length(seq3)<<"  ";
                    print_ele(seq3);
                    cout<<endl;
                    cout<<endl;
                }
                else if(i1==2){
                    print_format(seq3);
                    cout<<endl;
                    cout<<endl;
                }
                else if(i1==3){
                    cout<<"请输入x：";
                    double i2;
                    cin>>i2;
                    cout<<cal_poly(seq3,i2);
                    cout<<endl;
                    cout<<endl;
                }
                else if(i1==4){
                    seq3_d = derivative(seq3);
                    cout<<"导函数为：";
                    print_format(seq3_d);
                    cout<<endl;
                    cout<<endl;
                }
                else if(i1==5){
                    break;
                }
            }
        }

        else if(i==3){
            break;
        }

        else {
            cout<<"error!";
            continue;
        }

    }

    return 0;
}
