/***********************************************************************
 * Implementation:
 *    NOW SERVING
 * Summary:
 *    Contains the nowServing function, and also implements the methods
 *    for the Request class
 * Author
 *    Justin Ricks
 **********************************************************************/

#include "nowServing.h" // for nowServing() prototype
#include "deque.h"      // for DEQUE
#include <string>
#include <iostream>

using namespace std;

/************************************************
 * NOW SERVING
 * The interactive function allowing the user to
 * handle help requests in the Linux lab
 ***********************************************/
void nowServing()
{
   // a deque to hold all the requests
   Deque <Request> requests;

   // temporary variable to hold the current request
   Request tempRequest;
   
   // instructions
   cout << "Every prompt is one minute.  The following input is accepted:\n";
   cout << "\t<class> <name> <#minutes>    : a normal help request\n";
   cout << "\t!! <class> <name> <#minutes> : an emergency help request\n";
   cout << "\tnone                         : no new request this minute\n";
   cout << "\tfinished                     : end simulation\n";

   string input;
   int i = 0;

   do
   {
      // if we're done serving, try to add the next one
      if (!tempRequest.getMinutes())
      {
         if (!requests.empty())
         {
            tempRequest = requests.front();
            requests.pop_front();
         }
      }
      // if we are now serving, say who we are serving
      if (tempRequest.getMinutes())
      {
         // two different messages for if it's an emergency
         if (tempRequest.isUrgent())
         {
            cout << "\tEmergency for " << tempRequest.getName()
                 << " for class " << tempRequest.getCourse()
                 << ". Time left: " << tempRequest.getMinutes() << endl;
         }
         else
         {
            cout << "\tCurrently serving " << tempRequest.getName()
                 << " for class " << tempRequest.getCourse()
                 << ". Time left: " << tempRequest.getMinutes() << endl;
         }
      }

      // the main prompt
      cout << "<" << i << "> ";
      cin  >> input;

      // don't do anything if we get 'none'
      if (input != "none")
      {
         // quit case
         if (input == "finished")
            break;

         // it's urgent!!
         if (input == "!!")
         {
            bool urgent = true;
            string course;
            string name;
            int minutes = 0;

            // get all the input
            cin >> course;
            cin >> name;
            cin >> minutes;

            // create a Request object with the data
            Request req(urgent, course, name, minutes);

            // then push it to the front of the queue
            requests.push_front(req);
         }

         // otherwise, it should be a normal request
         else
         {
            bool urgent = false;
            string course;
            string name;
            int minutes = 0;

            // get all the input
            course = input;
            cin >> name;
            cin >> minutes;

            // create a Request object with the data
            Request req(urgent, course, name, minutes);

            // then push it to the back of the queue
            requests.push_back(req);
         }
      }

      // time marches forward!
      i++;

      // decrement the number of minutes left in the request
      if (tempRequest.getMinutes())
         tempRequest.decrementMinutes();
      
   }
   while (input != "finished");
   

   // finished!
   cout << "End of simulation\n";
}

/************************************************
 * REQUEST :: NON-DEFAULT CONSTRUCTOR
 * set all the variables of a Request object
 ***********************************************/
Request :: Request(bool urgent, std::string course, std::string name, int minutes)
{
   this->urgent  = urgent;
   this->course  = course;
   this->name    = name;
   this->minutes = minutes;
}

/************************************************
 * REQUEST :: ASSIGNMENT OPERATOR
 * Copy all the data over
 ***********************************************/
Request & Request :: operator = (const Request & rhs)
{
   this->urgent  = rhs.urgent;
   this->course  = rhs.course;
   this->name    = rhs.name;
   this->minutes = rhs.minutes;

   return *this;
}
