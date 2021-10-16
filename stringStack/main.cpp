#include "stringStack.h"
#include "stringQueue.h"

int main() {
    stringQueue *q = new stringQueue();
    q->enQueue("check");
    q->enQueue("me");
    q->enQueue("out");
    cout << q->deQueue() << endl;
    cout << q->deQueue() << endl;
    cout << q->deQueue() << endl;
    delete q;
    return 0;
}
