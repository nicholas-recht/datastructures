/***********************************************************************
* Implementation:
*    STOCK
* Summary:
*    This will contain the implementation for stocksBuySell() as well
*    as any other function or class implementation you need
* Author
*    Adam Cameron
*
*    Expected 5 hrs
*    Actual   7 hrs
**********************************************************************/

#include <iostream>    // for ISTREAM, OSTREAM, CIN, and COUT
#include <string>      // for STRING
#include <cassert>     // for ASSERT
#include "stock.h"     // for STOCK_TRANSACTION
#include "dollars.h"     // for STOCK_TRANSACTION
#include "queue.h"       // for QUEUE
using namespace std;


/******************************************************************
* PORTFOLIO :: BUY - allows the cilient to buy an inputted number
*                    of stocks at an inputted price per stock.
******************************************************************/
void Portfolio ::  buy(int numStocks, const Dollars & amountStocks)
{   
   //check for valid stock number
   if (numStocks < 1)
      return;

   //create new stock trnasaction
   stockTransaction newTransaction;
   newTransaction.numStocks = numStocks;
   newTransaction.buyPrice = amountStocks;

   //input new stock transaction to queue
   bought.push(newTransaction);
   return;
}
/******************************************************************
* PORTFOLIO :: SELL- allows the cilient to sell an inputted number
*                    of stocks for an inputted price per stock.
******************************************************************/
void Portfolio :: sell(int stocksToSell, const Dollars & amountStocks)
{
   if (stocksToSell < 1)
      return;

   //struct to record the details of the sale for the sale record
   stockTransaction newTransaction;
   newTransaction.sellPrice = amountStocks;
   
   //continue till the specified number of stocks have been sold
   //or there are are no more stocks to sell
   while(stocksToSell > 0 && !bought.empty())
   {
      //set newTrasaction
      newTransaction.buyPrice = bought.front().buyPrice;
      newTransaction.numStocks = 0;

      //sell stocks till the specified number is sold
      //or the first type of stocks added runs out
      while (stocksToSell > 0 && bought.front().numStocks > 0)
      {
         proceeds += (newTransaction.sellPrice - newTransaction.buyPrice);
         bought.front().numStocks--;
         stocksToSell--;
         newTransaction.numStocks++;
      }

      //if a type of stocks runs out move to the next one
      if(bought.front().numStocks == 0)
         bought.pop();

      // enter the new sale record
      sold.push(newTransaction);
   }
 
   return;
}

/******************************************************************
* PORTFOLIO :: DISPLAY - will display bought(but not sold) stocks,
*                        stock sales and total proceeds from sold
*                        stocks
******************************************************************/
void Portfolio :: display() const
{
   
   // display currently held
   Queue<stockTransaction> temp;
   temp = bought;
   if (!temp.empty())
      cout << "Currently held:\n";
   while (!temp.empty())
   {
       cout << "\tBought " << temp.front().numStocks 
            << " shares at " << temp.front().buyPrice << '\n';
       temp.pop();
   }

   //display sell history
   temp = sold;
   if (!temp.empty())
      cout << "Sell History:\n";
   while (!temp.empty())
   {   
       cout << "\tSold " << temp.front().numStocks 
         << " shares at " << temp.front().sellPrice << " for a profit of "
         << (temp.front().sellPrice - temp.front().buyPrice)*
            temp.front().numStocks
         << '\n';
       temp.pop();
   }
  
   //display proceeds
   cout << "Proceeds: " << proceeds << '\n';
}


/************************************************
 * STOCKS BUY SELL
 * The interactive function allowing the user to
 * buy and sell stocks
 ***********************************************/
//int main()
void stocksBuySell()
{
   Portfolio portfolio;

   // display instructions
   cout << "This program will allow you to buy and sell stocks. "
        << "The actions are:\n";
   cout << "  buy 200 $1.57   - Buy 200 shares at $1.57\n";
   cout << "  sell 150 $2.15  - Sell 150 shares at $2.15\n";
   cout << "  display         - Display your current stock portfolio\n";
   cout << "  quit            - Display a final report and quit the program\n";

   //receive user input
   while (1)
   {
      char input[50];
      cout << "> ";
      cin >> input;
      //interpret input using first letter
      bool error = 0;
      int numStocks;
      Dollars price;
      switch (input[0])
      {
         //buy
         case 'b':
            //receive data
            cin >> numStocks;
            cin >> price;
            //validate data
            if (cin.fail())
            {
               error = 1;
               cin.clear();
            }
            //perform buy
            else
               portfolio.buy(numStocks, price);
            break;
         //sell
         case 's':
            //receive data
            cin >> numStocks;
            cin >> price;
            //validate data
            if (cin.fail())
            {
               error = 1;
               cin.clear();
            }
            //perform buy
            else
               portfolio.sell(numStocks, price);
            break;
         //display
         case 'd':
            portfolio.display();
            break;
         //quit
         case 'q':
            return;
         default:
         error = 1;
      }
      //display error message if needed and prepare for next input
      cin.ignore(200, '\n');
      if (error)
         cout << "Error receiving input\n";
   }
}


