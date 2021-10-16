public class Vertex {
	public char lable;// node label, i.e., node "A", "B", or, "0", "1"
	public boolean wasVisited;
	public int cycleflag;
 
	public Vertex(char givenlable) {
		lable = givenlable;
		wasVisited = false;
		cycleflag = -1;
	}
}
