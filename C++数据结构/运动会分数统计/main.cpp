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
    int score[21];   //最多能取前20名
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
    cout<<"********* "<<school[n].school_name<<" (id:"<<school[n].code<<") 的个人成绩报表: *********"<<endl;
    cout<<endl;
    if(school[n].person_num==0){
        cout<<"****** 此学校无人参赛！******"<<endl;
    }
    else{
        cout<<setw(10)<<setiosflags(ios::left)<<"姓名";
        cout<<setw(10)<<setiosflags(ios::left)<<"项目ID";
        cout<<setw(13)<<setiosflags(ios::left)<<"项目名称";
        cout<<setw(10)<<setiosflags(ios::left)<<"名次";
        cout<<setw(10)<<setiosflags(ios::left)<<"得分"<<endl;
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
    cout<<"********* "<<school[n].school_name<<" (id:"<<school[n].code<<") 的团体成绩报表: *********"<<endl;
    cout<<endl;
    if(school[n].person_num==0){
        cout<<"****** 此学校无人参赛！******"<<endl;
    }
    else{
            cout<<setw(10)<<setiosflags(ios::left)<<"团队";
            cout<<setw(10)<<setiosflags(ios::left)<<"总得分"<<endl;
            cout<<endl;
            cout<<setw(10)<<setiosflags(ios::left)<<"男团";
            cout<<setw(10)<<setiosflags(ios::left)<<school[n].man_score<<endl;
            cout<<endl;
            cout<<setw(10)<<setiosflags(ios::left)<<"女团";
            cout<<setw(10)<<setiosflags(ios::left)<<school[n].woman_score<<endl;
            cout<<endl;
            cout<<setw(10)<<setiosflags(ios::left)<<"总和";
            cout<<setw(10)<<setiosflags(ios::left)<<school[n].woman_score+school[n].man_score<<endl;
            cout<<endl;
    }
}

void print_all_school_group_score(){
    cout<<"********* 各学校的团体成绩报表: *********"<<endl;
    cout<<endl;
    cout<<setw(10)<<setiosflags(ios::left)<<"学校ID";
    cout<<setw(13)<<setiosflags(ios::left)<<"学校名称";
    cout<<setw(10)<<setiosflags(ios::left)<<"男团得分";
    cout<<setw(10)<<setiosflags(ios::left)<<"女团得分";
    cout<<setw(10)<<setiosflags(ios::left)<<"总得分"<<endl;
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
    cout<<"************** 运动会成绩管理系统 **************"<<endl;
    cout<<endl;
    cout<<"1.显示所有学校的团体成绩"<<endl;
    cout<<endl;
    cout<<"2.显示指定学校的团体成绩"<<endl;
    cout<<endl;
    cout<<"3.显示指定学校的成绩报表"<<endl;
    cout<<endl;
    cout<<"4.学校信息增删操作说明"<<endl;
    cout<<endl;
    cout<<"5.运动项目增删操作说明"<<endl;
    cout<<endl;
    cout<<"6.运动员信息增删操作说明"<<endl;
    cout<<endl;
    cout<<"7.退出系统"<<endl;
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
        cout<<"请选择操作序号: ";
        cin>>c;
        if(c==1){
            system("cls");
            print_all_school_group_score();
            system("pause");
        }
        else if(c==2){
            system("cls");
            for(;;){
                cout<<"请输入学校编号(参加本次运动会学校共"<<SCHOOL_NUM<<"所，编号为1-"<<SCHOOL_NUM<<"):";
                int n;
                cin>>n;
                system("cls");
                print_school_group_score(n);
                cout<<"1.继续查询"<<endl;
                cout<<"2.返回主菜单"<<endl;
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
                cout<<"请输入学校编号(参加本次运动会学校共"<<SCHOOL_NUM<<"所，编号为1-"<<SCHOOL_NUM<<"):";
                int n;
                cin>>n;
                system("cls");
                print_school_person_score(n);
                cout<<"1.继续查询"<<endl;
                cout<<"2.返回主菜单"<<endl;
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
            cout<<"请修改student.txt中的学校信息块："<<endl;
            cout<<endl;
            cout<<"格式："<<endl;
            cout<<"第一个数字为：参赛学校数量;"<<endl;
            cout<<"往后每行均为一个学校名称;"<<endl;
            cout<<"系统会按照学校顺序自动给每个学校排ID，从1开始，往后依次加1"<<endl;
            cout<<endl;
            cout<<"例如："<<endl;
            cout<<"4"<<endl;
            cout<<"上海师范大学"<<endl;
            cout<<"上海第二工业大学"<<endl;
            cout<<"上海理工大学"<<endl;
            cout<<"复旦大学"<<endl;
            cout<<endl;
            cout<<"修改后重新启动程序即可！"<<endl;
            cout<<endl;
            system("pause");
        }
        else if(c==5){
            system("cls");
            cout<<endl;
            cout<<"请修改item.txt中项目信息块："<<endl;
            cout<<endl;
            cout<<"格式："<<endl;
            cout<<"第一行两个数字为：男生项目数量  女生项目数量;"<<endl;
            cout<<endl;
            cout<<"往后每行均为一个项目名称、项目得分人数、项目能得分人所得分数;"<<endl;
            cout<<endl;
            cout<<"系统会按照项目顺序自动给每个项目排ID，从1开始，往后依次加1"<<endl;
            cout<<endl;
            cout<<"***************注意*******************"<<endl;
            cout<<"若按照系统默认分数,即取3人时得分(5,3,2)或取5人时得分(7,5,3,2,1),则第三个参数输入0即可"<<endl;
            cout<<"**************************************"<<endl;
            cout<<endl;
            cout<<"例如："<<endl;
            cout<<"2 3"<<endl;
            cout<<"男子跳远 3 0 (此项目取前3名，并按照默认排分(5,3,2)"<<endl;
            cout<<"男子撑杆跳 5 0 (此项目取前5名，并按照默认排分(7,5,3,2,1)"<<endl;
            cout<<"女子50米跑 2 5 3 (此项目取前2名，排分标准为第1名5分，第2名3分"<<endl;
            cout<<"女子跳绳"<<endl;
            cout<<"女子跳高"<<endl;
            cout<<"女子网球"<<endl;
            cout<<endl;
            cout<<"修改后重新启动程序即可！"<<endl;
            cout<<endl;
            system("pause");
        }

        else if(c==6){
            system("cls");
            cout<<endl;
            cout<<"请修改person.txt中运动员信息块："<<endl;
            cout<<endl;
            cout<<"格式："<<endl;
            cout<<"第一行数字为：参赛运动员人数;"<<endl;
            cout<<"往后每行4个数据：运动员姓名  运动员学校ID  运动员所参加项目  运动员在此项目中获得名次"<<endl;
            cout<<"系统会按照项目顺序自动给每位运动员排ID，从1开始，往后依次加1"<<endl;
            cout<<"系统会按照运动员所参与项目自动判断性别"<<endl;
            cout<<endl;
            cout<<"例如："<<endl;
            cout<<"4"<<endl;
            cout<<"李华 1 2 3 (意为：李华来自ID为1的学校，在ID为2的项目中排名为第3名)"<<endl;
            cout<<"王红 3 1 1"<<endl;
            cout<<"李明 5 3 2"<<endl;
            cout<<"郑明 3 3 7"<<endl;
            cout<<"李行 3 3 3"<<endl;
            cout<<"刘杨 6 6 4"<<endl;
            cout<<endl;
            cout<<"修改后重新启动程序即可！"<<endl;
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

