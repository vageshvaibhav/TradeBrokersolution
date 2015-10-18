#include "Broker.h"

/**
 * @brief Initializes concrete broker
 * @param name
 */
void Broker1::Init(string name)
{
    setName(name);
    setCommission(1.05);     // Fixed commission = 5% (1 + 1*(5%))= 1.05
    setConversionRate(1.49); // Fixed conversion rate 1.49
}

/**
 * @brief Calculate broker quote for quantity of order
 * @param quantity
 * @return quote after calculation
 */
double Broker1::CalculateQuote(int quantity)
{
    return (quantity * getConversionRate() * getCommission());
}

/**
 * @brief Init for concrete broker
 * @param name
 */
void Broker2::Init(string name)
{
    setName(name);
    setConversionRate(1.52); // Fixed conversion rate 1.52

}

/**
 * @brief Calculate broker quote for quantity of order
 * @param quantity
 * @return quote after calculation using variable commission
 */
double Broker2::CalculateQuote(int quantity) // Calculating variable commission
{
    if(quantity >= 10 && quantity <= 40) {
        setCommission(1.03);
    }
    if(quantity >= 50 && quantity <= 80) {
        setCommission(1.025);
    }
    if(quantity >= 90 && quantity <= 100) {
        setCommission(1.02);
    }
    return (quantity * getConversionRate() * getCommission());
}