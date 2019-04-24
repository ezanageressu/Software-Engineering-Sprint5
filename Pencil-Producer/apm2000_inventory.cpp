#include "apm2000_inventory.h"

/**
 * @brief APM2000_Inventory::APM2000_Inventory
 * APM2000_Inventory constructor.\n
 * Default values:\n
 * number = 0\n
 * price = $150.00
 */
APM2000_Inventory::APM2000_Inventory()
{
    number = 0;
    price = 150.0f;
}

/**
 * @brief APM2000_Inventory::buyAPM2000
 * If canBuyAPM2000 evaluates to true, bank balance is debited, the number
 * of APMs in inventory increases by 1 and the APM price is updated.
 * @param wallet
 */
void APM2000_Inventory::buyAPM2000(Wallet& wallet)
{
    if (canBuyAPM2000(wallet))
    {
        wallet.debitMoney(price);
        number++;
        price *= 1.1f;
    }
}

/**
 * @brief APM2000_Inventory::canBuyAPM2000
 * checks if wallet balance has enough for new APM and if the number of APMs in
 * inventory is less than the max (10).
 * @param wallet
 * @return true conditions are met, false otherwise
 */
bool APM2000_Inventory::canBuyAPM2000(Wallet& wallet)
{
    return (number < 10 && wallet.canDebitMoney(price));
}
/**
 * @brief APM2000_Inventory::producePencil
 * It there are enough materials to make pencils, then create 2 pencils per second, or 2 * rate pencils per second.
 * @param pencilInventory, graphiteInventory, woodInventory
 */
void APM2000_Inventory::producePencil(Pencil_Inventory& pencilInventory,
                                      Graphite_Inventory& graphiteInventory,
                                      Wood_Inventory& woodInventory)
{
    if (canProducePencil(pencilInventory, graphiteInventory, woodInventory)){
        pencilInventory.producePencil(graphiteInventory, woodInventory, (2 * apmrate * number));
    }
}

/**
 * @brief APM2000_Inventory::canProducePencil
 * Check the validility to produce pencil. If not return false
 * @param pencilInventory, graphiteInventory, woodInventory
 * @return bool
 */
bool APM2000_Inventory::canProducePencil(Pencil_Inventory& pencilInventory,
                                         Graphite_Inventory& graphiteInventory,
                                         Wood_Inventory& woodInventory)
{
    return pencilInventory.canProducePencil(graphiteInventory, woodInventory, (2 * apmrate * number));
}

/// returns number of APMs in inventory
int APM2000_Inventory::getNumber() const
{
    return number;
}

/// returns price of APM
float APM2000_Inventory::getPrice() const
{
    return price;
}

/// return apmrate
float APM2000_Inventory::getRate() const
{
    return number * 120 * apmrate;
}

//return actual apmrate
float APM2000_Inventory::getAPMRate() const
{
  return apmrate;
}

/// return price of intelligence
float APM2000_Inventory::getIntelligencePrice() const
{
    return intelligence_price;
}

float APM2000_Inventory::getVersion() const{
  return version;
}

///Setter functions
void APM2000_Inventory::setNumber(float newnumber){
    number = newnumber;
}
void APM2000_Inventory::setPrice(float newprice){
    price = newprice;
}
void APM2000_Inventory::setIntelligencePrice(float newIntelligencePrice){
    intelligence_price = newIntelligencePrice;
}
void APM2000_Inventory::setAPMRate(float newrate){
    apmrate = newrate;
}
void APM2000_Inventory::setVersion(float newversion){
    version = newversion;
}



/**
 * @brief APM2000_Inventory::FirstCanUpgradeAPM
 * Check the validility to upgrade APM for the first time. checking for Intelligence and Total pencil. If not return false.
 * @param pencilInventory
 * @return bool
 */
bool APM2000_Inventory::FirstCanUpgradeAPM(Pencil_Inventory& pencil)
{
    return (pencil.checkIntelligence(50) && pencil.getTotalNumberOfPencilsProduced() >=3000);
}

/**
 * @brief APM2000_Inventory::SecondCanUpgradeAPM
 * Check the validility to upgrade APM for the second time. checking for Intelligence and Total pencil. If not return false.
 * @param pencilInventory
 * @return bool
 */
bool APM2000_Inventory::SecondCanUpgradeAPM(Pencil_Inventory& pencil)
{
    return (pencil.getTotalNumberOfPencilsProduced() == 5000);
}

/**
 * @brief APM2000_Inventory::FirstUpgradeAPM
 * if possible to upgrade, Upgrade APM to produce pencil rate by 10% and max by 1 and set version Apm2000 as 1.
 * @param pencilInventory
 */
void APM2000_Inventory::FirstUpgradeAPM(Pencil_Inventory& pencil){
    int balance;
    if(FirstCanUpgradeAPM(pencil)&& version == 0){
        max++;
        apmrate *= 1.1f;
        intelligence_price = 50;
        balance = pencil.getIntelligence();
        balance -= intelligence_price;
        pencil.setIntelligence(balance);
        version = 1;
    }
}

/**
 * @brief APM2000_Inventory::SecondUpgradeAPM
 * if possible to upgrade, Upgrade APM to produce pencil rate by 10% again and max by 1 again and set version Apm2000 as 2.
 * @param pencilInventory
 */
void APM2000_Inventory::SecondUpgradeAPM(Pencil_Inventory & pencil){
    int  balance;
    if(SecondCanUpgradeAPM(pencil)&&version == 1){
        max++;
        apmrate *= 1.1;
        intelligence_price = 200;
        balance = pencil.getIntelligence();
        balance -= intelligence_price;
        pencil.setIntelligence(balance);
        version =2;
    }
}
