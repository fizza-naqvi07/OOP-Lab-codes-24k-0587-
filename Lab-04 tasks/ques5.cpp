#include <iostream>
#include <string>
using namespace std;

class MenuItem
{
public:
    string n;
    float p;
    string t;

    MenuItem() {}
    MenuItem(string name, float price, string type)
    {
        n = name;
        p = price;
        t = type;
    }
};

class CoffeeShop
{
private:
    string name;
    MenuItem m[10];
    string o[10];
    int qty[10];
    int oCnt = 0;
    int mCnt = 0;

public:
    CoffeeShop(string n)
    {
        name = n;
    }

    void addMItem(string item, float price, string type)
    {
        if (mCnt < 10)
        {
            m[mCnt++] = MenuItem(item, price, type);
        }
    }

    void addOrder(string item, int quantity)
    {
        bool found = false;
        for (int i = 0; i < mCnt; ++i)
        {
            if (m[i].n == item)
            {
                o[oCnt] = item;
                qty[oCnt] = quantity;
                oCnt++;
                found = true;
                break;
            }
        }
        if (!found)
        {
            cout << "This item is currently unavailable" << endl;
        }
    }

    string fulfillOrder()
    {
        if (oCnt == 0)
        {
            return "All orders have been fulfilled";
        }
        else
        {
            string item = o[0];
            int quantity = qty[0];
            for (int i = 0; i < oCnt - 1; ++i)
            {
                o[i] = o[i + 1];
                qty[i] = qty[i + 1];
            }
            oCnt--;
            return "Order no. " + to_string(oCnt + 1) + ": " + item + " (" + to_string(quantity) + " item(s)) is ready";
        }
    }

    float dueAmount()
    {
        float total = 0;
        for (int i = 0; i < oCnt; ++i)
        {
            for (int j = 0; j < mCnt; ++j)
            {
                if (m[j].n == o[i])
                {
                    total += m[j].p * qty[i];
                    break;
                }
            }
        }
        return total;
    }

    void listOrders()
    {
        if (oCnt == 0)
        {
            cout << "No orders placed" << endl;
        }
        else
        {
            for (int i = 0; i < oCnt; ++i)
            {
                cout << "Order no. " << i + 1 << ": " << o[i] << " (" << qty[i] << " item(s))" << endl;
            }
        }
    }

    string cheapestItem()
    {
        string cheapest = "";
        float minPrice = 9999.99;
        for (int i = 0; i < mCnt; ++i)
        {
            if (m[i].p < minPrice)
            {
                minPrice = m[i].p;
                cheapest = m[i].n;
            }
        }
        return cheapest;
    }

    void drinksOnly()
    {
        cout << "Drinks available: ";
        for (int i = 0; i < mCnt; ++i)
        {
            if (m[i].t == "drink")
            {
                cout << m[i].n << " ";
            }
        }
        cout << endl;
    }

    void foodOnly()
    {
        cout << "Food available: ";
        for (int i = 0; i < mCnt; ++i)
        {
            if (m[i].t == "food")
            {
                cout << m[i].n << " ";
            }
        }
        cout << endl;
    }
};

int main()
{
    CoffeeShop shop("Cafe Central");

    int n;
    cout << "Enter the number of menu items: ";
    cin >> n;
    cin.ignore();

    for (int i = 0; i < n; ++i)
    {
        string item, type;
        float price;
        cout << "Enter item name: ";
        getline(cin, item);
        cout << "Enter item price: ";
        cin >> price;
        cin.ignore();
        cout << "Enter item type (food/drink): ";
        getline(cin, type);
        shop.addMItem(item, price, type);
    }

    int orderCnt;
    cout << "Enter the number of orders: ";
    cin >> orderCnt;
    cin.ignore();

    for (int i = 0; i < orderCnt; ++i)
    {
        string order;
        int quantity;
        cout << "Enter order: ";
        getline(cin, order);
        cout << "Enter quantity: ";
        cin >> quantity;
        cin.ignore();
        shop.addOrder(order, quantity);
    }

    for (int i = 0; i < orderCnt; ++i)
    {
        cout << shop.fulfillOrder() << endl;
    }

    cout << "Total due: " << shop.dueAmount() << endl;
    cout << "Cheapest item: " << shop.cheapestItem() << endl;

    shop.drinksOnly();
    shop.foodOnly();

    return 0;
}
