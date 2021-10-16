/******************************************************************************
 *  QueuePop.java
 *
 * This file is a copy of Queue.java from the "algs4" library.
 * A draw() method has been added. Go to its code for its API.
 * The original main() method has been changed. See code within main() for comments that guide you
 * through the implementation for HW 1.
 * For HW #1 you will modify this Queue code to transform it into QueuePop.
 
 For more documentation on Queue, see the API / documentation page supplied by algs4 website
 *
 *
 * Original code Copyright 2002-2018, Robert Sedgewick and Kevin Wayne.
 ******************************************************************************/

//package edu.princeton.cs.algs4;

import java.util.Iterator;
import java.util.NoSuchElementException;

import edu.princeton.cs.algs4.StdDraw;
import edu.princeton.cs.algs4.StdOut;
import edu.princeton.cs.algs4.StdRandom;

 
public class QueuePop<Item> implements Iterable<Item> {
    private Node<Item> first;    // beginning of queue
    private Node<Item> last;     // end of queue
    private int n;               // number of elements on queue

    // helper linked list class
    private static class Node<Item> {
        private Item item;
        private Node<Item> next;
    }

    /**
     * Initializes an empty queue.
     */
    public QueuePop() {
        first = null;
        last  = null;
        n = 0;
    }

    /**
     * Returns true if this queue is empty.
     *
     * @return {@code true} if this queue is empty; {@code false} otherwise
     */
    public boolean isEmpty() {
        return first == null;
    }

    /**
     * Returns the number of items in this queue.
      
     */
    public int size() {
        return n;
    }

    /**
     * Returns the item least recently added to this queue.
     * @throws NoSuchElementException if this queue is empty
     */
    public Item peek() {
        if (isEmpty()) throw new NoSuchElementException("Queue underflow");
        return first.item;
    }

    /**
     * Adds the item to this queue.
     *
     * @param  item the item to add
     */
    public void enqueue(Item item) {
        Node<Item> oldlast = last;
        last = new Node<Item>();
        last.item = item;
        last.next = null;
        if (isEmpty()) first = last;
        else           oldlast.next = last;
        n++;
    }

    /**
     * Removes and returns the item on this queue that was least recently added.
      
     * @throws NoSuchElementException if this queue is empty
     */
    public Item dequeue() {
        if (isEmpty()) throw new NoSuchElementException("Queue underflow");
        Item item = first.item;
        first = first.next;
        n--;
        if (isEmpty()) last = null;   // to avoid loitering
        return item;
    }

    /**
     * Returns a string representation of this queue.
     *
     * @return the sequence of items in FIFO order, separated by spaces
     */
    public String toString() {
        StringBuilder s = new StringBuilder();
        for (Item item : this) {
            s.append(item);
            s.append(' ');
        }
        return s.toString();
    } 

    /**
     * Returns an iterator that iterates over the items in this queue in FIFO order.
     *
     * @return an iterator that iterates over the items in this queue in FIFO order
     */
    public Iterator<Item> iterator()  {
        return new ListIterator(first);  
    }

    // an iterator, doesn't implement remove() since it's optional
    private class ListIterator implements Iterator<Item> {
        private Node<Item> current;

        public ListIterator(Node<Item> first) {
            current = first;
        }

        public boolean hasNext()  { return current != null;                     }
        public void remove()      { throw new UnsupportedOperationException();  }

