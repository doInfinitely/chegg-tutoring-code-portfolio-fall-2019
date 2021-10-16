// Cuckoo Hash table class
//
// CONSTRUCTION: a hashing function family and
// an approximate initial size or default of 101
//
// ******************PUBLIC OPERATIONS*********************
// bool insert( x ) --> Insert x
// bool remove( x ) --> Remove x
// bool contains( x ) --> Return true if x is present
// void makeEmpty( ) --> Remove all items
// int size( ) --> Return number of items

/**
* Cuckoo hash table implementation of hash tables.
* @author Mark Allen Weiss
*/
public class CuckooHashTable
{
public int[] table1;
public int[] table2;
public int tableSize;

public int Hash1Function(int index)
{
return index*(tableSize-1) % tableSize;
}
public int Hash2Function(int index)
{
return (index+1)*(tableSize-1) % tableSize;
}

public CuckooHashTable(int tableSizeInput){
tableSize = tableSizeInput;
table1 = new int[tableSize];
table2 = new int[tableSize];
for(int i=0;i<tableSize;i++) {
table1[i] = -1;
table2[i] = -1;
}
}

public void Insert(int x)
{
InsertInternal(x,1);
}

public void InsertInternal(int x,int tableIndex)
{
if (tableIndex == 1)
{
int index = Hash1Function(x);
if ( table1[index] == -1 ){
table1[index] = x;
}
else
{
int xOld = table1[index];
table1[index] = x;
InsertInternal(xOld,2);
}
}
else
{
int index = Hash2Function(x);
if ( table2[index] == -1 ){
table2[index] = x;
}
else
{
int xOld = table2[index];
table2[index] = x;
InsertInternal(xOld,1);
}
}
}

// Simple main
public static void main( String [ ] args )
{
CuckooHashTable H = new CuckooHashTable( 5 );

H.Insert(1);
H.Insert(2);
H.Insert(5);
H.Insert(6);
}

}
