#include <iostream>
#include "Seq.h"
using namespace std;

const int maxx=1000;
Seq seq;

Seq Seq::creat(int length){
    seq.length = length;
    int x;
    for (int i = 0; i < length; i++) {
        cin>>x;
        seq.ele[i] = x;
    }
    return seq;
}

void Seq::print_ele(){
    for (int i = 0; i < seq.length; i++) {
        cout<<seq.ele[i];
        if (i!=seq.length-1){
            cout<<"->";
        } else{
            cout<<endl;
        }
    }
}


int Seq::search_ele(int x){
    int count = 0;
    bool is_searched = false;
    for (int i = 0; i < seq.length; i++) {
        count++;
        if (seq.ele[i]==x){
            is_searched = true;
            break;
        }
    }
    if(is_searched){
        return count-1;
    } else{
        return -1;
    }
}

int Seq::delete_ele(int x){
    int pointer = Seq::search_ele(x);
    int count = 0;
    if (pointer==-1){
        cout<<"no such element to delete";
        exit(-1);
    } else{
        for (int i = pointer; i < seq.length; i++) {
            seq.ele[i] = seq.ele[i+1];
            count++;
        }
        seq.length--;
    }
    return count;
};

void Seq::selection_sort(){
    int begin=1;
    for (int i = 1; i <= seq.length-1; i++) {
        int min = seq.ele[begin-1];
        int count = 0,final_count = 0;
        for (int j = begin; j < seq.length; j++) {
            if (min<=seq.ele[j]){
                count++;
                continue;
            } else{
                count++;
                min = seq.ele[j];
                final_count = count;
            }
        }
        int xx = seq.ele[begin-1+final_count];
        int xxx = seq.ele[begin-1];
        seq.ele[begin-1+final_count] = seq.ele[begin-1];
        seq.ele[begin-1] = min;
        begin++;
    }
}


void Seq::quick_sort(int begin, int end){
    int baseline = seq.ele[(begin+end)/2];
    int low = begin, high = end;
    while (low<=high){
        while (seq.ele[low]<baseline&&low<=high){
            low++;
        }
        while (seq.ele[high]>baseline&&low<=high){
            high--;
        }
        if (low<=high){
            int temp = seq.ele[low];
            seq.ele[low] = seq.ele[high];
            seq.ele[high] = temp;
            high--;
            low++;
        }
    }
    if (high>begin){
        quick_sort(begin,high);
    }
    if (low>begin){
        quick_sort(low,end);
    }
}

void Seq::invert(){
    int length = seq.length-1;
    for (int i = 0; i < length/2+1; i++) {
        int temp = seq.ele[i];
        seq.ele[i] = seq.ele[length-i];
        seq.ele[length-i] = temp;
    }
}

int Seq::half_search(int x){
    int begin = 0,end = seq.length-1;
    int count=0;  //比较次数
    while (begin<=end){
        int mid = (begin+end)/2;
        count++;
        if (seq.ele[mid]==x){
            return mid;
        } else if (x>seq.ele[mid]){
            begin = mid+1;
        } else if (x<seq.ele[mid]){
            end = mid-1;
        }
    }
    return begin;
}


void Seq::insert(int x){
    int pos = Seq::half_search(x);
    int move_count = 0;   //移动次数，比较次数在二分查找函数里
    seq.length++;
    if (seq.length>maxx){
        cout<<"out of bound!"<<endl;
        exit(-1);
    }
    for (int i = seq.length-1; i > pos; i--) {
        seq.ele[i] = seq.ele[i-1];
        move_count++;
    }
    seq.ele[pos] = x;
}


//void Seq::delete_range(int minn, int maxx){
//    int pos_list[seq.length],pos=0;
//    pos_list[0] = 0;
//    for (int i = 0; i < seq.length; i++) {
//        if (seq.ele[i]>=minn && seq.ele[i]<=maxx){
//            pos++;
//            pos_list[pos] = i;
//        }
//    }
//    int count = 0;
//    for (int i=1;i <= pos;i++){
//        while (pos_list[i]-pos_list[i-1]<=1&&i<=pos){
//            count++;
//            i++;
//        }
//        for (int j = pos_list[i-1]+1; j <= pos_list[i]-1; j++) {
//            int a = seq.ele[j-count],b = seq.ele[j];
//            seq.ele[j-1-count] = seq.ele[j];
//        }
//    }
//    seq.print_ele();
//    count++;
//    for (int j = pos_list[pos]+1; j <= seq.length-1; j++) {
//        int a = seq.ele[j-count],b = seq.ele[j];
//        seq.ele[j-1-count] = seq.ele[j];
//    }
//    seq.length = seq.length-pos;
//}

void Seq::delete_range(int minn, int maxx){
    int pos_list[seq.length+2],pos=0;
    for (int i = 0; i < seq.length; i++) {
        if (seq.ele[i]>=minn && seq.ele[i]<=maxx){
            pos++;
            pos_list[pos] = i;
        }
    }
    if (pos_list[1] == 0){
        pos_list[0] = 0;
    } else{
        pos_list[0] = -1;
    }
    if (pos_list[pos] == seq.length-1){
        pos_list[pos+1] = 0;
    } else{
        pos_list[pos+1] = -1;
    }

    if (pos_list[0]==0){
        int i;
        for (i = 1; i < pos;) {
            while (pos_list[i+1]-pos_list[i]==1){
                i++;
            }
            for (int j = pos_list[i]+1; j < pos_list[i+1]; j++) {
                int a = seq.ele[j-i],b = seq.ele[j];
                seq.ele[j-i] = seq.ele[j];
            }
        }
        if (pos_list[pos+1]==-1){
            i++;
            for (int k=pos_list[pos]+1;k < seq.length;k++){
                int a = seq.ele[k-i],b = seq.ele[k];
                seq.ele[k-i] = seq.ele[k];
            }
        }
    }

}


void Seq::merge_list(Seq seq2){
    int merged[seq.length+seq2.length];
    int short_one,large_one;
    if (seq.length>=seq2.length){
        short_one = seq2.length;
        large_one = seq.length;
    } else{
        short_one = seq.length;
        large_one = seq2.length;
    }
    int pointer_i = 0,pointer_j = 0,pointer_merge = 0;
//    for (int i=0;i<seq.length;i++){
//        for (int j=0;j<seq2.length;j++){
//            if (seq.ele[i]<seq2.ele[j]){
//                merged[pointer] = seq.ele[i];
//                continue;
//            }
//        }
//    }
    while (short_one>=0){
        if (seq.ele[pointer_i]<seq2.ele[pointer_j]){
            merged[pointer_merge] = seq.ele[pointer_i];
            pointer_i++;
            pointer_merge++;
        }
        else if(seq.ele[pointer_i]>seq2.ele[pointer_j]){
            merged[pointer_merge] = seq.ele[pointer_i];
            pointer_j++;
            pointer_merge++;
            short_one--;
        }
        else if(seq.ele[pointer_i]==seq2.ele[pointer_j]){

        }
    }
}



