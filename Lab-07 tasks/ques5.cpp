#include <iostream>
#include <string>
using namespace std;

class Media
{
protected:
    string title, publicationDate, uniqueID, publisher;
    bool isCheckedOut;

public:
    Media(string t, string pubDate, string id, string pub) : title(t), publicationDate(pubDate), uniqueID(id), publisher(pub), isCheckedOut(false) {}

    virtual void displayInfo()
    {
        cout << "Title: " << title << "\nPublication Date: " << publicationDate << "\nUnique ID: " << uniqueID << "\nPublisher: " << publisher << "\nStatus: " << (isCheckedOut ? "Checked Out" : "Available") << endl;
    }

    void checkOut()
    {
        if (!isCheckedOut)
        {
            isCheckedOut = true;
            cout << title << " has been checked out." << endl;
        }
        else
        {
            cout << title << " is already checked out." << endl;
        }
    }

    void returnItem()
    {
        if (isCheckedOut)
        {
            isCheckedOut = false;
            cout << title << " has been returned." << endl;
        }
        else
        {
            cout << title << " was not checked out." << endl;
        }
    }

    bool search(string searchTitle) { return title == searchTitle; }
    bool searchByYear(string year) { return publicationDate == year; }
};

class Book : public Media
{
    string author, ISBN;
    int numberOfPages;

public:
    Book(string t, string pubDate, string id, string pub, string auth, string isbn, int pages)
        : Media(t, pubDate, id, pub), author(auth), ISBN(isbn), numberOfPages(pages) {}

    void displayInfo() override
    {
        Media::displayInfo();
        cout << "Author: " << author << "\nISBN: " << ISBN << "\nPages: " << numberOfPages << "\n--------------------------" << endl;
    }
};

class DVD : public Media
{
    string director, rating;
    double duration;

public:
    DVD(string t, string pubDate, string id, string pub, string dir, double dur, string rate)
        : Media(t, pubDate, id, pub), director(dir), duration(dur), rating(rate) {}

    void displayInfo() override
    {
        Media::displayInfo();
        cout << "Director: " << director << "\nDuration: " << duration << " minutes\nRating: " << rating << "\n--------------------------" << endl;
    }
};

class CD : public Media
{
    string artist, genre;
    int numberOfTracks;

public:
    CD(string t, string pubDate, string id, string pub, string art, int tracks, string gen)
        : Media(t, pubDate, id, pub), artist(art), numberOfTracks(tracks), genre(gen) {}

    void displayInfo() override
    {
        Media::displayInfo();
        cout << "Artist: " << artist << "\nTracks: " << numberOfTracks << "\nGenre: " << genre << "\n--------------------------" << endl;
    }
};

int main()
{
    Book b("The Art of Computer Programming", "1968", "B1024", "Addison Wesley", "Donald knuth", "978-0743273565", 672);
    DVD d("Inception", "2010", "D001", "Warner Bros", "Christopher Nolan", 148, "PG-13");
    CD c("Thriller", "1982", "C001", "Epic Records", "Michael Jackson", 9, "Pop");

    b.displayInfo();
    b.checkOut();
    b.returnItem();

    d.displayInfo();
    d.checkOut();
    d.returnItem();

    c.displayInfo();
    c.checkOut();
    c.returnItem();

    return 0;
}