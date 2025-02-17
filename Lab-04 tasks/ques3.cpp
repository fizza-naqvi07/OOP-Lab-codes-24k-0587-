
#include <iostream>
#include <string>
using namespace std;

class Invoice
{
public:
    Invoice(string p_no, string p_desc, int qty, double p_price) : part_no(p_no), part_desc(p_desc), quantity(qty > 0 ? qty : 0), price(qty > 0 && p_price > 0 ? p_price : 0.0) {}

    double getInvoiceAmt()
    {
        return quantity * price;
    }

    void printInvoice()
    {
        cout << "\nInvoice" << endl;
        cout << "Item Number: " << part_no << endl;
        cout << "Item Description: " << part_desc << endl;
        cout << "Quantity: " << quantity << endl;
        cout << "Price per Item: Rs. " << price << endl;
        cout << "Invoice Amount: Rs. " << getInvoiceAmt() << endl;
    }

private:
    string part_no, part_desc;
    int quantity;
    double price;
};

int main()
{
    string p_no, p_desc;
    int qty;
    double price;

    cout << "Enter Item Number: ";
    cin >> p_no;
    cout << "Enter Item Description: ";
    cin >> p_desc;
    cout << "Enter Quantity: ";
    cin >> qty;
    cout << "Enter price per Item: ";
    cin >> price;

    Invoice inv(p_no, p_desc, qty, price);

    inv.printInvoice();

    return 0;
}
