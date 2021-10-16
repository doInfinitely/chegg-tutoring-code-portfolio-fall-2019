import java.io.*;
import java.math.*;
import java.security.*;
import java.text.*;
import java.util.*;
import java.util.concurrent.*;
import java.util.function.*;
import java.util.regex.*;
import java.util.stream.*;
import static java.util.stream.Collectors.joining;
import static java.util.stream.Collectors.toList;
import java.lang.Math;
import java.util.Arrays;

class Result {

    /*
     * Complete the 'smellCosmos' function below.
     *
     * The function is expected to return a LONG_INTEGER_ARRAY.
     * The function accepts following parameters:
     *  1. LONG_INTEGER_ARRAY a
     *  2. LONG_INTEGER_ARRAY b
     */

    public static List<Long> convert(long number, int B, int m) {
        int x1 = 0;
        long x0 = number;
        int mult = (int) Math.pow(B, m);
        ArrayList<Long> output = new ArrayList<Long>();
        output.add(new Long(number/mult));
        output.add(new Long(number%mult));
        return output;
    }
    public static long kuratsuba(List<Long> x_converted, List<Long> y_converted, int B, int m) {
        long z2 = x_converted.get(0).longValue()*y_converted.get(0).longValue();
        long z0 = x_converted.get(1).longValue()*y_converted.get(1).longValue();
        long z1 = (x_converted.get(0).longValue()-x_converted.get(1).longValue())*(y_converted.get(1).longValue()-y_converted.get(0).longValue())+z2+z0;
        return z2*(long)Math.pow(B, 2*m) + z1*(long)Math.pow(B, m) + z0;
    }
        
    public static List<Long> smellCosmos(List<Long> a, List<Long> b) {
    // Write your code here
        int B = 10;
        int m = 3;
        ArrayList<Long> output = new ArrayList<Long>();
        for (int i = 0; i < a.size()+b.size()-1; i++)
             output.add(new Long(0));
        for (int i = 0; i < a.size(); i++) {
            for(int j = 0; j < b.size(); j++) {
                long coeff = output.get(i+j).longValue();
                coeff += kuratsuba(convert(a.get(i), B, m), convert(b.get(j), B, m), B, m);
                coeff %= (long)(Math.pow(10,9)+9);
                output.set(i+j, new Long(coeff));
            }
        }
        return output;
    }

}

public class Solution {
    public static void main(String[] args) throws IOException {
        BufferedReader bufferedReader = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bufferedWriter = new BufferedWriter(new FileWriter(System.getenv("OUTPUT_PATH")));

        int n = Integer.parseInt(bufferedReader.readLine().trim());

        List<Long> a = Stream.of(bufferedReader.readLine().replaceAll("\\s+$", "").split(" "))
            .map(Long::parseLong)
            .collect(toList());

        List<Long> b = Stream.of(bufferedReader.readLine().replaceAll("\\s+$", "").split(" "))
            .map(Long::parseLong)
            .collect(toList());

        List<Long> result = Result.smellCosmos(a, b);

        bufferedWriter.write(
            result.stream()
                .map(Object::toString)
                .collect(joining(" "))
            + "\n"
        );

        bufferedReader.close();
        bufferedWriter.close();
    }
}
