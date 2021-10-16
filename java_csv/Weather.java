import java.io.BufferedReader;
import java.io.FileReader;
import java.io.FileNotFoundException;
import java.io.IOException;

public class Weather {
    public static int readCsv(String path) {
        BufferedReader csvReader;
        try {
            csvReader = new BufferedReader(new FileReader(path));
        } catch (FileNotFoundException e) {
            return -1;
        }
        boolean firstLine = true;
        int minDay = -1;
        int minSpread = Integer.MAX_VALUE;
        String row;
        try {
            while ((row = csvReader.readLine()) != null) {
                if (firstLine) {
                    firstLine = false;
                    continue;
                }
                String[] data = row.split(",");
                try {
                    int max = Integer.parseInt(data[1]);
                    int min = Integer.parseInt(data[2]);
                    if (max-min < minSpread) {
                        minSpread = max-min;
                        minDay = Integer.parseInt(data[0]);
                    }
                } catch (ArrayIndexOutOfBoundsException e) {
                    continue;
                }
            }
        } catch(FileNotFoundException e) {
            return -1;
        } catch(IOException e) {
            return -1;
        }
        return minDay;
    }

        
    public static void main(String args[]) {
        System.out.println("The day with the minimum temperature spread is " + readCsv("Albany_Climate_Data082019.csv"));
    }
}
