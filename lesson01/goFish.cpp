/***********************************************************************
* Program:
*    Assignment 01, Go Fish
*    Brother Helfrich, CS 235
* Author:
*    Adam Cameron
* Summary: 
*    This is all the functions necessary to play Go Fish!
*
*    Estimated:  3.0 hrs   
*    Actual:     3.0 hrs
*      The most difficult part was reading the hand from a file. Often it
*      read an invalid card which would give the user a free guess.
************************************************************************/

#include <iostream>
#include <fstream>
#include "set.h"
#include "goFish.h"
#include "card.h"

using namespace std;

#define NUM_ROUNDS 5

/**********************************************************************
 * GO FISH
 * The function which starts it all
 ***********************************************************************/

void goFish()
//int main()
{
   //initial setup
   Set <Card> hand;
   string s;
   int matches = 0; 

   //reading in the hand
   ifstream in("/home/cs235/lesson01/hand.txt");
   while(!in.eof())
   {
      //read to temorary Card
      Card toHand;
      in >> toHand;
      
      //add only valid cards
      if (toHand != Card("INVALID"))
         hand.insert(toHand);
   }

   //friendly greeting
   cout << "We will play " << NUM_ROUNDS << " rounds of Go Fish.  "
        << "Guess the card in the hand\n";
   
   //playing the game
   for (int i = 1; i <= NUM_ROUNDS; i++)
   {
      //user makes his guess
      cout << "round " << i << ": ";
      cin >> s;
      Card guess(s.c_str());

      // correct
      if (hand.find(guess) != hand.end())
      {
         matches++;
         hand.erase(hand.find(guess));
         cout << "\tYou got a match!\n";
      }
      //incorrect
      else 
         cout << "\tGo Fish!\n";
   }

   //the results
   cout << "You have " << matches << " matches!\n"
        << "The remaining cards: ";

     //bool for puntuation
   bool notFirst = false;
   for (SetIterator <Card> it = hand.begin(); it != hand.end(); it++)
   {
      if (notFirst)
         cout << ", ";
      else
        notFirst = true;
      cout << *it;
   }
   cout << '\n';
   return;
}
