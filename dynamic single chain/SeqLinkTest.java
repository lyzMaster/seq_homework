package SeqLink;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class SeqLinkTest {
	public static void main(String args[]) throws IOException {
//		String[] word = { "fox", "cow", "pig", "cat", "rat", "lio", "tig",
//				"goa", "dog" };
		SeqLinkOps sl = new SeqLinkOps();
		InputStreamReader isr = new InputStreamReader(System.in);
		BufferedReader buf = new BufferedReader(isr);		
		System.out.println("��ѡ����������ķ�ʽ��");
		System.out.println("=============================");
			System.out.println("1��β�巨������ͷ�ڵ�ĵ�����        ");
			System.out.println("2��ͷ�巨������ͷ�ڵ�ĵ�����        ");
			System.out.println("3��β�巨������ͷ�ڵ�ĵ�����        ");	
			System.out.println("=============================");
			System.out.println("�밴��������ʾѡ����������");
				
			String str = buf.readLine();
			int choice = Integer.parseInt(str);
			
			switch (choice) {
			case 1: 
				sl.Rear_Create();
				System.out.print("��β�巨��������ͷ�ڵ㵥����ṹΪ: ");
				sl.print();
				break;			
			case 2: 
				sl.Front_Create();
				System.out.print("��ͷ�巨��������ͷ�ڵ㵥����ṹΪ: ");
				sl.print();
				break;
			case 3: 
				sl.Rear_Create_Head();
				System.out.print("��β�巨�����Ĵ�ͷ�ڵ㵥����ṹΪ: ");
				sl.print();
				break;
				
			}
	
//			System.out.println("�������Ա���Ϊ"+sl.ListLength());
			
		
//������ԣ���Ϊ������ڵĽڵ�Ͳ����ڵĽڵ�
//			sl.insert("ant", "1");
//			System.out.print("��������ֵΪ1�������ֵΪant��Ľ�㣬��������Ϊ: ");
//			sl.print();
//
//		sl.insert("phl", "qq");
//		System.out.print("��������ֵΪqq�������ֵΪphl��Ľ�㣬��������Ϊ: ");
//		sl.print();
//
//		sl.InsertIndex("aa",2);
//		System.out.print("�ڵڶ������λ�ò���ֵΪaa�Ľ�㣬��������Ϊ: ");
//		sl.print();
//

//		ɾ������	����Ϊɾ�����ڵĽڵ�Ͳ����ڵĽڵ�	
//		sl.delete("ant");
//		System.out.print("ɾ��������ֵΪant���󣬵�������Ϊ: ");
//		sl.print();
//
//		sl.delete("cc");
//		System.out.print("ɾ��������ֵΪcc���󣬵�������Ϊ: ");
//		sl.print();
//
//		sl.DeleteList(2);
//		System.out.print("ɾ����2���ڵ�󣬵�������Ϊ: ");
//		sl.print();
			
			
	}
}
