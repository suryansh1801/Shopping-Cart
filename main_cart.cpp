#include <bits/stdc++.h>
#include "data.h"
using namespace std;

vector<Product> allProducts = {
    Product(1, "onions", 25),
    Product(3, "potato", 20),
    Product(2, "carrot", 30),
    Product(5, "radish", 40),
    Product(4, "tomato", 35),
    Product(6, "brocoli", 45),
};

Product *chooseProduct()
{

    // Display the list of products
    string productList;
    cout << "Available Products "
         << "\n";

    for (auto product : allProducts)
        productList.append(product.getDisplayName());

    cout << productList << "\n";
    cout << "----------------"
         << "\n";
    string choice;
    cin >> choice;

    for (int i = 0; i < allProducts.size(); i++)
        if (allProducts[i].getShortName() == choice)
            return &allProducts[i];

    cout << "Product not found!"
         << "\n";
    return NULL;
}

bool checkout(Cart &cart)
{
    if (cart.isEmpty())
        return false;

    int total = cart.getTotal();
    cout << "Pay in Cash";

    int paid;
    cin >> paid;

    if (paid >= total)
    {
        cout << "Change " << paid - total << "\n";
        cout << "Thank you for shopping!";
        return true;
    }

    else
    {
        cout << "Not enough cash!";
        return false;
    }
}

int main()
{
    char action;
    Cart cart;
    while (true)
    {
        cout << "To perform an action, select the first character of the given options, the one given in brackets."
             << "\n";
        cout << "Select an action -  (a)dd item, (v)iew cart, (c)heckout"
             << "\n";
        cin >> action;

        if (action == 'a')
        {
            // Todo: Add to Cart
            //  View All Products + Choose Product + Add to the Cart
            Product *product = chooseProduct();
            if (product != NULL)
            {
                cout << "Added to the Cart " << product->getDisplayName() << "\n";
                cart.addProduct(*product);
            }
        }
        else if (action == 'v')
        {
            // View the Cart
            cout << "------------------"
                 << "\n";
            cout << cart.viewCart();
            cout << "------------------"
                 << "\n";
        }
        else
        {
            // Checkout
            cart.viewCart();
            if (checkout(cart))
                break;
        }
    }
    return 0;
}