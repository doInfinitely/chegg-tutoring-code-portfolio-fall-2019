package s340.software.os;

public class ProcessControlBlock
{
    private int acc;
    private int x;
    private int pc;
    private ProcessState state;
    
    public ProcessControlBlock()
    {
        this.acc = 0;
        this.x = 0;
        this.pc = 0;
        this.state = ProcessState.READY;
    }
    
    public void setAcc(int acc)
    {
        this.acc = acc;
    }
    
    public int getAcc()
    {
        return acc;
    }
    
    public void setX(int x)
    {
        this.x = x;
    }
    
    public int getX()
    {
        return x;
    }
    
    public void setPC(int pc)
    {
        this.pc = pc;
    }
    
    public int getPC()
    {
        return pc;
    }
    
    public void setState(ProcessState state)
    {
        this.state = state;
    }
    
    public ProcessState getState()
    {
        return state;
    }
}