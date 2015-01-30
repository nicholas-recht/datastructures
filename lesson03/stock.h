/***********************************************************************
 * Header:
 *    STOCK
 * Summary:
 *    This will contain just the prototype for stocksBuySell(). It also 
 *    contains the header for the Portfolio and stockTrasaction struct
 *    which is neccesary for that class.
 * Author
 *    Adam Cameron
 ************************************************************************/

#ifndef STOCK_H
#define STOCK_H

#include "dollars.h"   // for Dollars defined in StockTransaction
#include "queue.h"     // for QUEUE
#include <iostream>    // for ISTREAM and OSTREAM

// the interactive stock buy/sell function
void stocksBuySell();

//structure contains the three data items that may pretain to a
//stock trasaction
struct stockTransaction
{
  int numStocks;
  Dollars buyPrice;
  Dollars sellPrice;
};

/******************************************************************
* CLASS PORTFOLIO - this class will maintain a history of stock
*                   trasactions. Stocks may be purchased or sold. 
*                   A list of currently held stocks, a list of 
*                   sold stocks and the current net proceeds may be
*                   displayed.
******************************************************************/
class Portfolio
{
   public:
      //constructor
      Portfolio() : proceeds(0) {}
   
      void buy(int numStocks, const Dollars & amountStocks);
      void sell(int numStocks, const Dollars & amountStocks);
      void display() const;

   private:
      Dollars proceeds;                //track net gain from sales
      Queue<stockTransaction> bought; //records stocks yet to be sold
      Queue<stockTransaction> sold;   //records stock sales and profits
};


#endif // STOCK_H

