#include <iostream>

using namespace std;

class Engine {
private:
    bool isRunning;

public:
    Engine() : isRunning(false) {}

    void start() {
        if (!isRunning) {
            isRunning = true;
            cout << "Engine started" << endl;
        } else {
            cout << "Engine is already running!" << endl;
        }
    }

    void stop() {
        if (isRunning) {
            isRunning = false;
            cout << "Engine stopped" << endl;
        } else {
            cout << "Engine is already stopped!" << endl;
        }
    }

    bool getEngineStatus() {
        return isRunning;
    }
};

class Car {
private:
    Engine engine;

public:
    void startCar() {
        engine.start();
    }

    void stopCar() {
        engine.stop();
    }
};

int main() {
    Car myCar;
    int choice;
    bool running = true;

    while (running) {
        cout << "\nCar Control Menu:" << endl;
        cout << "1. Start Car" << endl;
        cout << "2. Stop Car" << endl;
        cout << "3. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                myCar.startCar();
                break;
            case 2:
                myCar.stopCar();
                break;
            case 3:
                running = false;
                cout << "Exiting the program..." << endl;
                break;
            default:
                cout << "Invalid choice!" << endl;
                break;
        }
    }

    return 0;
}
