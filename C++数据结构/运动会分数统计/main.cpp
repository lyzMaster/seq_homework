#include<iostream>
#include<cstdio>
#include<iomanip>
#include<cstdlib>
#include<fstream>
using namespace std;

const int MAX_SCHOOL_NUM = 20;
const int MAX_ITEM_NUM = 40;
const int MAX_PERSON_NUM = 100;

class Item{
public:
    string item_name;
    int code;
    int need_persons;
    int score[21];   //�����ȡǰ20��
};

class School{
public:
    string school_name;
    int code;
    int man_score;
    int woman_score;
    int person_code[MAX_PERSON_NUM+1];
    int person_num;
};

class Person{
public:
    string name;
    School school;
    Item item;
    int ranking;
    int score;
};

int SCHOOL_NUM = 0;
School school[MAX_SCHOOL_NUM+1];

int MAN_ITEM = 0;
int WOMEN_ITEM = 0;
Item item[MAX_ITEM_NUM+1];

int PERSON_NUM = 0;
Person person[MAX_PERSON_NUM+1];

//void read_data(){
//    int a = 1;
//    ifstream fin;
//    fin.open("data.txt");
//    fin>>SCHOOL_NUM;
//    for(int i=1;i<=SCHOOL_NUM;i++){
//        fin>>school[i].school_name;
//        school[i].code = a;
//        a++;
//    }
//
//    int b=1;
//    fin>>MAN_ITEM>>WOMEN_ITEM;
//    for(int i=1;i<=MAN_ITEM+WOMEN_ITEM;i++){
//        fin>>item[i].item_name>>item[i].need_persons;
//        for(int j=1;j<=item[i].need_persons;j++){
//            fin>>item[i].score[j];
//            if(item[i].need_persons==3&&item[i].score[1]==0){
//                item[i].score[1] = 5;
//                item[i].score[2] = 3;
//                item[i].score[3] = 2;
//                break;
//            }
//            else if(item[i].need_persons==5&&item[i].score[1]==0){
//                item[i].score[1] = 7;
//                item[i].score[2] = 5;
//                item[i].score[3] = 3;
//                item[i].score[4] = 2;
//                item[i].score[5] = 1;
//                break;
//            }
//        }
//        item[i].code = b;
//        b++;
//    }
//
//    fin>>PERSON_NUM;
//    for(int i=1;i<=PERSON_NUM;i++){
//        fin>>person[i].name;
//        int school_id;
//        fin>>school_id;
//        person[i].school = school[school_id];
//        int item_id;
//        fin>>item_id;
//        person[i].item = item[item_id];
//        fin>>person[i].ranking;
//    }
//    fin.close();
//}

void read_person(){
    ifstream fin;
    fin.open("person.txt");
    fin>>PERSON_NUM;
    for(int i=1;i<=PERSON_NUM;i++){
        fin>>person[i].name;
        int school_id;
        fin>>school_id;
        person[i].school = school[school_id];
        int item_id;
        fin>>item_id;
        person[i].item = item[item_id];
        fin>>person[i].ranking;
    }
    fin.close();
}

void read_item(){
    ifstream fin;
    fin.open("item.txt");
    int b=1;
    fin>>MAN_ITEM>>WOMEN_ITEM;
    for(int i=1;i<=MAN_ITEM+WOMEN_ITEM;i++){
        fin>>item[i].item_name>>item[i].need_persons;
        for(int j=1;j<=item[i].need_persons;j++){
            fin>>item[i].score[j];
            if(item[i].need_persons==3&&item[i].score[1]==0){
                item[i].score[1] = 5;
                item[i].score[2] = 3;
                item[i].score[3] = 2;
                break;
            }
            else if(item[i].need_persons==5&&item[i].score[1]==0){
                item[i].score[1] = 7;
                item[i].score[2] = 5;
                item[i].score[3] = 3;
                item[i].score[4] = 2;
                item[i].score[5] = 1;
                break;
            }
        }
        item[i].code = b;
        b++;
    }
    fin.close();

}

