import java.util.LinkedList;

class Queue {
	
	private LinkedList<Integer> queuelist;

 
	public Queue() {
		queuelist = new LinkedList<Integer>();

	}
 
	public void insert(int j) {//enqueue

		queuelist.add(j);
	}
 
	public int remove() {//dequeue
		return queuelist.remove().intValue();
	
	}
 
	public boolean isEmpty() {
		
		return queuelist.isEmpty();
		
	}
}
 
