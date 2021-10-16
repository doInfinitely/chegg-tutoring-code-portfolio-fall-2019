class stringQueue
{
    stringStack *A;
    stringStack *B;
  public:
    stringQueue();
    ~stringQueue();
    void enQueue(string x);
    string deQueue();
    int size();
  private:
    int length;
};

stringQueue::stringQueue()
{
    A = new stringStack();
    B = new stringStack();
    length = 0;
}

void stringQueue::enQueue(string x)
{
    A->push(x);
    ++length;
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
    --length;
    return B->pop();
}

int stringQueue::size() {
    return length;
}

stringQueue::~stringQueue() {
    delete A;
    delete B;
}
