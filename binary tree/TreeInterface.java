package TreeInterface;

public interface TreeInterface {
    /* 构造二叉链表 */
    public BinTree CreateBinTree(BinTree T);

    /* 用广义表表示二叉树 */
    public void ListBinTree(BinTree T);

    /* 用凹入表表示二叉树 */
    public void DisplayBinTree(BinTree T) ;
    //
	/* 前序遍历二叉树 */
    public void Preorder(BinTree T) ;

    /* 中序遍历二叉树 */
    public void Inorder(BinTree T) ;

    /* 后序遍历二叉树 */
    public void Postorder(BinTree T) ;

    /* 求二叉树的节点总数 */
    public int nodes(BinTree T) ;

    /* 求二叉树的叶子总数 */
    public int leafs(BinTree T);

    /* 交换二叉树的左右子树 */
    public BinTree swap(BinTree T)	;
}