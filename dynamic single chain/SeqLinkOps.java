package SeqLink;

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
            if (head == null){
                head = node;
            }
            else {
                node.next = head;
                head = node;
            }

            //if中的可省略，why??
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
            current.next = node;    //????
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
        return 0;
    }

    @Override
    public SeqLink search(Object val) {
        return null;
    }

    @Override
    public SeqLink GetNode(int i) {
        return null;
    }

    @Override
    public void insert(Object val, Object linkVal) {

    }

    @Override
    public void InsertIndex(Object x, int i) {

    }

    @Override
    public void delete(Object val) {

    }

    @Override
    public void DeleteList(int i) {

    }
}
