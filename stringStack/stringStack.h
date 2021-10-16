#include <iostream>

using namespace std;

struct Node
{
    string data;
    struct Node* next;
    struct Node* prev;
};

class stringStack
{
    struct Node *root;
    struct Node *top;

  public:
    stringStack();
    ~stringStack();

    void push(string);
    string pop();
    void clear();
    bool empty();
};

stringStack::stringStack()
{
    top = NULL;
}

void stringStack::push(string x)
{
    if (top == NULL)
    {
        top = new Node();
	top->data = x;
    } else
    {
        top->next = new Node();
        top->next->data = x;
        top->next->prev = top;
        top = top->next;
        top->next = NULL;
    }
}

string stringStack::pop()
{
    string output = top->data;
    if (top->prev != NULL) {
        top = top->prev;
        delete top->next;
    } else {
        delete top;
        top = NULL;
    }
    return output;
}

bool stringStack::empty()
{
    return top == NULL;
}

void stringStack::clear()
{
    while(!empty())
    {
        pop();
    }
}

stringStack::~stringStack()
{
    clear();
}
