package TreeInterface;

public class BinTree {
    Object data;
    BinTree lchild;
    BinTree rchild;
    BinTree() {	}
    BinTree(Object obj) {
        data=obj;
    }
    BinTree(Object obj, BinTree leftc, BinTree rightc) {
        data = obj;
        lchild = leftc;
        rchild = rightc;
    }

}
