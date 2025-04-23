#include <iostream>
#include <string>
using namespace std;

class Student {
protected:
    string name;
    int id;

public:
    Student(string n, int i) : name(n), id(i) {}

    virtual double getTuition(string status, int creditHours) = 0;
};

class GraduateStudent : public Student {
private:
    string researchTopic;

public:
    GraduateStudent(string n, int i) : Student(n, i) {}

    void setResearchTopic(string topic) {
        researchTopic = topic;
    }

    string getResearchTopic() {
        return researchTopic;
    }

    double getTuition(string status, int creditHours) override {
        if (status == "undergraduate")
            return creditHours * 200;
        else if (status == "graduate")
            return creditHours * 300;
        else if (status == "doctoral")
            return creditHours * 400;
        else
            return 0;
    }

    void display() {
        cout << "Name: " << name << endl;
        cout << "ID: " << id << endl;
        cout << "Research Topic: " << researchTopic << endl;
    }
};

int main() {
    GraduateStudent gs("Arham", 125);
    gs.setResearchTopic("Artificial Intelligence");

    gs.display();

    string status = "graduate";
    int credits = 9;

    double tuition = gs.getTuition(status, credits);

    cout << "Tuition for " << status << " student taking " << credits << " credit hours: $" << tuition << endl;

    return 0;
}
