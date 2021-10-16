import java.util.LinkedList;

class Queue {
	
	private LinkedList queuelist;

 
	public Queue() {
		queuelist = new LinkedList<Integer>();

	}
 
	public void insert(int j) {//enqueue

		queuelist.add(j);
	}
 
	public int remove() {//dequeue
		return (int)queuelist.remove();
	
	}
 
	public boolean isEmpty() {
		
		return queuelist.isEmpty();
		
	}
}
 