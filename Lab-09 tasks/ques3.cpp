#include <iostream>
#include <string>
#include <vector>
using namespace std;

class PatientRecord
{
private:
    string name;
    int id;
    string dob;
    vector<string> history;
    vector<string> treatments;
    vector<string> billing;

public:
    PatientRecord(string n, int i, string d) : name(n), id(i), dob(d) {}

    string getPublicData()
    {
        return "Name: " + name + ", ID: " + to_string(id);
    }

    string getMedicalData()
    {
        return "Name: " + name + ", History Count: " + to_string(history.size()) + ", Treatments Count: " + to_string(treatments.size());
    }

    void updateMedicalHistory(string note)
    {
        history.push_back(note);
    }

    void addTreatment(string treatment)
    {
        treatments.push_back(treatment);
    }

    void addBillingDetails(string entry)
    {
        billing.push_back(entry);
    }

    string getBillingSummary()
    {
        return "Billing Entries: " + to_string(billing.size());
    }

    friend class Doctor;
    friend class Billing;
};

class Doctor
{
public:
    void writeDiagnosis(PatientRecord &p, string note)
    {
        p.updateMedicalHistory(note);
    }

    void prescribeTreatment(PatientRecord &p, string treatment)
    {
        p.addTreatment(treatment);
    }

    void viewMedicalInfo(PatientRecord &p)
    {
        cout << p.getMedicalData() << endl;
    }
};

class Billing
{
public:
    void addCharge(PatientRecord &p, string item)
    {
        p.addBillingDetails(item);
    }

    void viewBilling(PatientRecord &p)
    {
        cout << p.getBillingSummary() << endl;
    }
};

class Receptionist
{
public:
    void tryAccessMedicalData(PatientRecord &p)
    {
        cout << p.getPublicData() << endl;
    }
};

int main()
{
    PatientRecord p("Naheel raza", 101, "1999-10-23");

    Doctor doc;
    doc.writeDiagnosis(p, "Diabetes Type 2");
    doc.prescribeTreatment(p, "Insulin daily");
    doc.viewMedicalInfo(p);

    Billing bill;
    bill.addCharge(p, "Consultation - 1000 PKR");
    bill.viewBilling(p);

    Receptionist rec;
    rec.tryAccessMedicalData(p);

    return 0;
}
