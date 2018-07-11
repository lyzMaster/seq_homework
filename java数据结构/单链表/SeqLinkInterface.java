package SeqLink;

public interface SeqLinkInterface {

	// 尾插法建立无头节点的单链表；
	public void Rear_Create();

	// 头插法建立无头节点的单链表；
	public void Front_Create();

	// 尾插法建立带头节点的单链表；
	public void Rear_Create_Head();

	// 打印无头节点单链表结构；
	public void print();

	// 求无头节点单链表的长度
	public int ListLength();

	// 在单链表中查找数据域值为val的结点
	public SeqLink search(Object val);

	// 写查找单链表第i个结点,此处为无头节点的单链表，节点从1开始
	public SeqLink GetNode(int i);

	// 在链表中的数据域值为linkVal的结点之后添加数据域值为val的结点
	// 若没找到要插入的元素，则插入头节点
	public void insert(Object val, Object linkVal);

	// 在链表中第i个结点的位置上添加数据域值为val的结点
	public void InsertIndex(Object x, int i);

	// 删除数据域值为val的结点
	public void delete(Object val);

	// 删除第i各结点
	public void DeleteList(int i);
}
