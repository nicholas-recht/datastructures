#include "stack.h"
#include <iostream>
using namespace std;

int main()
{
   Stack<int> s;
   s.push(1);
   s.push(1);
   cout << s.top() << '\n';
   s.pop();
   s.push(4);
   s.pop();
   s.push(5);
   s.pop();
   s.push(6);
   cout << s.top() << '\n';
   s.push(1);
   s.pop();
   s.push(9);
   s.pop();
   cout << s.top() << '\n';
   
   Stack<int> q = s;
   q.pop();
   cout << q.top() << '\n';
   cout << s.top() << '\n';


   return 0;
}
