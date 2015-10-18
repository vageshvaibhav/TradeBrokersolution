#include "UserInterface.h"
#include <iostream>
#include <algorithm>
/**
 * @brief UI function for injecting core strategy class pointer for calculation purpose
 * @param str
 *
 */
void ConsoleUserInterface::Init(shared_ptr<Strategy> str)
{
    coreStrategy = str;
    input = true;
}

/**
 * @brief Takes input from user on console screen and calls particular action routine as per selection
 */
void ConsoleUserInterface::ShowUserOptions()
{

    int condition;
    while(input) {
        system("CLS");
        cout << "*************Welcome to the InvestoBank Application Admin Interface*************"
             << "\n\n\n\n";
        cout << "Enter the number for transaction type mentioned :" << endl;
        cout << "1.Execute Buy Order for client" << endl;
        cout << "2.Execute Sell Order for client" << endl;
        cout << "3.View Number of digicoins transacted by all Brokers" << endl;
        cout << "4.View All Client's net positions" << endl;
        cout << "5.View All transaction in a session" << endl;
        cin >> condition;
        switch(condition) {
        case 1:
            cout << "Enter client Name:" << endl;
            cin >> clientName;
            cout << "Enter quantity of digicoins :" << endl;
            cin >> qty;
            if(!clientName.empty()) {
                transform(clientName.begin(), clientName.end(), clientName.begin(), ::toupper);
            }
            ExecuteOrder(clientName, "BUY", qty);
            break;
        case 2:
            cout << "Enter client Name:" << endl;
            cin >> clientName;
            cout << "Enter quantity of digicoins :" << endl;
            cin >> qty;
            if(!clientName.empty()) {
                transform(clientName.begin(), clientName.end(), clientName.begin(), ::toupper);
            }
            ExecuteOrder(clientName, "SELL", qty);
            break;
        case 3:
            ViewBrokerTransactions();
            break;
        case 4:
            ViewNetClientHoldings();
            break;
        case 5:
            ViewHistoricalTransactions();
            break;
        default:
            cout << "\n Invalid Input Exiting \n";
            input = false;
            break;
        }
        if(input) {
            cout << "Do You Wish to continue: press y or n" << endl;
            cin >> choice;
            if(choice == "n")
                input = false;
        }
    }
}

/**
 * @brief Prints list of brokers and digicoins transacted by each broker
 *
 */
void ConsoleUserInterface::ViewBrokerTransactions()
{
    coreStrategy->PrintBrokersTokenTransacted();
}

/**
 * @brief 
 * Print Client net holdings for all clients using average transaction price per digicoin and net quantity 
 * considering Buy and Sell orders
 */
void ConsoleUserInterface::ViewNetClientHoldings()
{
    coreStrategy->PrintClientNetHoldings();
}

/**
 * @brief 
 * Print list of all client's order executed per session
 */
void ConsoleUserInterface::ViewHistoricalTransactions()
{
    coreStrategy->ViewBuySellTrans();
}

/**
 * @brief 
 * @param client name
 * @param orderType
 * @param quantity to be executed
 * Core UI function calling function to allocate Orders to Broker's quotes
 */
void ConsoleUserInterface::ExecuteOrder(string client, string orderType, int quantity)
{
    if(ValidateInput(client, quantity)) {
        coreStrategy->AllocateOrderToBrokers(client, orderType, quantity);
    }
}

/**
 * @brief 
 * @param client
 * @param quantity
 * @return true if validation success
 *Basic input validation as per assignment requirements
 */
bool ConsoleUserInterface::ValidateInput(string client, int quantity)
{
    if((quantity < 10) || (quantity > 200) ||
       (quantity % 10) != 0) { // Only two brokers supported in current req with limit of 100 each
        cout << "Quantity should be multiple of 10 and between 10 to 200";
        return false;
    }
    return true;
}