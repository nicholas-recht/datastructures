/***********************************************************************
 * Header:
 *    NOW SERVING
 * Summary:
 *    This contains the class definition for the Request class, which
 *    encapsulates a request for help
 * Author
 *    Justin Ricks
 ************************************************************************/

#ifndef NOW_SERVING_H
#define NOW_SERVING_H

#include <string>

// the interactive nowServing program
void nowServing();

/************************************************
 * Request class
 * This class encapsulates all the data necessary
 * to simulate a student's help request in the
 * Linux lab
 ***********************************************/
class Request
{
  public:
   // default constructor
   Request() : urgent(false), course(""), name(""), minutes(0) {}
   // non-default constructor
   Request(bool urgent, std::string course, std::string name, int minutes);

   // assignment operator
   Request & operator = (const Request & rhs);

   // getters
   bool isUrgent()         { return urgent;  }
   int getMinutes()        { return minutes; }
   std::string getCourse() { return course;  }
   std::string getName()   { return name;    }

   // decrement the number of minutes
   void decrementMinutes() { minutes--; }

  private:
   bool urgent;
   int minutes;
   std::string course;
   std::string name;
};

#endif // NOW_SERVING_H
