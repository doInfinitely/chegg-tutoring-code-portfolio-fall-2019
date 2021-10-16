// 11/10/19
#include <iostream>
#include "suqueuearr.h"
#include "sustackarr.h"
#include "suqueuelist.h"
#include "sustacklist.h"

int main (){
 SUQueueArr<int> a;
 SUQueueList<int> b;
 //SUStackArr<int> c;
 SUStackList<int> d;
 int f, g, h, i;
 bool t = true, u = true, v = true, w = true;
 
  t = a.isEmpty();
  if (t == false)
  {
  a.enqueue(10); //adds values into queue
  a.enqueue(20);
  a.enqueue(30);
  a.enqueue(40);
  a.enqueue(50);
  a.enqueue(60);
  a.printQueue();
  a.dequeue(f); //remove value
  cout << "Deleted value is " << f << endl;
  cout << endl << "copied list" << endl;
  SUQueueArr<int> k(a);
  k.printQueue(); 
  f = a.size();
  cout << "Size is " << f << endl;
  }
 /* 
  u = b.isEmpty();
  if (u == false)
  {
  b.enqueue(10); //adds values into queue
  b.enqueue(20);
  b.enqueue(30);
  b.enqueue(40);
  b.enqueue(50);
  b.enqueue(60);
  b.dequeue(g); //remove value
  cout << endl << "copied list" << endl;
  SUQueueList<int> l(b);
  l.printQueue();  
  b.size();
  }
  
  v = c.isEmpty();
  if (v == false)
  {
  c.push(10); //adds values into stack
  c.push(20);
  c.push(30);
  c.push(40);
  c.push(50);
  c.push(60);
  c.pop(h); //remove value
  cout << endl << "copied list" << endl;
  SUStackArr<int> m(c);
  m.printStack();
  c.size();
  }
  
  w = d.isEmpty();
  if (w == false)
  {
  d.push(10); //adds values into stack
  d.push(20);
  d.push(30);
  d.push(40);
  d.push(50);
  d.push(60);
  d.pop(i); //remove value
  cout << endl << "copied list" << endl;
  SUStackList<int> n(d);
  n.printStack();  
  d.size();
  }
*/  
  return 0;
}
