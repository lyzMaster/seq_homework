package StackInterface;

public interface StackInterface {
    // 入栈
    public void push(long j); // put item on top of stack
    // 出栈
    public void pop(); // take item from top of stack
    // 返回栈顶元素
    public long StackTop();
    // true if stack is empty
    public boolean isEmpty();
    // true if stack is full
    public boolean isFull();

}
