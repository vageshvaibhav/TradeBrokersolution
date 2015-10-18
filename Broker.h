#ifndef BROKER_H
#define BROKER_H
#include <string>
using namespace std;

/**
 * @class AbstractBroker
 * @author vagesh
 * @date 18/10/2015
 * @file Broker.h
 * @brief 
 * Class representing Broker and attributes. Abstract interface added for dependency inversion
 */

class AbstractBroker
{
protected:
    double commission;
    double conversionRate;
    string brokerName;
    double getCommission()
    {
        return commission;
    }
    void setCommission(double comsn)
    {
        commission = comsn;
    }
    double getConversionRate()
    {
        return conversionRate;
    }
    void setConversionRate(double cvrate)
    {
        conversionRate = cvrate;
    }

public:
    virtual double CalculateQuote(int quantity) = 0;
    virtual void Init(string name) = 0;
    virtual void setName(string name) = 0;
    string getName() const
    {
        return brokerName;
    }
};
class Broker1 : public AbstractBroker
{
public:
    virtual double CalculateQuote(int quantity) override;
    virtual void Init(string name) override;
    virtual void setName(string name) override
    {
        brokerName = name;
    }
};

class Broker2 : public AbstractBroker
{
public:
    virtual double CalculateQuote(int quantity) override;
    virtual void Init(string name) override;
    virtual void setName(string name) override
    {
        brokerName = name;
    }
};
#endif
