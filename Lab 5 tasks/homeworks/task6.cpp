#include <iostream>
#include <string>

using namespace std;

class CoffeeShop {
public:
    string name;
    string menu[5] = {"coffee", "tea", "sandwich", "cake", "juice"};
    double prices[5] = {250 , 60, 300, 600, 80};
    string orders[5];
    int orderCount = 0;

    void addOrder(string item) {
        bool available = false;
        for (int i = 0; i < 5; ++i) {
            if (menu[i] == item) {
                orders[orderCount] = item;
                orderCount++;
                available = true;
                break;
            }
        }
        if (!available) {
            cout << "This item is currently unavailable!" << endl;
        }
    }

    void fulfillOrder() {
        if (orderCount > 0) {
            cout << "The " << orders[0] << " is ready!" << endl;
            for (int i = 0; i < orderCount - 1; ++i) {
                orders[i] = orders[i + 1];
            }
            orderCount--;
        } else {
            cout << "All orders have been fulfilled" << endl;
        }
    }

    void listOrders() {
        if (orderCount == 0) {
            cout << "No orders have been taken." << endl;
        } else {
            cout << "Orders taken: ";
            for (int i = 0; i < orderCount; ++i) {
                cout << orders[i] << " ";
            }
            cout << endl;
        }
    }

    double dueAmount() {
        double total = 0;
        for (int i = 0; i < orderCount; ++i) {
            for (int j = 0; j < 5; ++j) {
                if (orders[i] == menu[j]) {
                    total += prices[j];
                }
            }
        }
        return total;
    }

    string cheapestItem() {
        double minPrice = prices[0];
        string item = menu[0];
        for (int i = 1; i < 5; ++i) {
            if (prices[i] < minPrice) {
                minPrice = prices[i];
                item = menu[i];
            }
        }
        return item;
    }

    void drinksOnly() {
        cout << "Drinks: ";
        for (int i = 0; i < 5; ++i) {
            if (menu[i] == "coffee" || menu[i] == "tea" || menu[i] == "juice") {
                cout << menu[i] << " ";
            }
        }
        cout << endl;
    }

    void foodOnly() {
        cout << "Food: ";
        for (int i = 0; i < 5; ++i) {
            if (menu[i] == "sandwich" || menu[i] == "cake") {
                cout << menu[i] << " ";
            }
        }
        cout << endl;
    }

    void showMenu() {
        cout << "\nMenu:\n";
        for (int i = 0; i < 5; ++i) {
            cout << menu[i] << " - Rs." << prices[i] << endl;
        }
    }
};

int main() {
    CoffeeShop shop;
    string item;
    int choice;

    while (true) {
        cout << "\nCoffee Shop System:\n";
        cout << "1. Add Order\n";
        cout << "2. Fulfill Order\n";
        cout << "3. List Orders\n";
        cout << "4. Total Amount Due\n";
        cout << "5. Cheapest Item\n";
        cout << "6. Drinks Only\n";
        cout << "7. Food Only\n";
        cout << "8. Show Menu\n";
        cout << "9. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore();

        switch (choice) {
            case 1:
                cout << "Enter item to add to order: ";
                getline(cin, item);
                shop.addOrder(item);
                break;
            case 2:
                shop.fulfillOrder();
                break;
            case 3:
                shop.listOrders();
                break;
            case 4:
                cout << "Total amount due: " << shop.dueAmount() << endl;
                break;
            case 5:
                cout << "Cheapest item: " << shop.cheapestItem() << endl;
                break;
            case 6:
                shop.drinksOnly();
                break;
            case 7:
                shop.foodOnly();
                break;
            case 8:
                shop.showMenu();
                break;
            case 9:
                cout << "Exiting Coffee Shop..." << endl;
                return 0;
            default:
                cout << "Invalid choice! Please try again." << endl;
                break;
        }
    }
}
