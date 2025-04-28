#include <iostream>
#include <string>
#include <fstream>
using namespace std;

class Encryptor
{
private:
    string text;
    string e_text;
    string d_text;

public:
    void input()
    {
        cout << "Enter a string:" << endl;
        getline(cin, text);
    }

    void encrypt()
    {
        e_text = "";
        for (int i = 0; i < text.length(); ++i) {
            char c = text[i];
            c += (i+1);
            e_text += c;
        }
        cout << "Normal text: " << text << endl;
    }

    void writeTofile(string &filename) {
        ofstream of(filename);
        if(of.is_open()) {
            of << e_text;
            of.close();
            cout << "Encrypted text inserted in the file" << endl;
        }
        else {
            cout << "Unable to open file." << endl;
        }
    }

    void readfile(string &filename) {
        ifstream inf(filename);
        if(inf.is_open()){
            getline(inf,e_text);
            inf.close();
        } else {
            cout << "Unable to open file." << endl;
        }
    }

    void decrypt() {
        d_text = "";
        for (int i = 0; i < e_text.length(); ++i) {
            char c = e_text[i];
            c -= (i+1);
            d_text += c;
        }
        cout<<"Decrypted text from the file" << endl;
    }

};
 int main () {
    Encryptor e;
    string filename = "text.txt";

    e.input();
    e.encrypt();
    e.writeTofile(filename);
    e.readfile(filename);
    e.decrypt();

    return 0;
 }