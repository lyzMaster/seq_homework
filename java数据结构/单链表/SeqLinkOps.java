package SeqLink;

import java.util.NoSuchElementException;
import java.util.Scanner;

public class SeqLinkOps implements SeqLinkInterface{

    Scanner cin = new Scanner(System.in);
    SeqLink head = new SeqLink();

    @Override
    public void Rear_Create() {
        System.out.println("input data ends with 'endl'");
        SeqLink current = new SeqLink();
        current = head = null;
        for (;;){
            Object x = cin.next();
            if (x.equals("endl")){
                break;
            }
            SeqLink node = new SeqLink(x);
            if (head == null){
                head = node;
            }
            else {
                current.next = node;
            }
            current = node;
        }
        if (current!=null){
            current.next = null;
        }
    }

    @Override
    public void Front_Create() {
        System.out.println("input data ends with 'endl'");
        head = null;
        for (;;){
            Object x = cin.next();
            if (x.equals("endl")){
                break;
            }
            SeqLink node = new SeqLink(x);
//            if (head == null){
//                head = node;
//            }
//            else {
//                node.next = head;
//                head = node;
//            }
            node.next = head;
            head = node;        //这两行等价与以上。因为第一次时node.next=null，输出时，只输出null之前的，故没有影响。
        }
    }

    @Override
    public void Rear_Create_Head() {
        System.out.println("input data ends with 'endl'");
        SeqLink current = new SeqLink();
        current = head;
        for (;;){
            Object x = cin.next();
            if (x.equals("endl")){
                break;
            }
            SeqLink node = new SeqLink(x);
            current.next = node;
            current = node;
        }
        if (current!=null){
            current.next = null;
        }
    }

    @Override
    public void print() {
        for (SeqLink current = head; current!=null; current = current.next){
            System.out.print(current.data);
            if (current.next != null) {
                System.out.print("->");
            }
        }
    }

    @Override
    public int ListLength() {
        int sum = 0;
        for (SeqLink current = head; current!=null; current = current.next){
            sum++;
        }
        return sum;
    }

    @Override
    public SeqLink search(Object val) {
        for (SeqLink current = head; current!=null; current = current.next){
            if (val.equals(current.data)){
                return current;
            }
        }
        throw new NoSuchElementException();
    }

    @Override
    public SeqLink GetNode(int i) {
        int sum = 0;
        for (SeqLink current = head; current!=null; current = current.next){
            sum++;
            if (sum == i){
                return current;
            }
        }
        throw new IndexOutOfBoundsException();
    }

    @Override
    public void insert(Object val, Object linkVal) {
        SeqLink valClass = new SeqLink(val);
        boolean notequal = true;
        for (SeqLink current = head; current!=null; current = current.next){
            if (linkVal.equals(current.data)){
                valClass.next = current.next;
                current.next = valClass;
                notequal = false;
            }
        }
        if (notequal){
            valClass.next = head;
            head = valClass;
        }
    }

    @Override
    public void InsertIndex(Object x, int i) {
        SeqLink xClass = new SeqLink(x);
        if (i==1){
            xClass.next = head;
            head = xClass;
        }
        else {
            SeqLink noi = this.GetNode(i-1);
            xClass.next = noi.next;
            noi.next = xClass;
        }
    }

    @Override
    public void delete(Object val) {
        int sum = 0;
        boolean equal = false;
        for (SeqLink current = head;current!=null;current = current.next) {
            sum++;
            if (current.data.equals(val)){
                equal = true;
                break;
            }
        }
        if (equal){
            if (sum==1){
                SeqLink result = GetNode(sum+1);
                head = result;
            }
            else {
                SeqLink result = GetNode(sum);
                SeqLink result1 = GetNode(sum-1);
                result1.next = result.next;
            }
        }
        else {
            throw new NoSuchElementException();
        }

    }

    @Override
    public void DeleteList(int i) {
        SeqLink result = this.GetNode(i);
        this.delete(result.data);
    }
}
