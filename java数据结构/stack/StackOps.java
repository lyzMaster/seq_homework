package StackInterface;

public class StackOps implements StackInterface {
    Stack stack = new Stack(5);

    @Override
    public void push(long j) {
        if (isFull()){
            throw new IndexOutOfBoundsException();
        }
        stack.top++;
        stack.stackArray[stack.top] = j;
    }

    @Override
    public void pop() {
        if (isEmpty()){
            throw new NullPointerException();
        }
        stack.top--;
    }

    @Override
    public long StackTop() {
        return stack.stackArray[stack.top];
    }

    @Override
    public boolean isEmpty() {
        return stack.top==-1;
    }

    @Override
    public boolean isFull() {
        return stack.top==stack.maxSize-1;
    }
}
