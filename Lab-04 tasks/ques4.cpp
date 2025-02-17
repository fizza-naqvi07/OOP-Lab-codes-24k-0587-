#include <iostream>
#include <string>
using namespace std;

class Book
{
private:
    string auth;
    string tit;
    float prc;
    string pub;
    int stk;

public:
    Book(string a, string t, float p, string pbl, int s)
    {
        auth = a;
        tit = t;
        prc = p;
        pub = pbl;
        stk = s;
    }

    void showDetails()
    {
        cout << "Title: " << tit << endl;
        cout << "Author: " << auth << endl;
        cout << "Price: " << prc << endl;
        cout << "Publisher: " << pub << endl;
        cout << "Stock: " << stk << endl;
    }

    bool searchBook(string t, string a)
    {
        if (tit == t && auth == a)
        {
            return true;
        }
        return false;
    }

    bool checkStock(int req)
    {
        if (stk >= req)
        {
            return true;
        }
        return false;
    }

    void reduceStock(int sold)
    {
        stk -= sold;
    }

    float calcTotalCost(int req)
    {
        return prc * req;
    }
};

int main()
{
    string tit, auth;
    int req;

    Book books[] = {
        Book("J.K. Rowling", "Harry Potter", 500, "Bloomsbury", 10),
        Book("George Orwell", "1984", 400, "Secker & Warburg", 5),
        Book("J.R.R. Tolkien", "The Hobbit", 350, "HarperCollins", 15),
        Book("F. Scott Fitzgerald", "The Great Gatsby", 375, "Scribner", 3),
        Book("Markus Zusak", "The Book Thief", 499, "Knopf", 11)};

    cout << "Enter Book title: ";
    getline(cin, tit);
    cout << "Enter Author name: ";
    getline(cin, auth);

    bool found = false;
    for (int i = 0; i < 5; ++i)
    {
        if (books[i].searchBook(tit, auth))
        {
            books[i].showDetails();
            cout << "Enter the number of copies required: ";
            cin >> req;
            if (books[i].checkStock(req))
            {
                cout << "Total cost: " << books[i].calcTotalCost(req) << endl;
                books[i].reduceStock(req);
            }
            else
            {
                cout << "Required copies not in stock!" << endl;
            }
            found = true;
            break;
        }
    }

    if (!found)
    {
        cout << "Book not available!" << endl;
    }

    return 0;
}
