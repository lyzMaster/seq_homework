package StackInterface;

public class tset {
    public static void main(String[] args){
        StackOps ops = new StackOps();
        System.out.println();
        ops.push(100);
        ops.push(1000);
        ops.push(10000);
        ops.push(100000);
        ops.push(1000000);
        ops.pop();
        System.out.println(ops.StackTop());
    }
}
