#include <iostream>
#include <string>

using namespace std;

class Book {
protected:
    string genre;
public:
    Book(string g) : genre(g) {}
    virtual void display() = 0;
    virtual ~Book() {}
};

class Novel : public Book {
private:
    string title, author;
public:
    Novel(string t, string a) : Book("Novel"), title(t), author(a) {}
    void display() override {
        cout << "Genre: " << genre << "\nTitle: " << title << "\nAuthor: " << author << "\n";
    }
};

class Mystery : public Book {
private:
    string title, author;
public:
    Mystery(string t, string a) : Book("Mystery"), title(t), author(a) {}
    void display() override {
        cout << "Genre: " << genre << "\nTitle: " << title << "\nAuthor: " << author << "\n";
    }
};

int main() {
    Book* books[] = { new Novel("Pride and Prejudice", "Jane Austen"), new Mystery("Sherlock Holmes", "Arthur Conan Doyle") };
    
    for (int i = 0; i < 2; i++) {
        books[i]->display();
        cout << "----------------\n";
    }
    
    for (int i = 0; i < 2; i++) delete books[i];
    
    return 0;
}
