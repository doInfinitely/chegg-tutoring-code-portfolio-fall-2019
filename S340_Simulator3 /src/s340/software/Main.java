package s340.software;

import s340.hardware.Machine;
import s340.software.os.OperatingSystem;
import s340.software.os.Program;
import s340.software.os.ProgramBuilder;

public class Main
{
	public static void main(String[] args) throws Exception
	{
            //	setup the hardware, the operating system, and power up
            //	do not remove this
            Machine machine = new Machine();
            OperatingSystem os = new OperatingSystem(machine);
            machine.powerUp(os);

            // Need to fix program
            ProgramBuilder b1 = new ProgramBuilder();
            final int sum = 100;
            final int i = 200;
            final int startAddress = 2;
            b1.start(startAddress);
            b1.size(32); // number of words of data (the data size)
            b1.loadi(0); // Acc = 0
            b1.store(sum); // sum = 0
            b1.loadi(1); // Acc = 1
            b1.store(i); // i = 1
            b1.subi(101); // // Acc = i - 101
            b1.jzero(28); // change argument later
            b1.load(i); // Acc = i
            b1.add(sum); // Acc = i + sum
            b1.store(sum); // sum = Acc
            b1.load(i); // Acc = i
            b1.inca(); // Acc = i + 1
            b1.store(i); // i = i + 1
            b1.jmp(10); // PC = 10
            b1.load(sum); // Acc = sum
            b1.output(); // Print Acc
            b1.end(); // End the current program
            Program p1 = b1.build();
            System.out.println(p1);
            os.schedule(p1);
	}
}
