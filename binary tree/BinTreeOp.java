package TreeInterface;

import java.util.Scanner;

public class BinTreeOp implements TreeInterface {
    Scanner cin = new Scanner(System.in);

    @Override
    public BinTree CreateBinTree(BinTree T) {  //经典递归
        if (T==null){
            T = new BinTree();
        }
        Object x = cin.next();
        if (x.equals("#")){
            T = null;
            System.out.println(x.equals('#'));
        }
        else {
            T.data = x;
            CreateBinTree(T.lchild);
            CreateBinTree(T.rchild);
        }
        return T;
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
