package SeqLink;
public class SeqLink {
	Object data;   // the data wrapped in the node
	SeqLink next;  // reference to the next Node

	  // default constructor,empty node
	SeqLink() {}

	  // constructor for node with given object
	SeqLink(Object obj) { data = obj; }

	  // general constructor
	SeqLink(Object obj, SeqLink link) {  
	    data = obj;
	    next = link; 
	  }

	  
	 
	}
