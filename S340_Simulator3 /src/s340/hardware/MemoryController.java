package s340.hardware;

import s340.hardware.exception.MemoryAddressException;
import s340.hardware.exception.MemoryFault;

/*
 * A basic memory controller.
 */
public class MemoryController
{

	private final int[] memory;
	private int base;
	private int limit;

	public MemoryController(int[] contents)
	{
		this.memory = contents;
		//	initial configuration so that virtual and physical addresses are the same thing
		this.base = 0;
		this.limit = memory.length;
	}

	public MemoryController(int size)
	{
		this(new int[size]);
	}

	//	set the base register fo the memory controller
	public void setBase(int base)
	{
		this.base = base;
	}

	//	set the limit register fo the memory controller
	public void setLimit(int limit)
	{
		this.limit = limit;
	}

	/*
	 * Check if a virtual memory address is valid.
	 */
	private void checkAddress(int vAddress) throws MemoryAddressException
	{
		if (vAddress < 0 || vAddress >= limit)
		{
			throw new MemoryAddressException(vAddress);
		}
	}

	/*
	 * Load the contents of a given virtual memory address.
	 */
	public int load(int address) throws MemoryFault
	{
		checkAddress(address);
		return memory[base + address];
	}

	/*
	 * Store a value into a given virtual memory address.
	 */
	public void store(int address, int value) throws MemoryFault
	{
		checkAddress(address);
		memory[base + address] = value;
                System.out.println(memory[0]);
                System.out.println(memory[1]);
                System.out.println(memory[2]);
                System.out.println(memory[3]);
	}
}