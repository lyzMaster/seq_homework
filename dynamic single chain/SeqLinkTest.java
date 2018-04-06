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
		System.out.println("请选择建立单链表的方式：");
		System.out.println("=============================");
			System.out.println("1：尾插法建立无头节点的单链表        ");
			System.out.println("2：头插法建立无头节点的单链表        ");
			System.out.println("3：尾插法建立带头节点的单链表        ");	
			System.out.println("=============================");
			System.out.println("请按照以上提示选择建立方法：");
				
			String str = buf.readLine();
			int choice = Integer.parseInt(str);
			
			switch (choice) {
			case 1: 
				sl.Rear_Create();
				System.out.print("用尾插法建立的无头节点单链表结构为: ");
				sl.print();
				break;			
			case 2: 
				sl.Front_Create();
				System.out.print("用头插法建立的无头节点单链表结构为: ");
				sl.print();
				break;
			case 3: 
				sl.Rear_Create_Head();
				System.out.print("用尾插法建立的带头节点单链表结构为: ");
				sl.print();
				break;
				
			}
	
//			System.out.println("整个线性表长度为"+sl.ListLength());
			
		
//插入测试，分为插入存在的节点和不存在的节点
//			sl.insert("ant", "1");
//			System.out.print("在数据域值为1结点后插入值为ant后的结点，单链表变成为: ");
//			sl.print();
//
//		sl.insert("phl", "qq");
//		System.out.print("在数据域值为qq结点后插入值为phl后的结点，单链表变成为: ");
//		sl.print();
//
//		sl.InsertIndex("aa",2);
//		System.out.print("在第二个结点位置插入值为aa的结点，单链表变成为: ");
//		sl.print();
//

//		删除测试	，分为删除存在的节点和不存在的节点	
//		sl.delete("ant");
//		System.out.print("删除数据域值为ant结点后，单链表变成为: ");
//		sl.print();
//
//		sl.delete("cc");
//		System.out.print("删除数据域值为cc结点后，单链表变成为: ");
//		sl.print();
//
//		sl.DeleteList(2);
//		System.out.print("删除第2个节点后，单链表变成为: ");
//		sl.print();
			
			
	}
}
