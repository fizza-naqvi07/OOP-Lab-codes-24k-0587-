#include <iostream>
using namespace std;

class User
{
public:
    string name;
    int age;
};

int main()
{
    User u;
    u.name = "Teo";
    u.age = 24;

    cout << " My name is " << u.name << " and I'm " << u.age << " years old" << endl;
    return 0;
}
