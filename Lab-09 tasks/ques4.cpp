#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Passenger;

class Flight
{
private:
    string number;
    string from;
    string to;
    int capacity;
    vector<pair<int, string>> seatList;

    int findPassenger(int pid)
    {
        for (int i = 0; i < seatList.size(); i++)
        {
            if (seatList[i].first == pid)
                return i;
        }
        return -1;
    }

public:
    Flight(string n, string f, string t, int c) : number(n), from(f), to(t), capacity(c) {}

    bool bookSeat(int pid, string name)
    {
        if (seatList.size() >= capacity || findPassenger(pid) != -1)
            return false;
        seatList.push_back({pid, name});
        return true;
    }

    bool cancelSeat(int pid)
    {
        int idx = findPassenger(pid);
        if (idx == -1)
            return false;
        seatList.erase(seatList.begin() + idx);
        return true;
    }

    bool upgradeSeat(int pid, string newName)
    {
        int idx = findPassenger(pid);
        if (idx == -1)
            return false;
        seatList[idx].second = newName + " (Upgraded)";
        return true;
    }

    void printStatus()
    {
        cout << "Flight " << number << " " << from << " -> " << to << endl;
        cout << "Booked: " << seatList.size() << "/" << capacity << endl;
        for (auto &p : seatList)
        {
            cout << "Passenger ID " << p.first << ": " << p.second << endl;
        }
        cout << endl;
    }

    friend class Passenger;
};

class Passenger
{
private:
    int id;
    string name;

public:
    Passenger(int i, string n) : id(i), name(n) {}

    void requestBooking(Flight &f)
    {
        if (f.bookSeat(id, name))
            cout << name << " booked successfully.\n";
        else
            cout << name << " failed to book.\n";
    }

    void requestCancellation(Flight &f)
    {
        if (f.cancelSeat(id))
            cout << name << " cancelled successfully.\n";
        else
            cout << name << " failed to cancel.\n";
    }

    void requestUpgrade(Flight &f)
    {
        if (f.upgradeSeat(id, name))
            cout << name << " upgraded successfully.\n";
        else
            cout << name << " failed to upgrade.\n";
    }
};

int main()
{
    Flight f1("PK103", "Lahore", "Karachi", 2);
    Flight f2("PK207", "Islamabad", "Dubai", 1);

    Passenger p1(1, "Ali");
    Passenger p2(2, "Sara");
    Passenger p3(3, "Zain");

    p1.requestBooking(f1);
    p2.requestBooking(f1);
    p3.requestBooking(f1);

    p2.requestUpgrade(f1);
    p1.requestCancellation(f1);
    p3.requestBooking(f1);

    p1.requestBooking(f2);
    p2.requestBooking(f2);

    f1.printStatus();
    f2.printStatus();

    return 0;
}
