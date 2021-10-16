import java.io.File;
import java.io.FileNotFoundException;
import java.util.HashMap;
import java.util.Iterator;
import java.util.LinkedList;
import java.util.List;
import java.util.Scanner;

public class SeparateChainingHashTable<AnyType>
{
	
    private static final int DEFAULT_TABLE_SIZE = 101;

    /** HashTable: an array of linked lists. */
    private LinkedList [ ] HashTableSC; 
    private int currentSize;
	
    /**
     * Construct the hash table.
     */
    public SeparateChainingHashTable( )
    {
        this( DEFAULT_TABLE_SIZE );
    }

    /**
     * Construct the hash table.
     * @param size approximate table size.
     */
    public SeparateChainingHashTable( int size )
    {
        HashTableSC = new LinkedList[ size ];
        for( int i = 0; i < HashTableSC.length; i++ )
            HashTableSC[ i ] = new LinkedList<AnyType>( );
    }

    /**
     * Insert into the hash table. If the item is
     * already present, then update the item.
     * @param x the item to insert.
     */
    public void insert( Object gkey, Object gvalue )
    {
        int map_value = myhash( gkey );
		List<Item> whichList = HashTableSC[ map_value ];
        
        
        int getindex = keyexist(whichList, gkey);
        Item newitem = new Item(gkey,gvalue);
    
        if( getindex == -1 )
        {
        	currentSize++;
        	whichList.add(newitem);
        }
        else
        {    
        	//System.out.println("new value "+ gvalue);
        	//System.out.println("current value in the list "+ whichList.get(getindex).value);
        	//If the item exists, overwrite it.
			whichList.set(getindex, newitem);
        }

    }

    /**
     * Remove from the hash table.
     * @param x the item to remove.
     */
    public void remove( Object gkey )
    {
        int map_value = myhash( gkey );
		List<Item> whichList = HashTableSC[ map_value ];
        int getindex = keyexist(whichList, gkey);
        if( getindex != -1 )
        {
        	whichList.remove(getindex);
            currentSize--;
        }
    }
    
    public int keyexist(List<Item> glist, Object gkey)
    {
    	Iterator<Item> iterator = glist.iterator();
    	int index = 0;
        while (iterator.hasNext()) {
            Item current = iterator.next();
            if (current.key.equals(gkey)) {
            	//System.out.println("size of list "+glist.size());
            	//System.out.println("index " + index);
                return index;
            }
            index++;
        }
        return -1;
    	
    }
    
    public Item get( Object gkey )
    {
       int map_value = myhash( gkey );
		List<Item> whichList = HashTableSC[ map_value ];
        int getindex = keyexist(whichList, gkey);
        if( getindex != -1 )
        {
        	return whichList.get(getindex);
        }
        
        return null;
    }
    
    /**
     * Find an item in the hash table.
     * @param string the item to search for.
     * @return true if x isnot found.
     */
    public boolean contains( Object gkey )
    {
        List<Item> whichList = HashTableSC[ myhash( gkey ) ];
        Iterator<Item> iterator = whichList.iterator();
        while (iterator.hasNext()) {
            Item current = iterator.next();
            if (current.key.equals(gkey)) {
            	//System.out.println("size of list "+glist.size());
            	//System.out.println("index " + index);
                return true;
            }

        }
        return false;
    }
    
    public boolean containsValue( Object gvalue )
    {
       for(int i = 0; i < HashTableSC.length; i++)
       {
    	List<Item> whichList = HashTableSC[ i ];
        Iterator<Item> iterator = whichList.iterator();
        while (iterator.hasNext()) {
            Item current = iterator.next();
            if (current.value.equals(gvalue)) {

                return true;
            }

        }
       }
        return false;
    }

    /**
     * Make the hash table logically empty.
     */
    public void makeEmpty( )
    {
        for( int i = 0; i < HashTableSC.length; i++ )
            HashTableSC[ i ].clear( );
        currentSize = 0;    
    }




    private int myhash( Object x )
    {
        int hashVal = x.hashCode( );

        hashVal %= HashTableSC.length;
        if( hashVal < 0 )
            hashVal += HashTableSC.length;

        return hashVal;
    }
    
    public int itemsize()
    {
    	//Complete the itemsize() to return the number of items stored int the hashtable
	return currentSize;
		
    	
    }
 

        // Simple main
    public static void main( String [ ] args ) throws FileNotFoundException
    {

       
       
    	File file = new File("AccessLog.txt");// Replace path_to_AccessLog.txt by the path of AccessLog.txt on your computer, i.e., if you place the AccessLog.txt on the desktop of Windows, most likely, the path would be "C:/Users/Bowu/Desktop/AccessLog.txt"
		Scanner sc = new Scanner(file);
		SeparateChainingHashTable hm = new SeparateChainingHashTable(); // new hashtable
		
		 while (sc.hasNextLine()) //Read access log line by line
		 {
			 String[] parts = sc.nextLine().split("\\s+");
			 //split each line, i.e., "67.218.116.165 30/Jan/2010 00:03:18" into 3 parts
			 //"67.218.116.165", "30/Jan/2010", and "00:03:18"
			 //save into parts[]
			 //i.e., for the line of "67.218.116.165 30/Jan/2010 00:03:18" 
			 // parts[0] = "67.218.116.165", parts[1] = "30/Jan/2010", and parts[2] = "00:03:18"
			 
			 //Complete the method
			 //Insert item (IP, counter) into the hashtable
			 //Your method must use SeparateChainingHashTable
		 	hm.insert(parts[0], parts[0]);
			 
		 }
		 
		// test statement
	
		System.out.println(hm.itemsize());
		//Add output statement to find out how many unique IP addresses in the Access log.
		//Output should be 22

    	
    	
    
        
       
        
		 
		 

    	
    

    }

}
