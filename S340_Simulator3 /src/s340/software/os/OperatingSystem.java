package s340.software.os;

import s340.hardware.IInterruptHandler;
import s340.hardware.ISystemCallHandler;
import s340.hardware.ITrapHandler;
import s340.hardware.Machine;
import s340.hardware.Trap;
import s340.hardware.exception.MemoryFault;

/*
 * The operating system that controls the software running on the S340 CPU.
 *
 * The operating system acts as an interrupt handler, a system call handler, and
 * a trap handler.
 */


public class OperatingSystem implements IInterruptHandler, ISystemCallHandler, ITrapHandler
{

	// the machine on which we are running.
	private final Machine machine;
        private final int max = 10;
        private ProcessControlBlock[] process_table;
        private int processCount;

	/*
	 * Create an operating system on the given machine.
	 */
        
	public OperatingSystem(Machine machine) throws MemoryFault
	{
		this.machine = machine;
                this.process_table = new ProcessControlBlock[max];
                ProgramBuilder b0 = new ProgramBuilder();
                b0.start(0);
                b0.jmp(0);
                Program p0 = b0.build();
                schedule(p0);
                // Schedules the wait process by loading it into memory (at start location 0). The process is always ready to run.
                // The program is stored only at addresses 0 and 1 in memory because it is a single-instruction process.
                // The opcode 15 (interpreted as jmp) is stored at address 0, and its operand (0) is stored at address 1.
                // Creates a process control block entry in the process table corresponding to the wait process.
        }
        
        public ProcessControlBlock chooseNextProcess()
        {
                int pid = 0; // Need to identify the current process
                for (int i = pid + 1; i < processCount; i++)
                {
                    ProcessControlBlock pcb = process_table[i];
                    if (pcb.getState() == ProcessState.READY)
                        return pcb;
                }
                for (int i = 1; i <= pid; i++)
                {
                    ProcessControlBlock pcb = process_table[i];
                    if (pcb.getState() == ProcessState.READY)
                        return pcb;
                }
                return process_table[0];
        }
        
        /*
	 * Load a program into a given memory address in physical memory
	 */
        
	private int loadProgram(int startAddress, Program program) throws MemoryFault
	{
		int address = startAddress;
		for (int i : program.getCode())
		{
			machine.memory.store(address++, i);
		}
		return address;
	}

	/*
	 * Scheduled a list of programs to be run.
	 * 
	 * 
	 * @param programs the programs to schedule
	 */
	public void schedule(Program... programs) throws MemoryFault
	{
		for (Program program : programs)
		{
			loadProgram(program.getStart(), program);
                        ProcessControlBlock pcb = new ProcessControlBlock();
                        process_table[processCount++] = pcb;
		}
                
		// leave this as the last line
		machine.cpu.runProg.set(true);
	}

	/*
	 * Handle a trap from the hardware.
	 * 
	 * @param programCounter -- the program counter of the instruction after the
	 * one that caused the trap.
	 * 
	 * @param trapNumber -- the trap number for this trap.
	 */
	@Override
	public void trap(int savedProgramCounter, int trapNumber)
	{
		CheckValid.trapNumber(trapNumber);
		if (!machine.cpu.runProg.get())
		{
			return;
		}

		//	your code starts here
		switch (trapNumber)
		{
			case Trap.TIMER:
                                machine.cpu.runProg.set(false);
                                process_table[0].setState(ProcessState.READY); // Need to identify the current process
                                process_table[0].setAcc(machine.cpu.acc);
                                process_table[0].setX(machine.cpu.x);
                                process_table[0].setPC(savedProgramCounter);
                                ProcessControlBlock pcb = chooseNextProcess();
                                machine.cpu.acc = pcb.getAcc();
                                machine.cpu.x = pcb.getX();
                                machine.cpu.setPc(pcb.getPC());
                                pcb.setState(ProcessState.RUNNING);
                                machine.cpu.runProg.set(true);
				break;
			case Trap.END:
                                machine.cpu.runProg.set(false);
                                process_table[0].setState(ProcessState.DONE);
                                ProcessControlBlock pcb2 = chooseNextProcess();
                                machine.cpu.acc = pcb2.getAcc();
                                machine.cpu.x = pcb2.getX();
                                machine.cpu.setPc(pcb2.getPC());
                                pcb2.setState(ProcessState.RUNNING);
                                machine.cpu.runProg.set(true);
				break;
			default:
				System.err.println("UNHANDLED TRAP " + trapNumber);
				System.exit(1);
		}
	}

	/*
	 * Handle a system call from the software.
	 * 
	 * @param programCounter -- the program counter of the instruction after the
	 * one that caused the trap.
	 * 
	 * @param callNumber -- the callNumber of the system call.
	 * 
	 * @param address -- the memory address of any parameters for the system
	 * call.
	 */
	@Override
	public void syscall(int savedProgramCounter, int callNumber)
	{
		CheckValid.syscallNumber(callNumber);
		if (!machine.cpu.runProg.get())
		{
			return;
		}

		//	your code starts here
	}

	/*
	 * Handle an interrupt from the hardware.
	 * 
	 * @param programCounter -- the program counter of the instruction after the
	 * one that caused the trap.
	 * 
	 * @param deviceNumber -- the device number that is interrupting.
	 */
	@Override
	public void interrupt(int savedProgramCounter, int deviceNumber)
	{
		CheckValid.deviceNumber(deviceNumber);
		if (!machine.cpu.runProg.get())
		{
			return;
		}

		//	your code starts here
	}
}