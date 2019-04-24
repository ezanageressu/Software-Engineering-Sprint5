#ifndef MATERIAL_INVENTORY_H
#define MATERIAL_INVENTORY_H

#include "wallet.h"
#include <cstdlib>
#include <ctime>
using namespace std;

/**
 * @brief The Material_Inventory class
 * superclass of other material classes.
 */
class Material_Inventory
{
public:
    Material_Inventory(float, float);
    void buy(Wallet&);
    bool canBuy(Wallet&) const;
    float getPrice() const;
    void setPrice();
    float getAmount() const;
    void consume(float n = 1.00);
    bool canConsume(float n = 1.00) const;
    void setMaterial(int n);

    void setAmount(float);
private:
    /// price of 100.00m of material
    float price;
    /// amount of material in inventory
    float amount;
    /// the minimum price of the material
    float minPrice;
    float change;
    ///setter for debuging tool


};

#endif // MATERIAL_INVENTORY_H
