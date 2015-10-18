#ifndef STRATEGY_H
#define STRATEGY_H
#include <map>
#include <iostream>
#include <memory>
#include <vector>
#include <set>
#include "Order.h"
#include "Broker.h"

/**
 * @class Quote
 * @author vagesh
 * @date 18/10/2015
 * @file Strategy.h
 * @brief Used in Strategy class functions in calculation of best quotes from brokers
 * for client orders
 */

class Quote
{
    double quotePrice;
    string brokerName;
    void SetQuotePrice(double price)
    {
        quotePrice = price;
    }
    void SetBroker(string name)
    {
        brokerName = name;
    }
    friend class Comparator;

public:
    Quote(double price, string brkr)
        : quotePrice(price)
        , brokerName(brkr)
    {
    }
    double GetQuotePrice() const
    {
        return quotePrice;
    }
    string GetBroker() const
    {
        return brokerName;
    }
};

/**
 * @class Comparator
 * @author vagesh
 * @date 18/10/2015
 * @file Strategy.h
 * @brief functor to be used as comparison function set of quotes which can have quotes from multiple brokers
 */
class Comparator
{
public:
    bool operator()(const Quote& lhs, const Quote& rhs)
    {
        return (lhs.quotePrice < rhs.quotePrice);
    }
};

/**
 * @class Strategy
 * @author vagesh
 * @date 18/10/2015
 * @file Strategy.h
 * @brief Core logic class for application matching orders from clients and Broker's quotes
 */
class Strategy
{
    vector<shared_ptr<AbstractBroker> > brokerList;
    map<string, int> brokerAudit;
    map<string, vector<shared_ptr<Order> > > clientAudit;
    set<Quote, Comparator> quoteSet;
    double quotePrice;
    string brokerName;
    int quantityOfOrder;
    string orderType;

public:
    inline double GetQuotePrice()
    {
        return quotePrice;
    }
    inline string GetBrokerName()
    {
        return brokerName;
    }
    inline void AddBroker(shared_ptr<AbstractBroker> broker)
    {
        brokerList.push_back(broker);
    }
    int AllocateOrderToBrokers(string client, string orderType, int quantity);
    void PrintBrokersTokenTransacted();
    void PrintClientNetHoldings();
    void UpdateQuotes(int quantity, shared_ptr<Order> clientOrder);
    void ViewBuySellTrans();
};

#endif