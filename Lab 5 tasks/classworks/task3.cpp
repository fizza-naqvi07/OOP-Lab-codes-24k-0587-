#include <iostream>
#include <string>

using namespace std;

class Book {
private:
    string title;
    string isbn;

public:
    Book(string t, string i) : title(t), isbn(i) {}

    string getTitle() {
        return title;
    }

    string getISBN() {
        return isbn;
    }
};

class Catalog {
private:
    Book* bks[10];
    int cnt;

public:
    Catalog() : cnt(0) {}

    void addBook(Book* b) {
        if (cnt < 10) {
            bks[cnt++] = b;
        }
    }

    Book* findByISBN(const string& i) {
        for (int j = 0; j < cnt; j++) {
            if (bks[j]->getISBN() == i) {
                return bks[j];
            }
        }
        return nullptr;
    }
};

class Library {
private:
    string name;
    string addr;
    Catalog cat;
    Book* bks[10];
    int cnt;

public:
    Library(string n, string a) : name(n), addr(a), cnt(0) {}

    void addBook(Book* b) {
        if (cnt < 10) {
            bks[cnt++] = b;
            cat.addBook(b);
        }
    }

    void removeBook(const string& i) {
        for (int j = 0; j < cnt; j++) {
            if (bks[j]->getISBN() == i) {
                for (int k = j; k < cnt - 1; k++) {
                    bks[k] = bks[k + 1];
                }
                cnt--;
                break;
            }
        }
    }

    Book* findInCatalog(const string& i) {
        return cat.findByISBN(i);
    }

    void listBooks() {
        for (int j = 0; j < cnt; j++) {
            cout << "Book: " << bks[j]->getTitle() << " \nISBN: " << bks[j]->getISBN() << endl;
        }
    }
};

int main() {
    string n, a, t, i;
    Library lib("City Library", "123 Main St");

    for (int j = 0; j < 2; j++) {
        cout << "Enter book title: ";
        getline(cin, t);
        cout << "Enter book ISBN: ";
        getline(cin, i);

        Book* b = new Book(t, i);
        lib.addBook(b);
    }

    cout << "\nLibrary books list:" << endl;
    lib.listBooks();

    cout << "\nEnter ISBN to search: ";
    getline(cin, i);
    Book* b = lib.findInCatalog(i);
    if (b) {
        cout << "Found Book: " << b->getTitle() << ", ISBN: " << b->getISBN() << endl;
    } else {
        cout << "Book not found in catalog." << endl;
    }

    return 0;
}
