
public class Problem1 {

	public static int binarySearch(double[] A, double x, boolean start) {
		if (A.length == 0) {
			return 0;
		}
		if (A.length == 1) {
			if (A[0]  == x) {
				if (start) {
				return 0;
				}
				return 1;
			} else {
				if (x > A[0]) {
					return 1;
				}
				return 0;
			}
		}

		if (start) {
			if (A[A.length/2] >= x) {
				double[] temp = new double[A.length/2];
				for (int i = 0; i < temp.length; i++) {
					temp[i] = A[i];
				}
				return binarySearch(temp, x, start);
			} else {
				double[] temp = new double[A.length - A.length/2];
				for (int i = 0; i < temp.length; i++) {
					temp[i] = A[A.length/2+i];
				}
				return A.length/2 + binarySearch(temp, x, start);
			}
		} else {
			if (A[A.length/2] > x) {
				double[] temp = new double[A.length/2];
				for (int i = 0; i < temp.length; i++) {
					temp[i] = A[i];
				}
				return binarySearch(temp, x, start);
			} else {
				double[] temp = new double[A.length - A.length/2];
				for (int i = 0; i < temp.length; i++) {
					temp[i] = A[A.length/2+i];
				}
				return A.length/2 + binarySearch(temp, x, start);
			}	
		}
	}
	public static int count(double[] A, double x)
	{
		// given sorted array A, and a value x, return the number of times x occurs in A
		// complete the method count() here
		// O(log n) expected
		// O(n) or slower will be graded out of 10 points
		int end = binarySearch(A, x, false);
		int start = binarySearch(A, x, true);
		System.out.println(end);
		System.out.println(start);
		System.out.println();
		if (start == end) {
			if (A[start] == x) {
				return 1;
			} else {
				return 0;
			}
		}
		return end-start;
		
		
		
		
		
	}
	

	
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		// test your count() method here
		
		double[] testarray = {1.3, 2.1, 2.1, 2.1, 2.1, 6.7, 7.5, 7.5, 8.6, 9.0};
		double t1 = 2.1;
		double t2 = 7.5;
		double t3 = 1.3;
		System.out.println(t1+" appears "+ count(testarray, t1) + " times");
		System.out.println(t2+" appears "+ count(testarray, t2) + " times");
		System.out.println(t3+" appears "+ count(testarray, t3) + " times");
		
		
	}

}
