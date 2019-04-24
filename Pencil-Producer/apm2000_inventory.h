#ifndef APM2000_INVENTORY_H
#define APM2000_INVENTORY_H

#include "wallet.h"
#include "pencil_inventory.h"
#include "graphite_inventory.h"
#include "wood_inventory.h"
/**
 * @brief The APM2000_Inventory class
 * Automatic Pencil Machine(APM)\n
 * Suffix "2000" indicates 2000-series. Every 2000-series produces 2 pencils per
 * second, which are automatically added into the inventory. APM stops automatically
 * when there are insufficient materials and resumes when materials are available.
 * The upgrade version of APM2000 produce 10% faster than original APM2000. It can
 * be unlocked with 50 Intelligences and upgraded second time with 200 Intelligences
 * when the number of pencils manufactured reaches 5000.
 */
class APM2000_Inventory
{
public:
    APM2000_Inventory();
    void buyAPM2000(Wallet&);
    bool canBuyAPM2000(Wallet&);
    void producePencil(Pencil_Inventory&, Graphite_Inventory&, Wood_Inventory&);
    bool canProducePencil(Pencil_Inventory&, Graphite_Inventory&, Wood_Inventory&);
    int getNumber() const;
    float getPrice() const;
    float getRate() const;
    float getAPMRate() const;
    float getIntelligencePrice() const;
    float getVersion() const;
    void FirstUpgradeAPM(Pencil_Inventory&);
    bool FirstCanUpgradeAPM(Pencil_Inventory&);
    void SecondUpgradeAPM(Pencil_Inventory&);
    bool SecondCanUpgradeAPM(Pencil_Inventory&);

    void setNumber(float newnumber);
    void setPrice(float newprice);
    void setAPMRate(float);
    void setIntelligencePrice(float);
    void setVersion(float);

private:
    /// maximum number of APMs allowed
    int max = 10;
    /// number of APMs in your inventory
    int number;
    float apmrate = 1.00;
    /// price of APM
    float price;
    /// price of intelligence
    int intelligence_price;
    ///version of Upgrade
    int version;
};

#endif // APM2000_INVENTORY_H
