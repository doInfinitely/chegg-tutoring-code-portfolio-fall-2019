
public class LinkedList {
	
	
	// The LinkedList Node class
	private class Node{
		
		int data;
		Node next;
		
		Node(int gdata)
		{
			this.data = gdata;
			this.next = null;
		}
		
	}
	
	// The LinkedList fields
	Node head;
	
	// Constructor
	LinkedList(int gdata)
	{
		this.head = new Node(gdata);
	}
	
	public void Insertend(int gdata)
	{
		Node current = this.head;

		while(current.next!= null)
		{
			current = current.next;
		}
		
		Node newnode = new Node(gdata);
		current.next = newnode;
		
	}
	
	public void Listprint()
	{
		Node current = this.head;

		while(current!= null)
		{
			System.out.print(current.data + " ");
			current = current.next;
		}
		
		System.out.println();
		
	}
	
	public void Removemin() {
	// Complete this method to remove the minimum value in a linkedlist
		// To delete a node we must keep a reference to the preceding node.
		Node prev = null;
		Node finalPrev = prev;

		// Reference to the current node of the list
		Node current = this.head;
		int min = current.data;

		while (current != null) {

			// If the current element is smaller than the smallest found so far...
			if (current.data < min) {
				min = current.data;
				finalPrev = prev;
			}

			// Iterate the loop
			prev = current;
			current = current.next;
		}

		if (finalPrev != null) {
			finalPrev.next = finalPrev.next.next;
		} else { // Otherwise, the first element is the minimum
			this.head = this.head.next;
		}
	}
	
	public static void main(String[] args) {
		
		LinkedList exlist = new LinkedList(8);
		
		exlist.Insertend(1);
		exlist.Insertend(5);
		exlist.Insertend(2);
		exlist.Insertend(7);
		exlist.Insertend(10);
		exlist.Insertend(3);
		
		exlist.Listprint();
		//output: 8 1 5 2 7 10 3
		
		exlist.Removemin();
		
		exlist.Listprint();
		//output should be: 8 5 2 7 10 3
		
		
	}
	
	
	

}
