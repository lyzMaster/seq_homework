package SeqLink;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class SeqLinkOps implements SeqLinkInterface{

	private SeqLink head = new SeqLink();

	// 尾插法建立无头节点的单链表；
	public void Rear_Create() {
		SeqLink r = new SeqLink();
		r = head = null;
		String s;
		InputStreamReader isr = new InputStreamReader(System.in);
		BufferedReader buf = new BufferedReader(isr);
		System.out.println("请输入用,号隔开的一组数据");

		try {
			s = buf.readLine();
			StringTokenizer fenxi = new StringTokenizer(s, ",");

			while (fenxi.hasMoreTokens()) {

				SeqLink link = new SeqLink(fenxi.nextToken());
				// System.out.println(link.data);
				if (head == null)
					head = link;
				else
					r.next = link;
				r = link;

			}
			if (r != null)
				r.next = null;
		} catch (IOException e) {

			e.printStackTrace();
		}

	}

	// 头插法建立无头节点的单链表；
	public void Front_Create() {
		head = null;
		String s;
		InputStreamReader isr = new InputStreamReader(System.in);
		BufferedReader buf = new BufferedReader(isr);
		System.out.println("请输入用,号隔开的一组数据");

		try {
			s = buf.readLine();
			StringTokenizer fenxi = new StringTokenizer(s, ",");

			while (fenxi.hasMoreTokens()) {

				SeqLink link = new SeqLink(fenxi.nextToken());
				link.next = head;
				head = link;
			}

		} catch (IOException e) {

			e.printStackTrace();
		}

	}

	// 尾插法建立带头节点的单链表；
	public void Rear_Create_Head() {
		SeqLink r = new SeqLink();
		r = head;
		String s;
		InputStreamReader isr = new InputStreamReader(System.in);
		BufferedReader buf = new BufferedReader(isr);
		System.out.println("请输入用,号隔开的一组数据");

		try {
			s = buf.readLine();
			StringTokenizer fenxi = new StringTokenizer(s, ",");

			while (fenxi.hasMoreTokens()) {

				SeqLink link = new SeqLink(fenxi.nextToken());
				r.next = link;
				r = link;
			}

			r.next = null;
		} catch (IOException e) {

			e.printStackTrace();
		}

	}

	// 打印所有单链表结构；
	public void print() {
		System.out.print("head");
		for (SeqLink curr = head; curr != null; curr = curr.next)
			System.out.print(" -> " + curr.data);
		System.out.println(" -> null");
	}

	// 求无头节点单链表的长度
	public int ListLength() {
		int i = 0;
		SeqLink p;
		for (p = head; p != null; p = p.next)
			i++;
		return (i);
	}

	// 在单链表中查找数据域值为val的结点
	public SeqLink search(Object val) {
		for (SeqLink curr = head; curr != null; curr = curr.next)
			if (val.equals(curr.data))
				return curr;
		return null;
	}

	// 写查找单链表第i个结点,此处为无头节点的单链表，节点从1开始
	public SeqLink GetNode(int i) {
		int j;
		SeqLink p;
		p = head;
		j = 1;
		if (i <= 0 || i > ListLength()) {
			System.out.println("查找超出单链表范围！");
			System.exit(0);
		}
		while (p.next != null && j < i) {
			p = p.next;
			j++;
		}
		if (i == j)
			return (p);
		else
			return (null);
	}

	// 在链表中的数据域值为linkVal的结点之后添加数据域值为val的结点
	// 若没找到要插入的元素，则插入头节点
	public void insert(Object val, Object linkVal) {
		SeqLink temp;
		temp = search(linkVal);
		SeqLink ins = new SeqLink(val);
		// 若没指定插入某一个元素之后或指出的元素不存在，则插入到头指针之后
		if (temp == null) {
			ins.next = head;
			head = ins;
		} else {
			ins.next = temp.next;
			temp.next = ins;
		}
	}

	// 在链表中第i个结点的位置上添加数据域值为val的结点
	public void InsertIndex(Object x, int i) {
		SeqLink p, s;
		if (i == 1) {
			s = new SeqLink(x);
			s.next = head;
			head = s;
		} else {
			p = GetNode(i - 1); // 寻找第i-1个结点
			s = new SeqLink(x);
			s.next = p.next;
			p.next = s;
		}
	}

	// 删除数据域值为val的结点
	public void delete(Object val) {
		SeqLink temp;
		temp = search(val);

		// 指出边缘不存在的情况
		if (temp == null) {
			System.out.println("删除的元素不存在");
			System.exit(0);
		}
		if (temp == head)
			head = head.next;
		else {
			SeqLink prior = head;
			while (prior.next != temp)
				prior = prior.next;
			prior.next = temp.next;
		}
	}

	// 删除第i各结点
	public void DeleteList(int i) {
		SeqLink p, r;
		if (i == 1) {
			head = head.next;
		} else {
			p = GetNode(i - 1);// 寻找第i-1个结点
			if (p.next == null) {
				System.out.println("删除位置非法\n");
				System.exit(0);
			}
			r = p.next;
			p.next = r.next;
		}
	}
}