void read_school(){
    int a = 1;
    ifstream fin;
    fin.open("school.txt");
    fin>>SCHOOL_NUM;
    for(int i=1;i<=SCHOOL_NUM;i++){
        fin>>school[i].school_name;
        school[i].code = a;
        a++;
    }
    fin.close();
}

void set_school_man_woman_score(){
    for(int i=1;i<=SCHOOL_NUM;i++){
        school[i].man_score = 0;
        school[i].woman_score = 0;
        school[i].person_num = 0;

    }

    for(int i=1;i<=PERSON_NUM;i++){
        int person_score;
        person[i].score = 0;
        int school_code = person[i].school.code;
        if(person[i].ranking>person[i].item.need_persons){
            person_score = 0;
        }
        else{
            person_score = person[i].item.score[person[i].ranking];
            person[i].score = person_score;
        }

        if(person[i].item.code<=MAN_ITEM){   //man item
            school[school_code].man_score = school[school_code].man_score+person_score;   //update score of man or woman
            school[school_code].person_num++;
            school[school_code].person_code[school[school_code].person_num] = i;
        }
        else{  //woman item
            school[school_code].woman_score = school[school_code].woman_score+person_score;
            school[school_code].person_num++;
            school[school_code].person_code[school[school_code].person_num] = i;
        }
    }
}

void print_school_person_score(int n){
    cout<<"********* "<<school[n].school_name<<" (id:"<<school[n].code<<") �ĸ��˳ɼ�����: *********"<<endl;
    cout<<endl;
    if(school[n].person_num==0){
        cout<<"****** ��ѧУ���˲�����******"<<endl;
    }
    else{
        cout<<setw(10)<<setiosflags(ios::left)<<"����";
        cout<<setw(10)<<setiosflags(ios::left)<<"��ĿID";
        cout<<setw(13)<<setiosflags(ios::left)<<"��Ŀ����";
        cout<<setw(10)<<setiosflags(ios::left)<<"����";
        cout<<setw(10)<<setiosflags(ios::left)<<"�÷�"<<endl;
        cout<<endl;
        for(int i=1;i<=school[n].person_num;i++){
            cout<<setw(10)<<setiosflags(ios::left)<<person[school[n].person_code[i]].name;
            cout<<setw(10)<<setiosflags(ios::left)<<person[school[n].person_code[i]].item.code;
            cout<<setw(13)<<setiosflags(ios::left)<<person[school[n].person_code[i]].item.item_name;
            cout<<setw(10)<<setiosflags(ios::left)<<person[school[n].person_code[i]].ranking;
            cout<<setw(10)<<setiosflags(ios::left)<<person[school[n].person_code[i]].score;
            cout<<endl;
            cout<<endl;
        }
    }
}

void print_school_group_score(int n){
    cout<<"********* "<<school[n].school_name<<" (id:"<<school[n].code<<") ������ɼ�����: *********"<<endl;
    cout<<endl;
    if(school[n].person_num==0){
        cout<<"****** ��ѧУ���˲�����******"<<endl;
    }
    else{
            cout<<setw(10)<<setiosflags(ios::left)<<"�Ŷ�";
            cout<<setw(10)<<setiosflags(ios::left)<<"�ܵ÷�"<<endl;
            cout<<endl;
            cout<<setw(10)<<setiosflags(ios::left)<<"����";
            cout<<setw(10)<<setiosflags(ios::left)<<school[n].man_score<<endl;
            cout<<endl;
            cout<<setw(10)<<setiosflags(ios::left)<<"Ů��";
            cout<<setw(10)<<setiosflags(ios::left)<<school[n].woman_score<<endl;
            cout<<endl;
            cout<<setw(10)<<setiosflags(ios::left)<<"�ܺ�";
            cout<<setw(10)<<setiosflags(ios::left)<<school[n].woman_score+school[n].man_score<<endl;
            cout<<endl;
    }
}

