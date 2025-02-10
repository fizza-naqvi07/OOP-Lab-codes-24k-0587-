#ifndef BOOK_H
#define BOOK_H

#include <string>
using namespace std;

class Book
{
private:
    string name;
    string isbn;
    string aut;
    string pub;

public:
    Book(string bName, string isbn, string aut, string pub)
    {
        this->name = bName;
        this->isbn = isbn;
        this->aut = aut;
        this->pub = pub;
    }

    string getName()
    {
        return name;
    }

    string getIsbn()
    {
        return isbn;
    }

    string getAuthor()
    {
        return aut;
    }

    string getPublisher()
    {
        return pub;
    }

    string getBookInfo()
    {
        return "Book Name: " + name + "\nISBN Number: " + isbn + "\nAuthor Name: " + aut + "\nPublisher Name: " + pub;
    }

    void setName(string bName)
    {
        name = bName;
    }

    void setIsbn(string isbn)
    {
        this->isbn = isbn;
    }

    void setAuthor(string aut)
    {
        this->aut = aut;
    }

    void setPublisher(string pub)
    {
        this->pub = pub;
    }
};

#endif
