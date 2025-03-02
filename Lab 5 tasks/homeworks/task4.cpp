#include <iostream>

using namespace std;

class Blend {
public:
    void selectFruits() {
        int numFruits;
        cout << "How many fruits would you like to blend? ";
        cin >> numFruits;
        cin.ignore();
        
        string fruit;
        for (int i = 0; i < numFruits; ++i) {
            cout << "Enter fruit " << i + 1 << ": ";
            getline(cin, fruit);
            cout << fruit << " ";
        }
        cout << "\n";
    }

    void blendFruits() {
        selectFruits();
        cout << "Blending fruits..." << endl;
        for (int i = 0; i < 5; ++i) {
            for (volatile int j = 0; j < 100000000; ++j);
        }
    }
};

class Grind {
public:
    void selectFruits() {
        int numFruits;
        cout << "How many fruits would you like to grind? ";
        cin >> numFruits;
        cin.ignore();
        
        string fruit;
        for (int i = 0; i < numFruits; ++i) {
            cout << "Enter fruit " << i + 1 << ": ";
            getline(cin, fruit);
            cout << fruit << " ";
        }
        cout << "\n";
    }

    void grindFruits() {
        selectFruits();
        cout << "Grinding fruits..." << endl;
        for (int i = 0; i < 5; ++i) {
            for (volatile int j = 0; j < 100000000; ++j);
        }
    }
};

class JuiceMaker {
private:
    Blend blend;
    Grind grind;

public:
    void blendJuice() {
        blend.blendFruits();
        cout << "Juice blended!" << endl;
    }

    void grindJuice() {
        grind.grindFruits();
        cout << "Juice ground!" << endl;
    }
};

int main() {
    JuiceMaker juiceMaker;
    string action;

    cout << "Enter action (blend/grind): ";
    getline(cin, action);

    if (action == "blend") {
        juiceMaker.blendJuice();
    } else if (action == "grind") {
        juiceMaker.grindJuice();
    } else {
        cout << "Invalid action!" << endl;
    }

    return 0;
}