void print_all_school_group_score(){
    cout<<"********* ��ѧУ������ɼ�����: *********"<<endl;
    cout<<endl;
    cout<<setw(10)<<setiosflags(ios::left)<<"ѧУID";
    cout<<setw(13)<<setiosflags(ios::left)<<"ѧУ����";
    cout<<setw(10)<<setiosflags(ios::left)<<"���ŵ÷�";
    cout<<setw(10)<<setiosflags(ios::left)<<"Ů�ŵ÷�";
    cout<<setw(10)<<setiosflags(ios::left)<<"�ܵ÷�"<<endl;
    cout<<endl;
    for(int i=1;i<=SCHOOL_NUM;i++){
        cout<<setw(10)<<setiosflags(ios::left)<<school[i].code;
        cout<<setw(15)<<setiosflags(ios::left)<<school[i].school_name;
        cout<<setw(10)<<setiosflags(ios::left)<<school[i].man_score;
        cout<<setw(10)<<setiosflags(ios::left)<<school[i].woman_score;
        cout<<setw(10)<<setiosflags(ios::left)<<school[i].man_score+school[i].woman_score;
        cout<<endl;
        cout<<endl;
    }
}

void menu(){
    system("cls");
    cout<<"************** �˶���ɼ�����ϵͳ **************"<<endl;
    cout<<endl;
    cout<<"1.��ʾ����ѧУ������ɼ�"<<endl;
    cout<<endl;
    cout<<"2.��ʾָ��ѧУ������ɼ�"<<endl;
    cout<<endl;
    cout<<"3.��ʾָ��ѧУ�ĳɼ�����"<<endl;
    cout<<endl;
    cout<<"4.ѧУ��Ϣ��ɾ����˵��"<<endl;
    cout<<endl;
    cout<<"5.�˶���Ŀ��ɾ����˵��"<<endl;
    cout<<endl;
    cout<<"6.�˶�Ա��Ϣ��ɾ����˵��"<<endl;
    cout<<endl;
    cout<<"7.�˳�ϵͳ"<<endl;
    cout<<endl;
}


