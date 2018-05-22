package StackInterface;

public class Stack {
    public int maxSize; // size of stack array
    public long[] stackArray;
    public int top; // top of stack
    public Stack(int s) {
        maxSize = s; // set array size
        stackArray = new long[maxSize]; // create array
        top = -1; // no items yet
    }

}
