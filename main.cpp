#include "UserInterface.h"
#include "Broker.h"
#include <memory>
/**
 * @brief Entry Point for console app
 * @param argc
 * @param argv
 * Takes input from console
 * @return 
 ***/
int main(int argc, char** argv)
{
    shared_ptr<Strategy> Strategystr = make_shared<Strategy>();
    shared_ptr<AbstractBroker> broker1 = make_shared<Broker1>();
    shared_ptr<AbstractBroker> broker2 = make_shared<Broker2>();
    broker1->Init("Broker1");
    broker2->Init("Broker2");
    Strategystr->AddBroker(broker1);
    Strategystr->AddBroker(broker2);
    shared_ptr<AbstractUserInterface> consoleUI = make_shared<ConsoleUserInterface>();
    consoleUI->Init(Strategystr);
    consoleUI->ShowUserOptions();
    return 0;
}
