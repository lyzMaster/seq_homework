package TreeInterface;

import java.util.Scanner;

public class BinTreeOp implements TreeInterface {
    Scanner cin = new Scanner(System.in);
    @Override
    public BinTree CreateBinTree(BinTree T) {
        BinTree current = new BinTree();
        BinTree root = new BinTree();
        current = root = null;
        int i=0;
        for (;;){
            i++;
            Object n = cin.next();
            current.lchild()
        }
        return null;
    }

    @Override
    public void ListBinTree(BinTree T) {

    }

    @Override
    public void DisplayBinTree(BinTree T) {

    }

    @Override
    public void Preorder(BinTree T) {

    }

    @Override
    public void Inorder(BinTree T) {

    }

    @Override
    public void Postorder(BinTree T) {

    }

    @Override
    public int nodes(BinTree T) {
        return 0;
    }

    @Override
    public int leafs(BinTree T) {
        return 0;
    }

    @Override
    public BinTree swap(BinTree T) {
        return null;
    }
}
