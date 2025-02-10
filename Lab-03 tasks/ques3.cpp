#include <iostream>
#include <cstdlib>
using namespace std;

class Glass
{
public:
    int LiqLevel;

    Glass()
    {
        LiqLevel = 200;
    }

    void Drink(int ml)
    {
        if (ml > 0 && ml <= LiqLevel)
        {
            LiqLevel -= ml;
            cout << "Drank: " << ml << "ml, Remaining: " << LiqLevel << "ml" << endl;

            if (LiqLevel < 100)
            {
                Refill();
            }
        }
    }

    void Refill()
    {
        LiqLevel = 200;
        cout << "Glass has been refilled to 200 ml!" << endl;
    }
};

int main(int argc, char *argv[])
{
    Glass yourGlass;

    for (int i = 1; i < argc; i++)
    {
        int ml = atoi(argv[i]);

        if (ml <= 0)
            break;

        yourGlass.Drink(ml);
    }

    return 0;
}
