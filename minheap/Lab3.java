import java.io.*;
import java.util.*;

public class Lab3
{

    /**
     *  Problem 2: Use heaps to sort a given array in O(n log k) time.
     */
    private static void problem2(int[] arr, int k)
    {
        MinHeap heap = new MinHeap(k+2);
	    for (int i = 0; i < k+1; i++) {
		    heap.add(arr[i]);
	    }
	    for (int i = 0; i < arr.length; i++) {
            arr[i] = heap.removeMin();
            if (i + k + 1 < arr.length) {
                heap.add(arr[i+k+1]);
            }
        }

    }

    // ---------------------------------------------------------------------
    // Do not change any of the code below!

    private static final int LabNo = 3;
    private static final String quarter = "Winter 2019";

    private static final Random rng = new Random(123456);

    private static boolean testProblem1(int[][] testCase)
    {
        int[] arr = testCase[0];
        int index = testCase[1][0];

        int[] heapArr = arr.clone();
        MinHeap heap = new MinHeap(heapArr);

        // Make copy and "delete" element.
        int[] arrCopy = arr.clone();
        arrCopy[index] = arrCopy[arrCopy.length - 1];

        heap.delete(index);

        if (heap.getSize() != arr.length - 1)
        {
            return false;
        }

        // Check for heap property
        for (int i = 0; i < heap.getSize(); i++)
        {
            int parInd = (i - 1) / 2;
            int lefInd = 2 * i + 1;
            int rigInd = 2 * i + 2;

            if (i > 0 && heapArr[parInd] > heapArr[i])
            {
                return false;
            }

            if (lefInd < heap.getSize() && heapArr[lefInd] < heapArr[i])
            {
                return false;
            }

            if (rigInd < heap.getSize() && heapArr[rigInd] < heapArr[i])
            {
                return false;
            }
        }


        // Check if numbers are correct
        Arrays.sort(heapArr, 0, heap.getSize());
        Arrays.sort(arrCopy, 0, heap.getSize());

        for (int i = 0; i < heap.getSize(); i++)
        {
            if (heapArr[i] != arrCopy[i])
            {
                return false;
            }
        }

        return true;
    }

    private static boolean testProblem2(int[][] testCase)
    {
        int[] arr = testCase[0];
        int k = testCase[1][0];

        int[] testArr = arr.clone();
        int[] arr2 = arr.clone();
        Arrays.sort(arr2);

        problem2(testArr, k);

        // Check if arr is sorted
        for (int i = 0; i < testArr.length; i++)
        {
            if (arr2[i] != testArr[i])
            {
                return false;
            }
        }

        return true;
    }

    public static void main(String args[])
    {
        System.out.println("CS 302 -- " + quarter + " -- Lab " + LabNo);

        testProblems(1);
        testProblems(2);
    }

    private static void testProblems(int prob)
    {
        int noOfLines = 100000;

        System.out.println("-- -- -- -- --");
        System.out.println(noOfLines + " test cases for problem " + prob + ".");

        boolean passedAll = true;

        for (int i = 1; i <= noOfLines; i++)
        {

            int[][] testCase = null;

            boolean passed = false;
            boolean exce = false;

            try
            {
                switch (prob)
                {
                    case 1:
                        testCase = createProblem1(i);
                        passed = testProblem1(testCase);
                        break;

                    case 2:
                        testCase = createProblem2(i);
                        passed = testProblem2(testCase);
                        break;
                }
            }
            catch (Exception ex)
            {
                passed = false;
                exce = true;
            }

            if (!passed)
            {
                System.out.println("Test " + i + " failed!" + (exce ? " (Exception)" : ""));
                passedAll = false;

                switch (prob)
                {
                    case 1:
                        System.out.println("    arr: " + Arrays.toString(testCase[0]));
                        System.out.println("  index: " + testCase[1][0]);
                        break;

                    case 2:
                        System.out.println("  arr: " + Arrays.toString(testCase[0]));
                        System.out.println("    k: " + testCase[1][0]);
                        break;
                }

                break;
            }
        }

        if (passedAll)
        {
            System.out.println("All test passed.");
        }

    }

    private static int[][] createProblem1(int testNo)
    {
        int size = rng.nextInt(Math.min(5000, testNo)) + 10;

        int[] numbers = getRandomNumbers(size);
        MinHeap heap = new MinHeap(numbers);

        int index = rng.nextInt(size);

        return new int[][] { numbers, new int[] { index } };
    }

    private static int[][] createProblem2(int testNo)
    {
        int size = rng.nextInt(Math.min(50, testNo)) + 5;
        int[] k = new int[] { rng.nextInt(size - 3) + 3 };

        int[] numbers = getRandomNumbers(size);

        Arrays.sort(numbers);
        Hashtable<Integer, Integer> dic = GetShuffle(size, k);

        int[] buffer = new int[size];

        for (int i = 0; i < size; i++)
        {
            int shufInd = dic.get(i);
            buffer[shufInd] = numbers[i];
        }

        for (int i = 0; i < size; i++)
        {
            numbers[i] = buffer[i];
        }

        return new int[][] { numbers, k };
    }

    private static class ShuffleItem implements Comparable<ShuffleItem>
    {
        public int key;
        public double shift;

        @Override
        public int compareTo(ShuffleItem other) {
            Double thisDbl = shift;
            return thisDbl.compareTo(other.shift);
        }
    }

    private static Hashtable<Integer, Integer> GetShuffle(int size, int[] k)
    {
        ShuffleItem[] arr = new ShuffleItem[size];
        for (int i = 0; i < arr.length; i++)
        {
            arr[i] = new ShuffleItem();
            arr[i].key = i;
            arr[i].shift = i + rng.nextDouble() * k[0];
        }

        Arrays.sort(arr);

        int minDif = Integer.MAX_VALUE;
        int maxDif = Integer.MIN_VALUE;
        int minDifAbs = Integer.MAX_VALUE;
        int maxDifAbs = Integer.MIN_VALUE;

        Hashtable<Integer, Integer> dict = new Hashtable<Integer, Integer>();

        for (int i = 0; i < arr.length; i++)
        {
            int dif = i - arr[i].key;

            minDif = Math.min(minDif, dif);
            maxDif = Math.max(maxDif, dif);
            minDifAbs = Math.min(minDifAbs, Math.abs(dif));
            maxDifAbs = Math.max(maxDifAbs, Math.abs(dif));

            dict.put(arr[i].key, i);
        }

        k[0] = maxDifAbs;
        return dict;
    }

    private static void shuffle(int[] arr, int start, int length)
    {
        // Shuffle
        for (int i = 0; i < length; i++)
        {
            int baseInd = start + i;
            int rndInd = rng.nextInt(length - i) + baseInd;

            int tmp = arr[baseInd];
            arr[baseInd] = arr[rndInd];
            arr[rndInd] = tmp;
        }
    }

    private static int[] getRandomNumbers(int size)
    {
        int maxSize = size * 10;

        int[] integers = new int[maxSize];
        for (int i = 0; i < maxSize; i++)
        {
            integers[i] = i;
        }

        shuffle(integers, 0, integers.length);

        return Arrays.copyOf(integers, size);
    }

}
