import java.util.LinkedList;
import java.util.List;
import java.util.Random;
import java.util.Stack;
import java.util.HashSet;

public class Graph {
	private Vertex vertexList[];
	public int adjMat[][];
	private LinkedList<LinkedList<Integer>> adjlist;
	private int nVerts;
	private Stack<Integer> theStack; //for DFS
	private Queue theQueue; //for BFS
	
	public static void main(String[] args) {
		// complete the main method to create a graph for problem 5 in Assignment 5
		// test if the graph contains cycles
		
		
		
		
		
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
 
		//System.out.print("visits:");
		// theGraph.dfs();
		// theGraph.bfs();
		//theGraph.dfs();
		//System.out.println();
		for (int i = 0; i < element.length; i++) {
			System.out.print(element[i] + ": ");
			for (int j = 0; j < element.length; j++) {
				if (theGraph.adjMat[i][j] == 1) {
					System.out.print(element[j] + " ");
				}
			}
			System.out.println();
		}
		System.out.println("Cycle detected: " + theGraph.detectcycle());

		
	}
 
	
	 public Graph(int n) {
		  vertexList = new Vertex[n];
		  int [] vertexcycleflag = new int[n];
		  
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
	HashSet<Integer> vertices = new HashSet<Integer>();
	for (int i = 0; i < vertexList.length; i++) {
		vertices.add(new Integer(i));
	}
	while (vertices.size() > 0) {
		Integer root = vertices.iterator().next();
		HashSet<Integer> ancestors = new HashSet<Integer>();
		HashSet<Integer> visited = new HashSet<Integer>();
		boolean cycleFound = detectcycle(root, ancestors, visited);
		if (cycleFound) {
			return true;
		}
	}
	
	
	return false;
}

public boolean detectcycle(Integer root, HashSet<Integer> ancestors, HashSet<Integer> visited) {
	visited.add(root);
	for (int i = 0; i < vertexList.length; i++) {
		if (adjMat[root.intValue()][i] == 1 && ancestors.contains(new Integer(i))) {
			return true;
		}
	}
	ancestors.add(root);
	for (int i = 0; i < vertexList.length; i++) {
		if (adjMat[root.intValue()][i] == 1) {
			boolean cycleFound = detectcycle(new Integer(i), ancestors, visited);
			if (cycleFound) {
				return true;
			}
		}
	}
	ancestors.remove(root);
	return false;
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
	
	
	



