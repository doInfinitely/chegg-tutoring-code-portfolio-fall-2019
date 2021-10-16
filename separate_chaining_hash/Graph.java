import java.util.LinkedList;
import java.util.List;
import java.util.Random;
import java.util.Stack;

public class Graph {
	private Vertex vertexList[];
	private int adjMat[][];
	private LinkedList<LinkedList<Integer>> adjlist;
	private int nVerts;
	private Stack<Integer> theStack; //for DFS
	private Queue theQueue; //for BFS
	
	public static void main(String[] args) {
		// complete the main method to create a graph for problem 5 in Assignment 5
		// test if the graph contains cycles
		
		
		
		
		
		/* An example to create a graph using the Graph class
		char[] element = {'A','B','C','D','E'};
		Graph theGraph = new Graph(element.length);
		 for(char s :element){
		   theGraph.addVertex(s);
		  }
		// A: 0, B: 1, C: 2, D: 3, E: 4
		theGraph.addEdge(0, 1);
		theGraph.addEdge(1, 2);
		theGraph.addEdge(0, 3);
		theGraph.addEdge(3, 4);
 
		System.out.print("visits:");
		// theGraph.dfs();
		// theGraph.bfs();
		theGraph.dfsr();
		System.out.println();
		
		*/
		
	}
 
	
	 public Graph(int n) {
		  vertexList = new Vertex[n];
		  vertexcycleflag = new int[n];
		  
		  //cycleflag 
		  for  (int i = 0; i < n; i++) {
			  vertexcycleflag[i]=-1;
		  }
		 
		  
		  //adj matrix
		  adjMat = new int[n][n];
		  nVerts = 0;
		  for (int i = 0; i < n; i++) {
		   for (int j = 0; j < n; j++) {
		    adjMat[i][j] = 0;
		   }
		  }
		  
		  //adj list
		  
		  adjlist = new LinkedList<LinkedList<Integer>>();
		  for (int i = 0; i < n; i++) {
				
				adjlist.add(new LinkedList<Integer>());
			}
		  
		  theStack = new Stack<Integer>();
		  theQueue = new Queue();
		 }

	
 
	public void addVertex(char nodename) {// add vertex
		vertexList[nVerts++] = new Vertex(nodename);
	}
 
	public void addEdge(int start, int end) {// undirected
		//adj matrix
		adjMat[start][end] = 1;
		adjMat[end][start] = 1;
		//adj list
		
		if(!adjlist.get(start).contains(end))
			adjlist.get(start).add(end);
			 
		if(!adjlist.get(end).contains(start))
			adjlist.get(end).add(start);
		
	}
 
	public void displayVertex(int v) {// print vertex label
		System.out.print(vertexList[v].lable);
	}
 
	public int getAdjUnvisitedVertex(int v) {// get an unvisited connected vertex
		for (int i = 0; i < nVerts; i++) {
			if (adjMat[v][i] == 1 && vertexList[i].wasVisited == false) {
				return i;
			}
		}
		return -1;
	}
	
	
	



public boolean detectcycle()
{

	// complete the method to detect cycles in the graph
	// feel free to change the return type, parameters
	
	
	
	
}

	
	
	
	
	
	
 
	public void dfs() {// DFS using stack
	
		for (int i = 0; i < nVerts; i++) {
			vertexList[i].wasVisited = false;// Reset the wasvisited matrix 
		}
		//Pick the starting node randomly
		Random rand = new Random();
		int randNum = rand.nextInt(nVerts);
		
		//Visit the starting node
		vertexList[randNum].wasVisited = true; 
		displayVertex(randNum);
		theStack.push(randNum);
 
		while (!theStack.isEmpty()) {
			int neighbor = getAdjUnvisitedVertex(theStack.peek());
			if (neighbor == -1) {
				theStack.pop();
			} else {
				vertexList[neighbor].wasVisited = true;
				displayVertex(neighbor);
				theStack.push(neighbor);
			}
		}
 		

	}
	

	
 
	public void bfs() {// BFS using a queue
		
		for (int j = 0; j < nVerts; j++) {
				vertexList[j].wasVisited = false; // Reset the wasvisited matrix
		}
		//Pick the starting node randomly
		Random rand = new Random();
		int randNum = rand.nextInt(nVerts);
		
		//Visit the starting node
		vertexList[randNum].wasVisited = true;
		displayVertex(randNum);
		theQueue.insert(randNum);
	
		
		while (!theQueue.isEmpty()) {
			int currentv = theQueue.remove();
			int neighbor;
			while ((neighbor = getAdjUnvisitedVertex(currentv)) != -1) {
				vertexList[neighbor].wasVisited = true;
				displayVertex(neighbor);
				theQueue.insert(neighbor);
			}
		}
	 
	
	}
	
}
	
	
	



