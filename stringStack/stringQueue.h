class stringQueue
{
    stringStack *A;
    stringStack *B;
  public:
    stringQueue();
    ~stringQueue();
    void enQueue(string x);
    string deQueue();
};

stringQueue::stringQueue()
{
    A = new stringStack();
    B = new stringStack();
}

void stringQueue::enQueue(string x)
{
    A->push(x);
}

string stringQueue::deQueue()
{
    if (B->empty())
    {
        while(!A->empty())
        {
            B->push(A->pop());
        }
    }
    return B->pop();
}

stringQueue::~stringQueue() {
    delete A;
    delete B;
}
