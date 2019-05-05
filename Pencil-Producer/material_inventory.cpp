#include "material_inventory.h"

/**
 * @brief constructor of Material_Inventory Class
 * @param minPrice represents the minimum price of wood or graphite
 * @param change is 0.20m for graphite and 0.21m for wood per pencil
 */
Material_Inventory::Material_Inventory(float minPrice, float change)
{
    srand(time(0));
    this->minPrice = minPrice;
    this->change = change;
    setPrice();
    amount = 1000.0f;
}

/**
 * @brief Material_Inventory::buy
 * if there are sufficient funds in bank balance, increase the amount of material
 * in inventory by 100.00m and debit bank balance.
 * @param wallet
 */
void Material_Inventory::buy(Wallet& wallet)
{
    if (canBuy(wallet))
    {
        amount += 100.0f;
        wallet.debitMoney(price);
    }
}

/**
 * @brief function to check whether we can buy wood or graphite
 * @param wallet class
 * @return returns true if the bank balance is greater or equal to the price of the material,
 * false otherwise
 */
bool Material_Inventory::canBuy(Wallet& wallet) const
{
    float bankBalance = wallet.getBankBalance();
    return (bankBalance >= price);
}

/**
 * @brief method to get price of wood or graphite
 * @return returns price of wood or graphite
 */
float Material_Inventory::getPrice() const
{
    return price;
}

/**
 * @brief randomly increases the price of the material within a certain value range
 */
void Material_Inventory::setPrice()
{
    price = minPrice + rand() % 1001;
}

/**
 * @brief function to get amount of wood or graphite
 * @return returns the amount of the material in inventory
 */
float Material_Inventory::getAmount() const
{
    return amount;
}

/**
 * @brief Setter function for amount of material
 * @param sets amount of material to newamount
 */
void Material_Inventory::setAmount(float newamount){
  this->amount = newamount;
}


/**
 * @brief Material_Inventory::consume
 * if there is sufficient material, reduces the amount of material in inventory
 * by the appropriate amount.
 * @param reduces amount by change * n
 */
void Material_Inventory::consume(float n)
{
    if (canConsume(n))
    {
        amount -= change * n;
    }
}

/**
 * @brief function to check whether there is enough materials to make pencil
 * @param checks if amount is greater than change * n
 * @return returns true if there is enough materials, otherwise false
 */
bool Material_Inventory::canConsume(float n) const
{
    return (amount >= change * n);
}

/**
 * @brief function to increase amount of graphite or wood in the inventory
 * @param increases amount by n
 */
void Material_Inventory::setMaterial(int n)
{
    amount += n;
}
