/***********************************************************************
 * QUEUEDRIVER.CPP
 * Summary:
 *    This is a simple driver program to test the Queue Class. It tests
 *    the copy constructor, assignment operator, push, pop, front, and
 *    empty functions. 
 * Author
 *    Nicholas Recht
 ************************************************************************/

#include "queue.h"
#include <iostream>

using namespace std;

//Driver Program
int main()
{
   Queue<int> q;
   char input = 'o';
   int inputInt = 0; 

   while (input != 'x')
   {
      try
      {
         cout << "What would you like to do (x, quit; p, push, u, pop, c copy): ";
         
         cin >> input;
         
         if (input == 'p')
         {
            
            cin >> inputInt; 
            q.push(inputInt);
         }
         else if (input == 'u')
            q.pop();
         else if (input == 'c')
         {
            Queue<int> temp(q);
            q.clear();
            q = temp; 
            
         }

         cout << endl << "Is Empty: " << q.empty() << endl; 
         
         if (!q.empty())
            cout << "Front is: " << q.front() << endl;

         cout << "Capacity is: " << q.capacity() << endl; 
      }

      //TEST some Errors!
      catch (const char * p)
      {
         cout << p << endl;
      }
   }
   return 0;
}
