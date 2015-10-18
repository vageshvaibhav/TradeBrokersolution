#ifndef USERINTERFACE_H
#define USERINTERFACE_H
#include "Strategy.h"
#include <string>
#include <stdlib.h>
using namespace std;
/**
 * @class AbstractUserInterface
 * @author vagesh
 * @date 18/10/2015
 * @file UserInterface.h
 * @brief 
 * Class for providing User interface for application
 * Abstract Interface added for making it extensible
 */
class AbstractUserInterface
{
protected:
    bool input;
    int qty;
    string choice, clientName;
    shared_ptr<Strategy> coreStrategy;

public:
    virtual void Init(shared_ptr<Strategy> str) = 0;
    virtual void ShowUserOptions() = 0;
    virtual void ViewBrokerTransactions() = 0;
    virtual void ViewNetClientHoldings() = 0;
    virtual void ExecuteOrder(string client, string orderType, int quantity) = 0;
    virtual bool ValidateInput(string client, int quantity) = 0;
};

class ConsoleUserInterface : public AbstractUserInterface
{
public:
    virtual void Init(shared_ptr<Strategy> str) override;
    virtual void ShowUserOptions() override;
    virtual void ViewBrokerTransactions() override;
    virtual void ViewNetClientHoldings() override;
    virtual void ExecuteOrder(string client, string orderType, int quantity) override;
    virtual bool ValidateInput(string client, int quantity);
    void ViewHistoricalTransactions();
};

#endif