#ifndef PENCIL_INVENTORY_H
#define PENCIL_INVENTORY_H

#include "wallet.h"
#include "graphite_inventory.h"
#include "wood_inventory.h"
#include <cmath>
#include <iostream>
#include <algorithm>
#include <QtNetwork>


/**
 * @brief The Pencil_Inventory class
 * main class for managing pencil prices and production.
 */
class Pencil_Inventory
{
public:
    Pencil_Inventory();

    // getter methods
    float getPrice() const;
    int getAmount() const;
    float getPublicDemand() const;
    int getTotalNumberOfPencilsProduced() const;
    int getNumberOfPencilsToBeSold() const;
    int getIntelligence() const;
    float getM() const;
    float getMarketingPrice();
    // setter methods for debuging tool
    void setPencil(int n, int m);
    void setIntelligence(int n);
    void increasemarketing(int m);
    void increaseIntelligence(int n);
    // bool checking method for Intelligence
    bool checkIntelligence(int m);

    // setter functions
    void setPrice(float);
    void setAmount(float);
    void setTotalNumberOfPencilsProduced(float);
    void setM(float);
    void setMarketingPrice(float);

    // change price
    void increasePrice();
    void decreasePrice();
    bool canDecreasePrice() const;
    void changeIntelligence();

    // sell and produce pencils
    void sellPencil(Wallet&, int n = 1);
    bool canSellPencil(int n = 1) const;
    void producePencil(Graphite_Inventory&, Wood_Inventory&, float n = 1.00);
    bool canProducePencil(Graphite_Inventory&, Wood_Inventory&, float n = 1) const;

    // upgrade marketing
    void UpgradeMarketing(Wallet&);


private:
    /**
     * steps to increase/decrease the price of a pencil.
     * Default value set to $0.05
     */
    const float change = 0.05f;

    /**
     * @brief the price of a pencil
     */
    float price;
    /**
     * @brief the number of pencils in the inventory
     */
    int amount;

    /**
     * @brief the total number fo pencils produced
     */
    int totalNumberOfPencilsProduced;

    /**
     * @brief new value Intelligence
     */
    int Intelligence = 0;

    /**
     * @brief new value Marketing
     */
    float M =0;

    /**
     * @brief price of Marketing
     */
    float marketing_price = 500;
};

#endif // PENCIL_INVENTORY_H