        public Item next() {
            if (!hasNext()) throw new NoSuchElementException();
            Item item = current.item;
            current = current.next; 
            return item;
        }
    }

// ***********************************************************************
	// draw()
    /* Draw queuePop if there are items in it
     * The drawing space is the unit square [0,1] x [0,1].
     * QueuePop items are represented as circles, centered on the x-axis at y=0.5.
     * If the animate flag is set, one of the items will move up, appearing to disappear.
     * A pair of calls to this function with a dequeue or pop will animate the departure of an item.
     * Example:
     *    queuePop.draw(0, 100, numColors, colors, radius);
     *	  queuePop.dequeue();
     *	  queuePop.draw(-1, 1000, numColors, colors, radius);
     *
     * int ianimate = -1 do not animate
     *     ianimate >= 0 animate the kth item in the queue (k=0, 1, ...) (if out of bounds, none will animate)
     * 
     * int pauseTime: pauses for t milliseconds
     * int numColors: number of colors in input color array
     * int color[][]: rgb colors
     * double radius: radius for circles (drawing space is unit square [0,1] x [0,1])
     */
	    public void draw(int ianimate, int pauseTime, int numColors, int [][] colors, double radius) {
	    	
	    	StdDraw.enableDoubleBuffering();
	    	
	    	int qsize = size();
	    	//StdOut.println("\n draw: size of queuePop = " + qsize);
	    	    	
	    	// draw if the queue has items
	    	if(qsize > 0) {
	    		 		
	    		// create some variables to make plot look "nice"
	    		// use up 3/4 of the screen space which is one unit wide
	    		double maxXlgth = 0.75;
	    		// x-axis goes from 0 to 1. Scale and translate to center the circles
	    		double translate = 0.5 - maxXlgth/2.0;
	    		
	    		
	    		// set number of times to animate a circle if the ianimate flag is set to valid item in queuePop
	    		int numIters = 1;
	    		if(ianimate != -1)numIters = 10; 
	    		
	    		// set the step size in y to animate the circle
	    		double delta = 0.4/numIters;
	    		
	    		//StdOut.println("\n draw: ianimate = " + ianimate);
	    		
	    		// animate by redrawing with different y-value for a circle
	    		for(int iter=1; iter <= numIters; iter++) {
	    		
	    			// keep track of which entry in queuePop is being processed
		    		int k = -1;
		    		
		    		// clear the screen
		    		StdDraw.clear();
		    	
			    	//StdOut.println("\n draw: iter = " + iter);
			    	
		    		// iterate thru each item in the queuePop
			        Iterator<Item> i = iterator();
			        while(i.hasNext()) {
			        	Item j = i.next();
			        	//StdOut.print(j + " ");
			        	
			        	// x position a function of the kth item
			        	// if last item, center it
			        	// y position is just center
			        	k++;
			        	double x;
			        	if(qsize == 1) {
			        		x = 0.5;
			        	}
			        	else x = (1.0*k/(qsize-1))*maxXlgth + translate;
			        	double y = 0.5;
			        	// animate the kth entry by changing the y-value
			        	if(k == ianimate) y = 0.5 + (iter - 1)*delta;
			        		
			        	//StdOut.println("k="+ k + "  x=" + x + "  y=" + y + "  radius = " + radius);
			        	
			        	// grab color in color map based on item
			        	int icolor = Math.floorMod((int) j, numColors); 
			        	//StdOut.println("item = " + (int) j + "  icolor = "+ icolor);
			        	
			        	StdDraw.setPenColor(colors[icolor][0], colors[icolor][1], colors[icolor][2]);
			        	StdDraw.filledCircle(x, y, radius);
			        	//StdOut.println("draw: color  " + colors[icolor][0] + " " +colors[icolor][1] + " " +  colors[icolor][2]);
			        }
			         
			        StdDraw.show();
			        StdDraw.pause(pauseTime);
			        
		    	}
	    		// before leaving, clear the screen
	    		//StdDraw.clear();
		        //StdDraw.show();
	    	}
	    }
		
    /**
     * Unit tests the {@code Queue} data type.
     *
     * 
     */
    public static void main(String[] args) {
		
        QueuePop<Integer> queuePop = new QueuePop<Integer>();
        int iret;
        
        // To Do: create test data (integers 0, num) to put on queuePop
		// You can do this in an array or create the data on the fly
        int num = 10;
         
        
        // create a list of colors ---  one for each entry in test
		// Option: create your own color creation method
        int numColors = num;
        int [][] colors;
        colors = new int [numColors][3];
        for(int i=0; i<numColors; i++) {
        	colors[i][0] = StdRandom.uniform(255);
        	colors[i][1] = StdRandom.uniform(255);
        	colors[i][2] = 255 - colors[i][1];
        }
         
        
        // specify the radius of each circle to draw 
        // (just an eye-ball to look good value based on number of data)
        
		double minRadius = 0.001;
		double radius = 0.25/num;
		if(radius < minRadius) radius = minRadius;
		StdOut.println("radius =  " + radius);
      
        // To Do: add all of test data to queuePop
        
        StdOut.println("\n Added all of test to queuePop");
        StdOut.println(queuePop);
        
        
        // To Do: test dequeue and pop by calling each once
        iret = 0; // dequeue here
        StdOut.println("\n dequeue one of queuePop " + iret);
        StdOut.println(queuePop);
        
        iret = 0;   // pop here 
        StdOut.println("\n pop one of queuePop " + iret);
        StdOut.println(queuePop);
        
        
        // Demonstrate iterating thru queuePop
        // using long form of foreach
        StdOut.println("\n Print queuePop using iterator");
        Iterator<Integer> i = queuePop.iterator();
        while(i.hasNext()) {
        	Integer j = i.next();
        	StdOut.print(j + " ");
        }
        // Demonstrate iterating thru queuePop
        //foreach
        StdOut.println("\n Print queuePop using foreach");
        for(Integer ival : queuePop)
        	StdOut.print(ival + " ");
        
      // draw all  
      queuePop.draw(-1, 1, numColors, colors, radius);
      
      // To Do: alternatively dequeue and pop until queuePop is empty
	  // draw with animation (See draw documentation to see example call sequence)
       
       
      // clear the window
      StdDraw.clear();
      StdDraw.show();
	  
    }
}
