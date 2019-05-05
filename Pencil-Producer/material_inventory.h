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
    /**
     * @brief price of 100.00m of material
     */
    float price;
    /**
     * @brief amount of material in inventory
     */
    float amount;
    /**
     * @brief the minimum price of the material
     */
    float minPrice;

    /**
     * @brief change represents the amount of wood or graphite that should be
     * deducted from the inventory when a pencil is made
     */
    float change;


};

#endif // MATERIAL_INVENTORY_H
