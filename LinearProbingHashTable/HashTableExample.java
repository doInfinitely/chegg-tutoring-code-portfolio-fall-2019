import java.awt.*;
import java.util.*;

public class HashTableExample {
static void Insert(int[] hashTable, int size, int x) {
int index = x % size;
if (hashTable[index] == -1) {
hashTable[index] = x;
} else {
Boolean valueWasInserted = false;
for (int i = 1; i < size; i++) {
if (hashTable[i + index] == -1) {
hashTable[i + index] = x;
valueWasInserted = true;
break;
}
}
if (!valueWasInserted) {
System.out.println("Error: " + x);
}
}
}

static void PrintTable(int[] hashTable) {
System.out.println("\nTable:");
for (int v : hashTable)
System.out.print(v + ", ");
}

public static void main(String args[]) {

// Create a HashTable to store 
// String values corresponding to integer keys 
int size = 6;
int[] hashTable = new int[size];

for (int i = 0; i < size; i++) {
hashTable[i] = -1;
}

Insert(hashTable, size, 1);
PrintTable(hashTable);
Insert(hashTable, size, 0);
PrintTable(hashTable);
Insert(hashTable, size, 5);
PrintTable(hashTable);
}
}
