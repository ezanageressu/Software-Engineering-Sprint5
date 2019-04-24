#include "pencil_inventory.h"

/**
 * @brief Pencil_Inventory::Pencil_Inventory
 * constructor for Pencil_Inventory class.
 * @note starts with default values:\n
 *  price = $1.00\n
 *  number of pencils = 0\n
 *  number of pencils produced = 0\n
 */
Pencil_Inventory::Pencil_Inventory()
{
    price = 1.0f;
    amount = 0;
    totalNumberOfPencilsProduced = 0;
}

/// returns the price of a pencil
float Pencil_Inventory::getPrice() const
{
    return price;
}

/// returns the number of pencils in inventory
int Pencil_Inventory::getAmount() const
{
    return amount;
}

/// returns the public demand of pencils
float Pencil_Inventory::getPublicDemand() const
{
    return (round(100 * std::pow(1.1f,M)/ price)) / 100.0f;
}

/// returns the total number of pencils produced
int Pencil_Inventory::getTotalNumberOfPencilsProduced() const
{
    return totalNumberOfPencilsProduced;
}

int Pencil_Inventory::getNumberOfPencilsToBeSold() const
{
    return std::min(static_cast<int>(floor(5 * getPublicDemand())), amount);
}

int Pencil_Inventory::getIntelligence() const
{
    return Intelligence;
}

///Setter functions

void Pencil_Inventory::setPrice(float newprice){
  price = newprice;
}

void Pencil_Inventory::setAmount(float newamount){
  amount = newamount;
}

void Pencil_Inventory::setTotalNumberOfPencilsProduced(float newtotal){
  totalNumberOfPencilsProduced = newtotal;
}


void Pencil_Inventory::setM(float newM){
  M = newM;
}

void Pencil_Inventory::setMarketingPrice(float newmarketingprice){
  marketing_price = newmarketingprice;
}

/**
 * @brief Pencil_Inventory::increasePrice
 * increase the price of pencils.
 */
void Pencil_Inventory::increasePrice()
{
    price += change;
}

/**
 * @brief Pencil_Inventory::decreasePrice
 * decrease the price of pencils.
 */
void Pencil_Inventory::decreasePrice()
{
    if (canDecreasePrice())
    {
        price -= change;
    }
}

/**
 * @brief Pencil_Inventory::canDecreasePrice
 * checks if the price can be decreased without resulting in a negative price.
 * @return true if new price is positive, false otherwise.
 */
bool Pencil_Inventory::canDecreasePrice() const
{
    return (static_cast<int>(price * 100) / 100.0f > change);
}

/**
 * @brief Pencil_Inventory::sellPencil
 * the function checks if there are pencils to sell and then
 * decrements the number of pencils in the inventory by n.
 * Wallet is then credited by the price of n pencils
 * @param w wallet
 * @param n the number of pencils to sell. Default value is 1.
 */
void Pencil_Inventory::sellPencil(Wallet& w, int n)
{
    if (canSellPencil(n))
    {
        amount -= n;
        w.creditMoney(price * n);
    }
}

/// returns true if there are pencils to sell, false otherwise
bool Pencil_Inventory::canSellPencil(int n) const
{
    return (amount >= n);
}

/**
 * @brief Pencil_Inventory::producePencil
 * checks if there is enough material to produce n pencils. If true
 * consumes graphite and wood for n pencils and increments the number
 * of pencils in the inventory and totalNumberOfPencilsProduced by n.
 * @param graphiteInventory the amount of graphite in the inverntory
 * @param woodInventory the amount of wood in the inventory
 * @param n the number of pencils to produce
 */
void Pencil_Inventory::producePencil(Graphite_Inventory& graphiteInventory, Wood_Inventory& woodInventory, float n)
{
    if (canProducePencil(graphiteInventory, woodInventory, n))
    {
        graphiteInventory.consume(n);
        woodInventory.consume(n);
        amount += n;
        totalNumberOfPencilsProduced += n;
    }
}

/// returns true if there is enough material to produce n pencils, false otherwise
bool Pencil_Inventory::canProducePencil(Graphite_Inventory& graphiteInventory, Wood_Inventory& woodInventory, float n) const
{
    return (graphiteInventory.canConsume(n) && woodInventory.canConsume(n));
}

///setter for pencil
void Pencil_Inventory::setPencil(int n,int m)
{
    totalNumberOfPencilsProduced += n;
    amount = amount + m;
}

/// increase Intelligence by one
void Pencil_Inventory::changeIntelligence()
{
    if(totalNumberOfPencilsProduced>=3000 && Intelligence <200)
        Intelligence += 1;
}

/// check if user have enough Intelligence
bool Pencil_Inventory::checkIntelligence(int m)
{
    if(Intelligence > m){
        return true;
    }
    else{
        return false;
    }

}

/// setter for Intelligence
void Pencil_Inventory::setIntelligence(int n){
    if(n > 200){
        Intelligence = 200;
    }
    else{
        Intelligence = n;
    }

}


/// getter for Marketing
float Pencil_Inventory::getM() const{
    return M;
}

/// getter for Marketing price
float Pencil_Inventory::getMarketingPrice()
{
    return marketing_price;
}

/**
 * @brief Pencil_Inventory::UpgradeMarketing
 * check if user have enough money to buy marketing
 * if true then debit money and increment marketing by one
 * and increase marketing price by 10%
 * @param wallet
 */
void Pencil_Inventory::UpgradeMarketing(Wallet& wallet){
    if(wallet.canDebitMoney(marketing_price)){
        wallet.debitMoney(marketing_price);
        M++;
        marketing_price *= 1.1;
    }
}
