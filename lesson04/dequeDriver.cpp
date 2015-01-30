/***********************************************************************
 * DEQUEDRIVER.CPP
 * Summary:
 *    This is a simple driver program to test the Deque Class. It tests
 *    the copy constructor, assignment operator, push, pop, front, and
 *    empty functions. 
 * Author
 *    Nicholas Recht
 ************************************************************************/

#include "deque.h"
#include <iostream>

using namespace std;

//Driver Program
int main()
{
   Deque<int> q(4);
   char input = 'o';
   int inputInt = 0; 

   while (input != 'x')
   {
      try
      {
         cout << "What would you like to do?\n"
              << "\t(x quit, f push_front,\n"
              << "\tu pop_front, b push_back,\n"
              << "\tr pop_back, c copy): ";
         
         cin >> input;
         
         if (input == 'f')
         {
            
            cin >> inputInt; 
            q.push_front(inputInt);
         }
         else if (input == 'u')
            q.pop_front();
         else if (input == 'b')
         {
            
            cin >> inputInt; 
            q.push_back(inputInt);
         }
         else if (input == 'r')
            q.pop_back();
         else if (input == 'c')
         {
            Deque<int> temp(q);
            q.clear();
            q = temp; 
            
         }

         cout << endl << "Is Empty: " << q.empty() << endl; 
         
         if (!q.empty())
         {
            cout << "Front is: " << q.front() << endl;
            cout << "Back is: " << q.back() << endl;
         }

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
