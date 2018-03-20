package SeqInterFace;

import java.util.NoSuchElementException;
import java.util.Scanner;

public class Seq implements SeqInterface{
	
	public int maxSize;
	public String[] seqArray;
	public int length;
	
	public Seq(int max) {
		maxSize = max;
		seqArray = new String[maxSize];
		length = 0;
	}

	@Override
	public void CreateList(int n) {
		this.length = n;
		Scanner input = new Scanner(System.in);
		try{
			for(int i=0;i<n;i++){
				seqArray[i] = input.next();
			}
		}
		catch(Exception e){
			System.out.print(e);
		}
	}

	@Override
	public void PrintList() {
		for(int i=0;i<this.length;i++){
			System.out.println(seqArray[i]);
		}
	}

	@Override
	public int getLength() {
		return this.length;
	}

	@Override
	public String first() {
		return this.seqArray[0];
	}

	@Override
	public String lasty() {
		return this.seqArray[this.getLength()-1];
	}

	@Override
	public void LocateList(String x) {
		boolean equals = true;
		for(int i=0;i<this.length;i++){
			if(seqArray[i].equals(x)){
				System.out.println(i);
				equals = false;
			}
		}
		if (equals){
			throw new NoSuchElementException();
		}
	}

	@Override
	public int index(String a) {
		for(int i=0;i<this.length;i++){
			if(seqArray[i].equals(a)){
				return i;
			}
		}
		return -1;
	}

	@Override
	public String prev(int i) throws flowOrErrorException {
		return seqArray[i-2];
	}

	@Override
	public String prev(String a) throws flowOrErrorException {
		int i;
		for(i=0;i<this.length;i++){
			if(seqArray[i].equals(a)){
				break;
			}
		}
		return seqArray[i-1];
	}

	@Override
	public String next(int i) throws flowOrErrorException {
		return seqArray[i];
	}

	@Override
	public String next(String a) throws flowOrErrorException {
		int i;
		for(i=0;i<this.length;i++){
			if(seqArray[i].equals(a)){
				break;
			}
		}
		return seqArray[i+1];
	}

	@Override
	public void InsertList(String x) throws flowOrErrorException {
		seqArray[length] = x;
		this.length++;
	}

	@Override
	public void InsertList(String x, int i) throws flowOrErrorException {
		for (int j=this.length;j>=i-1;j--){
			seqArray[j] = seqArray[j-1];
		}
		seqArray[i-1] = x;
		this.length++;
	}

	@Override
	public void DeleteList(int i) throws flowOrErrorException {
		for (int j=i+1;j<=this.length;j++){
			seqArray[j-1] = seqArray[j];
		}
		this.length--;
	}

	@Override
	public void DeleteList(String x) throws flowOrErrorException {
		boolean equals = true;
		for (int i = 0; i < this.length; i++) {
			if (x.equals(seqArray[i])) {
				this.DeleteList(i);
				equals = false;
			}
		}
		if (equals){
			throw new NoSuchElementException();
		}
	}

}
