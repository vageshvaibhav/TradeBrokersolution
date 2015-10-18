#ifndef ORDER_H
#define ORDER_H
#include <string>
using namespace std;

/**
 * @class Order
 * @author vagesh
 * @date 18/10/2015
 * @file Order.h
 * @brief 
 * Class representing Client's Orders with all necessary properties.
 * Also contains set of brokers whose quotes were matched
 */

class Order
{    
    string clientName;
    string orderType;
    int quantity;
    double orderPrice;
    double averagePrice;
    set<string> BrokerName;
    friend class Strategy;
    void SetOrderType(string type)
    {
        orderType = type;
    }
    void SetQuantity(int qty)
    {
        quantity = qty;
    }

    void SetOrderPrice(double price)
    {
        orderPrice = price;
    }

    void SetAveragePrice(double avgPrice)
    {
        averagePrice = avgPrice;
    }

    void SetClientName(string client)
    {
        clientName = client;
    }

public:
    int GetQuantity() const
    {
        return quantity;
    }

    double GetOrderPrice() const
    {
        return orderPrice;
    }

    double GetAveragePrice() const
    {
        return averagePrice;
    }

    string GetClientName() const
    {
        return clientName;
    }

    string GetOrderType() const
    {
        return orderType;
    }

    void init(string clntname, string ordertp, int qty)
    {
        SetClientName(clntname);
        SetOrderType(ordertp);
        SetQuantity(qty);
    }
};
#endif