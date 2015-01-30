#include "wholeNumber.h"
#include <iostream>

using namespace std;

void wholenumberdriver()
{
   WholeNumber w1;
   WholeNumber w2;
   string oper; 

   while (oper != "quit")
   {
      cout << "Enter a whole number: ";
      cin >> w1;

      cout << "Your number is: " << w1 << endl;

      cout << "Enter an operator(+, -, *, ^, >, <, or quit): ";
      cin >> oper;

      if (oper == "quit")
         return; 
      
      cout << "Enter a second number: ";
      cin >> w2;
      
      cout << "Your number is: " << w2 << endl;
      
      cout << w1 << " " << oper << " " << w2 << " =\n";

      if (oper == "+")
         cout << w1 + w2 << endl;
      else if (oper == "-")
         cout << w1 - w2 << endl;
      else if (oper == "*")
         cout << w1 * w2 << endl;
      else if (oper == "^")
         cout << pow(w1, w2) << endl;
      else if (oper == ">")
         cout << (w1 > w2) << endl;
      else if (oper == "<")
         cout << (w1 < w2) << endl; 
   }
   
   return;
}
