import java.io.File;
import java.io.FileNotFoundException;
import java.util.Scanner;
import java.util.ArrayList;

public class Regiments {
    public static void main(String[] args) {
        Army army = new Army();
        File file = new File("regiments.txt");
        Scanner s;
        try {
            s = new Scanner(file);
        } catch(FileNotFoundException e) {
            return;
        }
        while (s.hasNextLine()) {
            String line = s.nextLine();
            String[] splitline = line.split("\\s+");
            int number = Integer.parseInt(splitline[0]);
            army.addRegiment(new Regiment(number, splitline[1], 1000 - 50*(number-1)));
        }
        for (int i = 0; i < 20; i++) {
            for (Regiment r : army.regiments) {
                r.strength += 100;
                if (r.number == 5) {
                    r.strength -= 70;
                }
            }
            army.printReport();
        }    
    }
}

class Regiment {
    int number;
    String name;
    int strength;
   public Regiment(int number, String name, int strength) {
       this.number = number;
       this.name = name;
       this.strength = strength;
   }
   public String[] vector() {
       return new String [] {Integer.toString(number), name, Integer.toString(strength)};
   }
}

class Army {
    ArrayList<Regiment> regiments;
    int week;
    public Army() {
        regiments = new ArrayList<Regiment>();
        week = 0;
    }
    public void addRegiment(Regiment r) {
        regiments.add(r);
    }
    public void strengthenRegiment(int regimentNumber, int numMen) {
        regiments.get(regimentNumber).strength += numMen;
    }
    public Regiment getStrongest() {
        Regiment strongest = null;
        for (Regiment r : regiments) {
            if (strongest == null || strongest.strength < r.strength) {
                strongest = r;
            }
        }
        return strongest;
    }
    public void printReport() {
        System.out.format("Progress report on the vojna in Manchuria and Korea for the glorification of the Motherland, Week %d%n%n", week);
        Regiment zarya = getStrongest();
        System.out.format("The %s are STRONG. This week they will find glory on the front.%n%n", zarya.name);
        regiments.remove(zarya);
        Object[] header = new String[] {"Number", "Name", "Strength"};
        System.out.format("%15s%15s%15s%n", header);
        System.out.format("%15s%15s%15s%n%n", (Object[])zarya.vector());

        if (regiments.size() > 0) {
            System.out.format("The remaining regiments ready for battle, and await their moment to seize glory for Mother Russia.%n%n");
            System.out.format("%15s%15s%15s%n", header);
            for (Regiment r : regiments) {
                System.out.format("%15s%15s%15s%n", (Object[])r.vector());
            }
        }
        System.out.format("%n%n%n");
        week += 1;
    }
}
