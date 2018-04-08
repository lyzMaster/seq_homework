package SeqLink;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class SeqLinkOps implements SeqLinkInterface{

	private SeqLink head = new SeqLink();

	// β�巨������ͷ�ڵ�ĵ�����
	public void Rear_Create() {
		SeqLink r = new SeqLink();
		r = head = null;
		String s;
		InputStreamReader isr = new InputStreamReader(System.in);
		BufferedReader buf = new BufferedReader(isr);
		System.out.println("��������,�Ÿ�����һ������");

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

	// ͷ�巨������ͷ�ڵ�ĵ�����
	public void Front_Create() {
		head = null;
		String s;
		InputStreamReader isr = new InputStreamReader(System.in);
		BufferedReader buf = new BufferedReader(isr);
		System.out.println("��������,�Ÿ�����һ������");

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

	// β�巨������ͷ�ڵ�ĵ�����
	public void Rear_Create_Head() {
		SeqLink r = new SeqLink();
		r = head;
		String s;
		InputStreamReader isr = new InputStreamReader(System.in);
		BufferedReader buf = new BufferedReader(isr);
		System.out.println("��������,�Ÿ�����һ������");

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

	// ��ӡ���е�����ṹ��
	public void print() {
		System.out.print("head");
		for (SeqLink curr = head; curr != null; curr = curr.next)
			System.out.print(" -> " + curr.data);
		System.out.println(" -> null");
	}

	// ����ͷ�ڵ㵥����ĳ���
	public int ListLength() {
		int i = 0;
		SeqLink p;
		for (p = head; p != null; p = p.next)
			i++;
		return (i);
	}

	// �ڵ������в���������ֵΪval�Ľ��
	public SeqLink search(Object val) {
		for (SeqLink curr = head; curr != null; curr = curr.next)
			if (val.equals(curr.data))
				return curr;
		return null;
	}

	// д���ҵ������i�����,�˴�Ϊ��ͷ�ڵ�ĵ������ڵ��1��ʼ
	public SeqLink GetNode(int i) {
		int j;
		SeqLink p;
		p = head;
		j = 1;
		if (i <= 0 || i > ListLength()) {
			System.out.println("���ҳ���������Χ��");
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

	// �������е�������ֵΪlinkVal�Ľ��֮�����������ֵΪval�Ľ��
	// ��û�ҵ�Ҫ�����Ԫ�أ������ͷ�ڵ�
	public void insert(Object val, Object linkVal) {
		SeqLink temp;
		temp = search(linkVal);
		SeqLink ins = new SeqLink(val);
		// ��ûָ������ĳһ��Ԫ��֮���ָ����Ԫ�ز����ڣ�����뵽ͷָ��֮��
		if (temp == null) {
			ins.next = head;
			head = ins;
		} else {
			ins.next = temp.next;
			temp.next = ins;
		}
	}

	// �������е�i������λ�������������ֵΪval�Ľ��
	public void InsertIndex(Object x, int i) {
		SeqLink p, s;
		if (i == 1) {
			s = new SeqLink(x);
			s.next = head;
			head = s;
		} else {
			p = GetNode(i - 1); // Ѱ�ҵ�i-1�����
			s = new SeqLink(x);
			s.next = p.next;
			p.next = s;
		}
	}

	// ɾ��������ֵΪval�Ľ��
	public void delete(Object val) {
		SeqLink temp;
		temp = search(val);

		// ָ����Ե�����ڵ����
		if (temp == null) {
			System.out.println("ɾ����Ԫ�ز�����");
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

	// ɾ����i�����
	public void DeleteList(int i) {
		SeqLink p, r;
		if (i == 1) {
			head = head.next;
		} else {
			p = GetNode(i - 1);// Ѱ�ҵ�i-1�����
			if (p.next == null) {
				System.out.println("ɾ��λ�÷Ƿ�\n");
				System.exit(0);
			}
			r = p.next;
			p.next = r.next;
		}
	}
}
