package SeqLink;

public interface SeqLinkInterface {

	// β�巨������ͷ�ڵ�ĵ�����
	public void Rear_Create();

	// ͷ�巨������ͷ�ڵ�ĵ�����
	public void Front_Create();

	// β�巨������ͷ�ڵ�ĵ�����
	public void Rear_Create_Head();

	// ��ӡ��ͷ�ڵ㵥����ṹ��
	public void print();

	// ����ͷ�ڵ㵥����ĳ���
	public int ListLength();

	// �ڵ������в���������ֵΪval�Ľ��
	public SeqLink search(Object val);

	// д���ҵ������i�����,�˴�Ϊ��ͷ�ڵ�ĵ������ڵ��1��ʼ
	public SeqLink GetNode(int i);

	// �������е�������ֵΪlinkVal�Ľ��֮�����������ֵΪval�Ľ��
	// ��û�ҵ�Ҫ�����Ԫ�أ������ͷ�ڵ�
	public void insert(Object val, Object linkVal);

	// �������е�i������λ�������������ֵΪval�Ľ��
	public void InsertIndex(Object x, int i);

	// ɾ��������ֵΪval�Ľ��
	public void delete(Object val);

	// ɾ����i�����
	public void DeleteList(int i);
}
