#include "Strategy.h"

/**
 * @brief Prints net client holdings as per logic mentioned in assignement problem
 * Calculates average of transaction value for each client and multiply by total quantity
 * after considering buy and sell transactions
 */
void Strategy::PrintClientNetHoldings()
{
    for(auto& iterclientAudit : clientAudit) {
        double averagePriceTrn = 0;
        int netQuantity = 0;
        for(auto& iterVector : (iterclientAudit).second) {
            averagePriceTrn += (iterVector)->GetAveragePrice();
            if((iterVector)->GetOrderType() == "BUY") {
                netQuantity += (iterVector)->GetQuantity();
            } else {
                netQuantity -= (iterVector)->GetQuantity();
            }
        }

        cout << "Net Client Holdings for all Client " << iterclientAudit.first << " = "
             << ((averagePriceTrn * netQuantity) / (iterclientAudit.second.size())) << "\n";
    }
}

/**
 * @brief Core function allocates broker quotes to Client orders
 * steps:
 * 1.Check if quantity>100
 * Split the order with multiple brokers considering list of brokers can have more than two brokers
 * Splitting order in chunks of 100 (Max limit)
 * Allocating best price quote for intermediate chunks
 * Update the map containing brokers audit data
 * 2. if quantity<100
 * Allocating best broker price for order
 * Update the map containing brokers audit data
 * 3.Update Client Audit data
 * @param client
 * @param orderType
 * @param quantity
 * @return 
 */
int Strategy::AllocateOrderToBrokers(string client, string orderType, int quantity)
{
    quotePrice = 0;
    int tempQuantity = quantity;
    int maxSellingLimit = 100;
    shared_ptr<Order> clientOrder = make_shared<Order>();
    clientOrder->init(client, orderType, quantity);
    if(tempQuantity > 100) {
        while(tempQuantity > 0) {
            if(tempQuantity > 100)
                maxSellingLimit = 100;
            else
                maxSellingLimit = tempQuantity;
            UpdateQuotes(maxSellingLimit, clientOrder);
            auto itr = quoteSet.begin(); // Already sorted set , first element gives best price
            quotePrice += (*itr).GetQuotePrice();
            clientOrder->BrokerName.insert((*itr).GetBroker());
            auto itrBroker = brokerAudit.find((*itr).GetBroker());
            if(itrBroker != brokerAudit.end()) {
                itrBroker->second += maxSellingLimit;
            } else {
                brokerAudit.insert(std::pair<string, int>((*itr).GetBroker(), maxSellingLimit));
            }
            tempQuantity -= maxSellingLimit;
        }
    } else {
        UpdateQuotes(quantity, clientOrder);
        auto itr = quoteSet.begin();
        quotePrice = ((*itr).GetQuotePrice());
        clientOrder->BrokerName.insert((*itr).GetBroker());
        auto itrBroker = brokerAudit.find((*itr).GetBroker());
        if(itrBroker != brokerAudit.end()) {
            itrBroker->second += clientOrder->GetQuantity();
        } else {
            brokerAudit.insert(std::pair<string, int>((*itr).GetBroker(), clientOrder->GetQuantity()));
        }
    }
    clientOrder->SetOrderPrice(quotePrice);
    clientOrder->SetAveragePrice((clientOrder->GetOrderPrice()) /
                                 (clientOrder->GetQuantity())); // this will be used to get client net holdings
    auto itrclientAudit = clientAudit.find(clientOrder->GetClientName());
    if(itrclientAudit != clientAudit.end()) {
        (itrclientAudit->second).push_back(clientOrder);
    } else {
        vector<shared_ptr<Order> > vTemp;
        vTemp.push_back(clientOrder);
        clientAudit.insert(pair<string, vector<shared_ptr<Order> > >(clientOrder->GetClientName(), vTemp));
    }

    cout << endl << "Client " << clientOrder->GetClientName() << "  " << clientOrder->GetOrderType() << " "
         << clientOrder->GetQuantity() << " at " << clientOrder->GetOrderPrice() << "\n\n";

    return 0;
}

/**
 * @brief Prints list of brokers and quantities transacted by each broker
 */
void Strategy::PrintBrokersTokenTransacted()
{
    for(auto& iterbrokerAudit : brokerAudit) {
        cout << "Broker Name: " << iterbrokerAudit.first << "  quantity Transacted:  " << iterbrokerAudit.second
             << "\n";
    }
}

/**
 * @brief Updates the broker quotes for split of orders
 * @param quantity
 * @param clientOrder
 */
void Strategy::UpdateQuotes(int quantity, shared_ptr<Order> clientOrder)
{
    quoteSet.clear(); // for updated quantity, create new quotes
    for(auto& iter : brokerList) {
        if(clientOrder->BrokerName.find(iter->getName()) == clientOrder->BrokerName.end()) {
            Quote tempQuote(iter->CalculateQuote(quantity), iter->getName());
            quoteSet.insert(tempQuote);
        }
    }
}

/**
 * @brief Prints all Buy and sell transactions for a session
 */
void Strategy::ViewBuySellTrans()
{
    for(auto& iterclientAudit : clientAudit) {
        for(auto& iterVector : (iterclientAudit).second) {
            cout << endl << " Client: " << (iterVector)->GetClientName()
                 << " transaction type: " << (iterVector)->GetOrderType()
                 << " quantity: " << (iterVector)->GetQuantity() << endl;
        }
    }
}