int main(){
    read_school();
    read_item();
    read_person();
    set_school_man_woman_score();
    for(;;){
        menu();
        int c;
        cout<<"��ѡ��������: ";
        cin>>c;
        if(c==1){
            system("cls");
            print_all_school_group_score();
            system("pause");
        }
        else if(c==2){
            system("cls");
            for(;;){
                cout<<"������ѧУ���(�μӱ����˶���ѧУ��"<<SCHOOL_NUM<<"�������Ϊ1-"<<SCHOOL_NUM<<"):";
                int n;
                cin>>n;
                system("cls");
                print_school_group_score(n);
                cout<<"1.������ѯ"<<endl;
                cout<<"2.�������˵�"<<endl;
                int x;
                cin>>x;
                if(x==1){
                    system("cls");
                    continue;
                }
                else if(x==2){
                    break;
                }
            }
        }
        else if(c==3){
            system("cls");
            for(;;){
                cout<<"������ѧУ���(�μӱ����˶���ѧУ��"<<SCHOOL_NUM<<"�������Ϊ1-"<<SCHOOL_NUM<<"):";
                int n;
                cin>>n;
                system("cls");
                print_school_person_score(n);
                cout<<"1.������ѯ"<<endl;
                cout<<"2.�������˵�"<<endl;
                int x;
                cin>>x;
                if(x==1){
                    system("cls");
                    continue;
                }
                else if(x==2){
                    break;
                }
            }
        }
        else if(c==4){
            system("cls");
            cout<<endl;
            cout<<"���޸�student.txt�е�ѧУ��Ϣ�飺"<<endl;
            cout<<endl;
            cout<<"��ʽ��"<<endl;
            cout<<"��һ������Ϊ������ѧУ����;"<<endl;
            cout<<"����ÿ�о�Ϊһ��ѧУ����;"<<endl;
            cout<<"ϵͳ�ᰴ��ѧУ˳���Զ���ÿ��ѧУ��ID����1��ʼ���������μ�1"<<endl;
            cout<<endl;
            cout<<"���磺"<<endl;
            cout<<"4"<<endl;
            cout<<"�Ϻ�ʦ����ѧ"<<endl;
            cout<<"�Ϻ��ڶ���ҵ��ѧ"<<endl;
            cout<<"�Ϻ�����ѧ"<<endl;
            cout<<"������ѧ"<<endl;
            cout<<endl;
            cout<<"�޸ĺ������������򼴿ɣ�"<<endl;
            cout<<endl;
            system("pause");
        }
        else if(c==5){
            system("cls");
            cout<<endl;
            cout<<"���޸�item.txt����Ŀ��Ϣ�飺"<<endl;
            cout<<endl;
            cout<<"��ʽ��"<<endl;
            cout<<"��һ����������Ϊ��������Ŀ����  Ů����Ŀ����;"<<endl;
            cout<<endl;
            cout<<"����ÿ�о�Ϊһ����Ŀ���ơ���Ŀ�÷���������Ŀ�ܵ÷������÷���;"<<endl;
            cout<<endl;
            cout<<"ϵͳ�ᰴ����Ŀ˳���Զ���ÿ����Ŀ��ID����1��ʼ���������μ�1"<<endl;
            cout<<endl;
            cout<<"***************ע��*******************"<<endl;
            cout<<"������ϵͳĬ�Ϸ���,��ȡ3��ʱ�÷�(5,3,2)��ȡ5��ʱ�÷�(7,5,3,2,1),���������������0����"<<endl;
            cout<<"**************************************"<<endl;
            cout<<endl;
            cout<<"���磺"<<endl;
            cout<<"2 3"<<endl;
            cout<<"������Զ 3 0 (����Ŀȡǰ3����������Ĭ���ŷ�(5,3,2)"<<endl;
            cout<<"���ӳŸ��� 5 0 (����Ŀȡǰ5����������Ĭ���ŷ�(7,5,3,2,1)"<<endl;
            cout<<"Ů��50���� 2 5 3 (����Ŀȡǰ2�����ŷֱ�׼Ϊ��1��5�֣���2��3��"<<endl;
            cout<<"Ů������"<<endl;
            cout<<"Ů������"<<endl;
            cout<<"Ů������"<<endl;
            cout<<endl;
            cout<<"�޸ĺ������������򼴿ɣ�"<<endl;
            cout<<endl;
            system("pause");
        }

        else if(c==6){
            system("cls");
            cout<<endl;
            cout<<"���޸�person.txt���˶�Ա��Ϣ�飺"<<endl;
            cout<<endl;
            cout<<"��ʽ��"<<endl;
            cout<<"��һ������Ϊ�������˶�Ա����;"<<endl;
            cout<<"����ÿ��4�����ݣ��˶�Ա����  �˶�ԱѧУID  �˶�Ա���μ���Ŀ  �˶�Ա�ڴ���Ŀ�л������"<<endl;
            cout<<"ϵͳ�ᰴ����Ŀ˳���Զ���ÿλ�˶�Ա��ID����1��ʼ���������μ�1"<<endl;
            cout<<"ϵͳ�ᰴ���˶�Ա��������Ŀ�Զ��ж��Ա�"<<endl;
            cout<<endl;
            cout<<"���磺"<<endl;
            cout<<"4"<<endl;
            cout<<"� 1 2 3 (��Ϊ�������IDΪ1��ѧУ����IDΪ2����Ŀ������Ϊ��3��)"<<endl;
            cout<<"���� 3 1 1"<<endl;
            cout<<"���� 5 3 2"<<endl;
            cout<<"֣�� 3 3 7"<<endl;
            cout<<"���� 3 3 3"<<endl;
            cout<<"���� 6 6 4"<<endl;
            cout<<endl;
            cout<<"�޸ĺ������������򼴿ɣ�"<<endl;
            cout<<endl;
            system("pause");
        }

        else if(c==7){
            break;
        }

        else{
            continue;
        }
    }

    return 0;
}

