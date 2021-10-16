
public class Problem4 {

	public static int squareroot(int x)
	{
		// given a positive integer x, return square root of x
		// if x is not a perfect square, return the floor of its square root
		// complete the method squareroot() here
		// O(log n) expected
		// O(n) or slower will be graded out of 10 points
		double b = 1;
		while (Math.pow(b,2) < x) {
			b *= 10;
		}
		return squareroot(x, b);
		
		
		
		
		
		
		
		
	}
	public static int squareroot(int x, double b) {
		double a = (Math.pow(b, 2) - x) / (2*b);
		if (a < 1 && Math.floor(b-a) == Math.floor(b-1.5*a)) {
			return (int) Math.floor(b-a);
		}
		return squareroot(x, b-a);
	}

	

	
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		// test your count() method here
		
		int x1 = 8;
		int x2 = 5;
		int x3 = 17;
		System.out.println("The square root of " + x1 + " is " + squareroot(x1));
		System.out.println("The square root of " + x2 + " is " + squareroot(x2));
		System.out.println("The square root of " + x3 + " is " + squareroot(x3));
		
		
	}

}
